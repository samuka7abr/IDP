# Bet Blocker Extension

Uma extensão de navegador que identifica e bloqueia sites de apostas ilegais, emitindo um pop-up de aviso sempre que o usuário tenta acessá-los. O projeto utiliza uma integração com o banco de dados do governo para verificar a legalidade dos sites.

## 📋 Funcionalidades

- **Identificação de sites ilegais**: Verifica URLs acessadas com base em uma lista oficial fornecida pelo banco de dados do governo.
- **Bloqueio proativo**: Exibe um pop-up de aviso quando o site é classificado como ilegal.
- **Integração com banco de dados**: Consulta em tempo real as informações para garantir a precisão da análise.

## 🚀 Como funciona

1. O usuário navega normalmente.
2. Quando uma URL é acessada, a extensão consulta o banco de dados do governo para verificar a classificação do site.
3. Caso o site seja identificado como ilegal, o acesso é bloqueado e um pop-up é exibido para o usuário.

## 🛠️ Tecnologias Utilizadas

- **HTML/CSS/JavaScript**: Para o desenvolvimento da interface da extensão.
- **Banco de Dados**: Integração com um banco de dados governamental para consulta em tempo real.
- **APIs**: Comunicação com o banco de dados por meio de APIs REST.

## 💻 Instalação

1. Clone o repositório:
   ```bash
   git clone https://github.com/samuka7abr/Block-Bet_Extension.git
2. Abra o navegador e acesse as configurações de extensões:
    - No Chrome: chrome://extensions/
    - No Firefox: about:addons
3. Ative o modo de desenvolvedor e carregue a pasta do projeto como uma extensão não empacotada.
