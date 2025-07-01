const loginScreen  = document.getElementById('login-screen')
const appScreen    = document.getElementById('app-screen')
const loginBtn     = document.getElementById('login-btn')
const userInput    = document.getElementById('login-username')
const loginError   = document.getElementById('login-error')
const currentUser  = document.getElementById('current-user')
const logoutBtn    = document.getElementById('logout-btn')

const searchInput  = document.getElementById('search-input')
const searchBtn    = document.getElementById('search-btn')
const resultDiv    = document.getElementById('search-result')
const resultName   = document.getElementById('search-name')
const addBtn       = document.getElementById('add-btn')

const contactsEl   = document.getElementById('contacts')
const chatHeader   = document.getElementById('chat-header')
const messagesEl   = document.getElementById('messages')
const messageInput = document.getElementById('message-input')
const sendBtn      = document.getElementById('send-btn')

let user = null
let peer = null
let socket = null

function initSocket() {
    socket = io()
    
    socket.on('connect', () => {
        console.log('Conectado ao servidor')
        if (user) {
            socket.emit('join', { username: user })
        }
    })
    
    socket.on('new_message', (message) => {
        console.log('Nova mensagem recebida:', message)
        if (peer && message.chat_id === getChatId(user, peer)) {
            addMessageToChat(message, false)
        }
        loadContacts()
    })
    
    socket.on('message_sent', (message) => {
        console.log('Mensagem enviada confirmada:', message)
        if (peer && message.chat_id === getChatId(user, peer)) {
            addMessageToChat(message, true)
        }
    })
    
    socket.on('message_error', (data) => {
        console.error('Erro ao enviar mensagem:', data.error)
        alert('Erro ao enviar mensagem. Tente novamente.')
    })
    
    socket.on('disconnect', () => {
        console.log('Desconectado do servidor')
    })
}

function getChatId(user1, user2) {
    return [user1, user2].sort().join('_')
}

function formatTime(timestamp) {
    const date = new Date(timestamp)
    return date.toLocaleTimeString('pt-BR', { 
        hour: '2-digit', 
        minute: '2-digit' 
    })
}

loginBtn.onclick = async () => {
    const username = userInput.value.trim()
    if (!username) {
        showLoginError('Digite um username')
        return
    }
    
    try {
        const response = await fetch('/login', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ username })
        })
        
        if (response.ok) {
            const userData = await response.json()
            user = userData.username
            currentUser.textContent = `${userData.name} (${userData.username})`
            
            loginScreen.classList.add('hidden')
            appScreen.classList.remove('hidden')
            hideLoginError()
            
            initSocket()
            loadContacts()
        } else {
            const error = await response.json()
            showLoginError(error.error || 'Erro no login')
        }
    } catch (error) {
        showLoginError('Erro de conexão')
    }
}

logoutBtn.onclick = () => {
    user = null
    peer = null
    if (socket) {
        socket.disconnect()
        socket = null
    }
    
    appScreen.classList.add('hidden')
    loginScreen.classList.remove('hidden')
    userInput.value = ''
    hideLoginError()
    
    contactsEl.innerHTML = ''
    messagesEl.innerHTML = ''
    chatHeader.textContent = ''
    searchInput.value = ''
    resultDiv.classList.add('hidden')
}

function showLoginError(message) {
    loginError.textContent = message
    loginError.classList.remove('hidden')
}

function hideLoginError() {
    loginError.classList.add('hidden')
}

async function loadContacts(){
    if (!user) return
    
    try {
        const response = await fetch(`/chats/${user}`)
        if (response.ok) {
            const chats = await response.json()
            contactsEl.innerHTML = ''
            
            chats.forEach(chatId => {
                const contact = chatId.split('_').find(x => x !== user)
                const div = document.createElement('div')
                div.textContent = contact
                div.className = 'contact'
                div.onclick = () => openChat(contact)
                contactsEl.appendChild(div)
            })
        }
    } catch (error) {
        console.error('Erro ao carregar contatos:', error)
    }
}

searchBtn.onclick = async () => {
    const query = searchInput.value.trim()
    if (!query) return
    
    try {
        const response = await fetch(`/users/${query}`)
        if (response.status === 404) {
            resultDiv.classList.remove('hidden')
            resultName.textContent = 'Usuário não encontrado'
            addBtn.style.display = 'none'
        } else if (response.ok) {
            const userData = await response.json()
            resultDiv.classList.remove('hidden')
            resultName.textContent = userData.name
            addBtn.style.display = 'inline-block'
            resultDiv.dataset.username = userData.username
        }
    } catch (error) {
        console.error('Erro na busca:', error)
    }
}

addBtn.onclick = async () => {
    const contact = resultDiv.dataset.username
    if (!contact) return
    
    try {
        const response = await fetch(`/contacts/${user}`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ contact_username: contact })
        })
        
        if (response.ok) {
            searchInput.value = ''
            resultDiv.classList.add('hidden')
            loadContacts()
        } else {
            const error = await response.json()
            alert(error.error || 'Erro ao adicionar contato')
        }
    } catch (error) {
        console.error('Erro ao adicionar contato:', error)
    }
}

async function openChat(contact){
    peer = contact
    chatHeader.textContent = contact
    
    // Atualizar contatos ativos
    document.querySelectorAll('.contact').forEach(el => el.classList.remove('active'))
    event.target.classList.add('active')
    
    const chatId = getChatId(user, peer)
    try {
        const response = await fetch(`/messages/${chatId}`)
        if (response.ok) {
            const messages = await response.json()
            messagesEl.innerHTML = ''
            messages.forEach(message => {
                const isSent = message.sender === user
                addMessageToChat(message, isSent)
            })
        }
    } catch (error) {
        console.error('Erro ao carregar mensagens:', error)
    }
}

function addMessageToChat(message, isSent) {
    const div = document.createElement('div')
    div.className = `msg ${isSent ? 'sent' : 'received'}`
    
    const textDiv = document.createElement('div')
    textDiv.textContent = message.text
    
    const timeDiv = document.createElement('div')
    timeDiv.className = 'time'
    timeDiv.textContent = formatTime(message.timestamp)
    
    div.appendChild(textDiv)
    div.appendChild(timeDiv)
    messagesEl.appendChild(div)
    
    // Scroll para baixo
    messagesEl.scrollTop = messagesEl.scrollHeight
}

// Enviar mensagem
sendBtn.onclick = async () => {
    if (!peer || !socket) return
    
    const text = messageInput.value.trim()
    if (!text) return
    
    const chatId = getChatId(user, peer)
    const messageData = {
        chat_id: chatId,
        sender: user,
        receiver: peer,
        text: text
    }
    
    // Limpar input imediatamente
    messageInput.value = ''
    
    // Enviar via WebSocket - o servidor vai confirmar e adicionar a mensagem
    socket.emit('send_message', messageData)
}

messageInput.onkeypress = (e) => {
    if (e.key === 'Enter') {
        sendBtn.click()
    }
}

searchInput.onkeypress = (e) => {
    if (e.key === 'Enter') {
        searchBtn.click()
    }
}

userInput.onkeypress = (e) => {
    if (e.key === 'Enter') {
        loginBtn.click()
    }
}
