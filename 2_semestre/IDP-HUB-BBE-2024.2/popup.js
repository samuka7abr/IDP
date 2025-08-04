document.addEventListener("DOMContentLoaded", () => {
    const downloadButton = document.getElementById("download-blocked-sites");
    const addButton = document.getElementById("butao");

    // Inicializa a lista de sites bloqueados
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

    // Função para baixar a lista de sites bloqueados
    downloadButton.addEventListener("click", () => {
        const jsonData = JSON.stringify(blockedSites, null, 2);
        const blob = new Blob([jsonData], { type: 'application/json' });
        const url = URL.createObjectURL(blob);
        const a = document.createElement('a');
        a.href = url;
        a.download = 'blockedSites.json';
        a.click();
        URL.revokeObjectURL(url); // Libera o objeto URL
    });

    // Função para adicionar um site à lista de bloqueio
    addButton.addEventListener("click", () => {
        let newSite = prompt("Digite o site que deseja bloquear (exemplo: example.com):");
        if (newSite) {
            // Remove o protocolo, caso o usuário insira
            newSite = newSite.replace(/^https?:\/\//, "");
            if (!blockedSites.includes(newSite)) {
                blockedSites.push(newSite);
                alert(`Site ${newSite} adicionado à lista de bloqueio.`);
            } else {
                alert("Este site já está na lista de bloqueio.");
            }
        }
    });
});