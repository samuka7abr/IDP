(function () {
    function createOverlay() {
        if (!document.getElementById('block-extension-overlay')) {
            var overlay = document.createElement('div');
            overlay.id = 'block-extension-overlay';

            // Estilo do overlay
            overlay.style.position = 'fixed';
            overlay.style.left = 0;
            overlay.style.top = 0;
            overlay.style.width = '100%';
            overlay.style.height = '100%';
            overlay.style.zIndex = 10000;
            overlay.style.backgroundColor = 'rgba(0, 0, 0, 0.85)';
            overlay.style.color = '#fff';
            overlay.style.display = 'flex';
            overlay.style.flexDirection = 'column';
            overlay.style.justifyContent = 'center';
            overlay.style.alignItems = 'center';
            overlay.style.fontSize = '24px';
            overlay.style.fontFamily = 'Arial, sans-serif';
            
            // Conteúdo do overlay
            overlay.innerHTML = `
                <h1>Este site está bloqueado</h1>
                <p>Foque em suas metas! Este conteúdo não está disponível agora.</p>
            `;

            document.body.appendChild(overlay);
        }
    }

    // Adiciona o overlay ao carregar a página
    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', createOverlay);
    } else {
        createOverlay();
    }
})();
