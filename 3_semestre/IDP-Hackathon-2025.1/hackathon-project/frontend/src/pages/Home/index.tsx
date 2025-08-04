import { useState, useEffect } from 'react'
import styled from 'styled-components'
import { FiUserPlus, FiSearch, FiEdit2, FiTrash2, FiClock } from 'react-icons/fi'
import { useNavigate } from 'react-router-dom'
import { AddClientModal } from '../../components/AddClientModal'
import { EditClientModal } from '../../components/EditClientModal'
import { ClientHistoryModal } from '../../components/ClientHistoryModal'
import { ToastContainer, toast } from 'react-toastify'
import 'react-toastify/dist/ReactToastify.css'

interface Client {
  id: number
  name: string
  age: number
  lastSession: string
  phone?: string
  email?: string
}

interface Session {
  id: number
  date: string
  time: string
  notes: string
}

const Container = styled.div`
  min-height: 100vh;
  background: ${({ theme }) => theme.colors.background};
  padding: ${({ theme }) => theme.spacing.xl};
`

const Header = styled.header`
  display: grid;
  grid-template-columns: 180px 1fr 220px;
  align-items: center;
  margin-bottom: ${({ theme }) => theme.spacing.xl};
  gap: ${({ theme }) => theme.spacing.md};
`

const ThemeToggle = styled.button`
  justify-self: start;
  padding: 0.5rem 1rem;
  border-radius: 20px;
  border: none;
  background: ${({ theme }) => theme.colors.primary};
  color: #fff;
  font-weight: bold;
  cursor: pointer;
  box-shadow: 0 2px 8px rgba(0,0,0,0.10);
`

const Title = styled.h1`
  color: ${({ theme }) => theme.colors.text};
  font-size: ${({ theme }) => theme.fonts.sizes.xxlarge};
  text-align: center;
  margin: 0;
`

const AddButton = styled.button`
  justify-self: end;
  background: ${({ theme }) => theme.colors.primary};
  color: ${({ theme }) => theme.colors.white};
  padding: ${({ theme }) => theme.spacing.md} ${({ theme }) => theme.spacing.lg};
  border-radius: ${({ theme }) => theme.borderRadius.md};
  display: flex;
  align-items: center;
  gap: ${({ theme }) => theme.spacing.sm};
  font-weight: ${({ theme }) => theme.fonts.weights.semibold};
  transition: all 0.2s;

  &:hover {
    background: ${({ theme }) => theme.colors.secondary};
    transform: translateY(-1px);
  }
`

const SearchContainer = styled.div`
  position: relative;
  margin-bottom: ${({ theme }) => theme.spacing.xl};
`

const SearchInput = styled.input`
  width: 100%;
  padding: ${({ theme }) => theme.spacing.md};
  padding-left: ${({ theme }) => theme.spacing.xxl};
  border: 2px solid ${({ theme }) => theme.colors.gray[200]};
  border-radius: ${({ theme }) => theme.borderRadius.md};
  font-size: ${({ theme }) => theme.fonts.sizes.medium};
  transition: all 0.2s;

  &:focus {
    outline: none;
    border-color: ${({ theme }) => theme.colors.primary};
    box-shadow: 0 0 0 3px ${({ theme }) => theme.colors.gray[100]};
  }
`

const SearchIcon = styled.div`
  position: absolute;
  left: ${({ theme }) => theme.spacing.md};
  top: 50%;
  transform: translateY(-50%);
  color: ${({ theme }) => theme.colors.gray[400]};
  font-size: ${({ theme }) => theme.fonts.sizes.large};
`

const ClientsList = styled.div`
  background: ${({ theme }) => theme.colors.white};
  border-radius: ${({ theme }) => theme.borderRadius.lg};
  box-shadow: ${({ theme }) => theme.shadows.md};
  overflow: hidden;
`

const Avatar = styled.div`
  width: 48px;
  height: 48px;
  border-radius: 50%;
  background: ${({ theme }) => theme.colors.primary};
  color: #fff;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 1.5rem;
  font-weight: bold;
  margin-right: ${({ theme }) => theme.spacing.lg};
  box-shadow: 0 2px 8px rgba(0,0,0,0.08);
`

