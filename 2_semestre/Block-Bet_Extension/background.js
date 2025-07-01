// Lista de sites bloqueados 
let blockedSites = [
    "superbet.com", 
    "novibet.com", 
    "parimatch.com", 
    "vbets.com", 
    "sportingbet.com", 
    "bet365.com", 
    "sportsbet.io", 
    "betnacional.com", 
    "rivalo.com"
];


function isSiteBlocked(url) {
    return blockedSites.some((site) => url.includes(site));
}

// Monitora atualizações nas abas
chrome.tabs.onUpdated.addListener((tabId, changeInfo, tab) => {
    if (changeInfo.status === "complete" && isSiteBlocked(tab.url)) {
        // Injetar o script de bloqueio na aba
        chrome.scripting.executeScript({
            target: { tabId: tabId },
            files: ["block.js"]
        });
    }
});

// Função para remover o bloqueio
function removeBlock(tabId) {
    chrome.scripting.executeScript({
        target: { tabId: tabId },
        files: ["unblock.js"]
    });
}