import React from 'react';
import { InstagramLogo, XLogo, FacebookLogo } from "@phosphor-icons/react";

// Os css`s de pagina estarão na pasta Style/Pages/NomeDaPagina.css
// Para importar basta digitar import "./Style/Pages/NomeDaPagina.css"

function Socials() {
  return (
    <footer style={{ display: "flex", justifyContent: "center", alignItems: "center", padding: "10px", background: "#f5f5f5" }}>
      <a href="https://www.instagram.com/defensoriadf/" target="_blank" rel="noopener noreferrer" style={{ margin: "0 10px" }}>
        <InstagramLogo size={52} color="#5e5a5a" />
      </a>
      <a href="https://x.com/defensoriadf" target="_blank" rel="noopener noreferrer" style={{ margin: "0 10px" }}>
        <XLogo size={52} color="#5e5a5a" />
      </a>
      <a href="https://www.facebook.com/defensoriadf/?locale=pt_BR" target="_blank" rel="noopener noreferrer" style={{ margin: "0 10px" }}>
        <FacebookLogo size={52} color="#5e5a5a" />
      </a>
    </footer>
  );
}

export default Socials;