const ClientItem = styled.div`
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: ${({ theme }) => theme.spacing.lg};
  border-bottom: 1px solid ${({ theme }) => theme.colors.gray[200]};
  transition: background-color 0.2s, box-shadow 0.2s;
  background: ${({ theme }) => theme.colors.white};
  box-shadow: 0 2px 8px rgba(0,0,0,0.04);
  border-radius: ${({ theme }) => theme.borderRadius.md};
  margin: 12px 0;

  &:last-child {
    border-bottom: none;
  }

  &:hover {
    background: ${({ theme }) => theme.colors.gray[100]};
    box-shadow: 0 4px 16px rgba(0,0,0,0.10);
  }
`

const ClientInfo = styled.div`
  display: flex;
  align-items: center;
  gap: ${({ theme }) => theme.spacing.md};
`

const ClientText = styled.div`
  display: flex;
  flex-direction: column;
`;

const ClientName = styled.span`
  font-weight: ${({ theme }) => theme.fonts.weights.semibold};
  color: ${({ theme }) => theme.colors.text};
  cursor: pointer;
  transition: color 0.2s;

  &:hover {
    color: ${({ theme }) => theme.colors.primary};
  }
`

const ClientDetails = styled.span`
  color: ${({ theme }) => theme.colors.gray[600]};
  font-size: ${({ theme }) => theme.fonts.sizes.small};
`

const ActionButtons = styled.div`
  display: flex;
  gap: ${({ theme }) => theme.spacing.sm};
`

const ActionButton = styled.button`
  background: none;
  border: none;
  color: ${({ theme }) => theme.colors.gray[500]};
  padding: ${({ theme }) => theme.spacing.sm};
  border-radius: ${({ theme }) => theme.borderRadius.sm};
  transition: all 0.2s;

  &:hover {
    color: ${({ theme }) => theme.colors.primary};
    background: ${({ theme }) => theme.colors.gray[100]};
  }

  &.delete:hover {
    color: ${({ theme }) => theme.colors.error};
  }
`

const HistoryButton = styled(ActionButton)`
  &.history:hover {
    color: ${({ theme }) => theme.colors.secondary};
  }
`

export function Home({ showThemeToggle, isDark, toggleTheme }) {
  const navigate = useNavigate();
  const [clients, setClients] = useState<Client[]>(() => {
    const stored = localStorage.getItem('clients');
    return stored ? JSON.parse(stored) : [
      { id: 1, name: 'Maria Silva', age: 28, lastSession: '15/03/2024', phone: '(11) 98765-4321', email: 'maria@email.com' },
      { id: 2, name: 'João Santos', age: 35, lastSession: '14/03/2024', phone: '(11) 91234-5678', email: 'joao@email.com' },
      { id: 3, name: 'Ana Oliveira', age: 42, lastSession: '13/03/2024', phone: '(11) 99876-5432', email: 'ana@email.com' },
    ];
  });
  const [sessions, setSessions] = useState<Record<number, Session[]>>(() => {
    const stored = localStorage.getItem('sessions');
    return stored ? JSON.parse(stored) : {
      1: [
        { id: 1, date: '15/03/2024', time: '14:00', notes: 'Paciente relatou melhora significativa nos sintomas de ansiedade.' },
        { id: 2, date: '08/03/2024', time: '14:00', notes: 'Sessão focada em técnicas de respiração e mindfulness.' },
      ],
      2: [
        { id: 1, date: '14/03/2024', time: '15:30', notes: 'Discussão sobre progressos no tratamento de depressão.' },
      ],
      3: [
        { id: 1, date: '13/03/2024', time: '16:00', notes: 'Primeira sessão de avaliação.' },
      ],
    };
  });
  // Salvar no localStorage sempre que clients ou sessions mudarem
  useEffect(() => {
    localStorage.setItem('clients', JSON.stringify(clients));
  }, [clients]);
  useEffect(() => {
    localStorage.setItem('sessions', JSON.stringify(sessions));
  }, [sessions]);

  const [isAddModalOpen, setIsAddModalOpen] = useState(false)
  const [isEditModalOpen, setIsEditModalOpen] = useState(false)
  const [isHistoryModalOpen, setIsHistoryModalOpen] = useState(false)
  const [selectedClient, setSelectedClient] = useState<Client | null>(null)
  const [searchTerm, setSearchTerm] = useState('')

  const handleAddClient = (newClient: { name: string; age: number; phone: string; email: string }) => {
    const client: Client = {
      id: clients.length + 1,
      name: newClient.name,
      age: newClient.age,
      lastSession: new Date().toLocaleDateString('pt-BR'),
      phone: newClient.phone,
      email: newClient.email
    }
    setClients([...clients, client])
    setSessions({ ...sessions, [client.id]: [] })
    setIsAddModalOpen(false)
    toast.success('Paciente adicionado com sucesso!');
  }

  const handleEditClient = (client: Client) => {
    setSelectedClient(client)
    setIsEditModalOpen(true)
  }

  const handleSaveEdit = (editedClient: { id: number; name: string; age: number; lastSession: string }) => {
    setClients(clients.map(client => 
      client.id === editedClient.id ? { ...client, ...editedClient } : client
    ))
    setIsEditModalOpen(false)
    toast.success('Paciente editado com sucesso!');
  }

  const handleDeleteClient = (id: number) => {
    if (confirm('Tem certeza que deseja remover este paciente?')) {
      setClients(clients.filter(client => client.id !== id))
      const newSessions = { ...sessions }
      delete newSessions[id]
      setSessions(newSessions)
      toast.success('Paciente removido com sucesso!');
    }
  }

  const handleViewHistory = (client: Client) => {
    setSelectedClient(client)
    setIsHistoryModalOpen(true)
  }

  const handleClientClick = (clientName: string) => {
    navigate(`/sessions/${encodeURIComponent(clientName)}`);
  };

  const filteredClients = clients.filter(client =>
    client.name.toLowerCase().includes(searchTerm.toLowerCase())
  )

  return (
    <Container>
      <Header>
        <ThemeToggle onClick={toggleTheme}>
          {isDark ? 'Tema Claro' : 'Tema Escuro'}
        </ThemeToggle>
        <Title>Meus Pacientes</Title>
        <AddButton onClick={() => setIsAddModalOpen(true)}>
          <FiUserPlus />
          Adicionar Paciente
        </AddButton>
      </Header>

      <SearchContainer>
        <SearchIcon>
          <FiSearch />
        </SearchIcon>
        <SearchInput
          type="text"
          placeholder="Buscar pacientes..."
          value={searchTerm}
          onChange={(e) => setSearchTerm(e.target.value)}
        />
      </SearchContainer>

      <ClientsList>
        {clients
          .filter(client =>
            client.name.toLowerCase().includes(searchTerm.toLowerCase())
          )
          .map(client => (
            <ClientItem key={client.id}>
              <ClientInfo>
                <Avatar>{client.name.charAt(0).toUpperCase()}</Avatar>
                <ClientText>
                  <ClientName onClick={() => handleClientClick(client.name)}>
                    {client.name}
                  </ClientName>
                  <ClientDetails>
                    {client.age} anos
                  </ClientDetails>
                  <ClientDetails>
                    Última sessão: {client.lastSession}
                  </ClientDetails>
                </ClientText>
              </ClientInfo>
              <ActionButtons>
                <ActionButton onClick={() => handleEditClient(client)}>
                  <FiEdit2 />
                </ActionButton>
                <ActionButton
                  className="delete"
                  onClick={() => handleDeleteClient(client.id)}
                >
                  <FiTrash2 />
                </ActionButton>
              </ActionButtons>
            </ClientItem>
          ))}
      </ClientsList>

      {isAddModalOpen && (
        <AddClientModal
          isOpen={isAddModalOpen}
          onClose={() => setIsAddModalOpen(false)}
          onAdd={handleAddClient}
        />
      )}

      {isEditModalOpen && selectedClient && (
        <EditClientModal
          isOpen={isEditModalOpen}
          client={selectedClient}
          onClose={() => setIsEditModalOpen(false)}
          onSave={handleSaveEdit}
        />
      )}

      {isHistoryModalOpen && selectedClient && (
        <ClientHistoryModal
          client={selectedClient}
          sessions={sessions[selectedClient.id] || []}
          onClose={() => setIsHistoryModalOpen(false)}
        />
      )}

      <ToastContainer position="top-right" autoClose={3000} />
    </Container>
  )
} 