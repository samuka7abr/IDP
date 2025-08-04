# Boas-vindas ao repositório do projeto de Fabrica de Projetos!

Para realizar o projeto, atente-se a cada passo descrito a seguir e, se tiver qualquer dúvida, nos envie por mensagem! 🚀

Aqui você vai encontrar os detalhes de como estruturar o desenvolvimento do seu projeto a partir deste repositório, utilizando uma branch específica e um _Pull Request_ para colocar seus códigos.

# Orientações

<details>
  <summary><strong>‼️ Antes de começar a desenvolver</strong></summary><br />

  1. Clone o repositório

  - Use o comando: `git clone https://github.com/IdpProjects/FabricaDeProjetos1`.

  - Entre na pasta do repositório que você acabou de clonar:
    - `cd FabricaDeProjetos1/defensoria-publica`
  - Crie e Vá para a branch do seu grupo com o codigo a seguir:
    - `git checkout main-group-XX && git pull`, onde `XX` é o nome do seu grupo. Exemplos: `main-group-pesquisa1`, `main-group-pesquisa2`.

  2. Instale as dependências e inicialize o projeto

  - Instale as dependências:
    - `npm install`
  - Inicialize o projeto:
    - `npm start` (uma nova página deve abrir no seu navegador com um texto simples)
  
  3. Faça alterações separadas por novas branchs criadas a partir da branch `main-group-XX`, criando uma nova branch para cada demanda

  - Verifique que você está na branch `main-group-XX`
    - Exemplo: `git branch`
  - Se não estiver, mude para a branch `main-group-XX`
    - Exemplo: `git checkout main-group-XX && git pull`
  - Agora, crie uma branch para a demanda que você vai desenvolver do seu projeto
    - Você deve criar uma branch com uma breve descrição da demanda a ser desenvolvida
    - Exemplo: `git checkout -b main-group-XX-cria-campo-de-input`

  4. Adicione as mudanças ao _stage_ do Git e faça um `commit`

  - Verifique que as mudanças ainda não estão no _stage_
    - Exemplo: `git status` (devem aparecer listadas as novas alterações em vermelho)
  - Adicione o novo arquivo ao _stage_ do Git
    - Exemplo:
      - `git add .` (adicionando todas as mudanças - _que estavam em vermelho_ - ao stage do Git)
      - `git status` (devem aparecer listadas as novas alterações em verde)
  - Faça o `commit`
    - Exemplo:
      - `git commit -m 'cria componente de input'` (fazendo o primeiro commit)
      - `git status` (deve aparecer uma mensagem tipo _nothing to commit_ )

  5. Adicione a sua branch com o novo `commit` ao repositório remoto

  - Usando o exemplo anterior: `git push -u origin main-group-XX-cria-campo-de-input`

  6. Crie um novo `Pull Request` _(PR)_

  - Vá até a página de _Pull Requests_ do [repositório no GitHub](https://github.com/IdpProjects/FabricaDeProjetos1/pulls)
  - Clique no botão verde _"New pull request"_
  - Clique na caixa de seleção _"Compare"_ e escolha a sua branch **com atenção**
  - Coloque um título para a sua _Pull Request_
    - Exemplo: _"[GRUPO XX] Cria tela de busca"_
  - Clique no botão verde _"Create pull request"_
  - Adicione uma descrição para o _Pull Request_ e clique no botão verde _"Create pull request"_
  - **Não se preocupe em preencher mais nada por enquanto!**
  - Volte até a [página de _Pull Requests_ do repositório](https://github.com/IdpProjects/FabricaDeProjetos1/pulls) e confira que o seu _Pull Request_ está criado

  7. Assim que aprovado por pelo menos duas pessoas do grupo de Revisores acesse **SEU** _Pull Request_ e clique no botão _"Merge pull request"_

</details>

<details>
  <summary><strong>⌨️ Durante o desenvolvimento</strong></summary><br />

  - Faça `commits` das alterações que você fizer no código regularmente

  - Lembre-se de sempre após um (ou alguns) `commits` atualizar o repositório remoto

  - Os comandos que você utilizará com mais frequência são:
    1. `git status` _(para verificar o que está em vermelho - fora do stage - e o que está em verde - no stage)_
    2. `git add` _(para adicionar arquivos ao stage do Git)_
    3. `git commit` _(para criar um commit com os arquivos que estão no stage do Git)_
    4. `git push -u origin nome-da-branch` _(para enviar o commit para o repositório remoto na primeira vez que fizer o `push` de uma nova branch)_
    5. `git push` _(para enviar o commit para o repositório remoto após o passo anterior)_

</details>

<details>
  <summary><strong>🤝 Depois de terminar o desenvolvimento (opcional)</strong></summary><br />

  Para sinalizar que o seu projeto está pronto para o _"Code Review"_, faça o seguinte:

  - Vá até a página **DO SEU** _Pull Request_, adicione a label de _"code-review"_ e marque seus colegas:

    - No menu à direita, clique no _link_ **"Labels"** e escolha a _label_ **code-review**;

    - No menu à direita, clique no _link_ **"Assignees"** e escolha **o seu usuário**;

  Caso tenha alguma dúvida, [aqui tem um video explicativo](https://vimeo.com/362189205).

</details>


<details>
  <summary><strong>💻 Protótipo do projeto no Figma</strong></summary><br />

Além da qualidade do código e do atendimento aos requisitos, um bom layout é um dos aspectos responsáveis por melhorar a usabilidade de uma aplicação e turbinar seu portfólio!

Você pode estar se perguntando: *"Como deixo meu projeto com um layout mais atrativo?"* 🤔

Para isso, disponibilizamos esse [protótipo do Figma](xxxx) para lhe ajudar !

⚠️ A estilização de sua aplicação será avaliada nesse projeto, portanto esse protótipo é apenas uma **sugestão** e seu uso é **opcional**.

</details>

<br/>

# Requisitos

:warning: **PULL REQUESTS COM PROBLEMAS DE FUNCIONAMENTO SERÃO AVALIADOS.** :warning:

## Tela de início

>Obs: É necessário que a página de Login tenha o caminho `src/components/Carrousel.js`

## 1. Complete a função de componente que renderiza para o usuario as personas criadas pelo time de pesquisa

**PRIORIDADE**

Criar o componente de carrosel, que através do array de objetos criado no arquivo persona.js, no caminho `src/Utils/mocks/persona.js`.
  
:bulb: Se preciso, pesquisar como ultilizar a função .map() para este caso!

:warning: **Lembre-se das observações técnicas descritas acima.**

<details>
  <summary><strong> Observações técnicas:</strong></summary>

  * O componente deve renderizar as personas em formato de carrosel.
  * Independente do numero de personas que estiverem no array de objetos, construir a logica para que apenas os 5 primeiros sejam visiveis, e que o restante será visto apenas se o usuario clicar em ver mais.
  * O botão "Ver mais" deve ser invisivel ate que o usuario chegue no ultimo painel do carrosel.
  * Os botões ">" e "<" devem levar o usuario para a proxima persona ou anterior`
</details>
<br /><details>
  <summary><strong>O que será verificado</strong></summary>

  * Será validado se o componente é renderizado corretamente.
  * Será validado se as 5 personas são exibidas.
  * Será validado se o botão ver mais aparece quando o usuario chega no ultimo carrosel.
  * Será validado que ao clicar no botão ver mais, o usuario possa ver por completo todos os items do carrosel. 
  * Será validado que ao clicar no botão ">" ou "<" o usuario pode visualizar novas personas.

</details>

---

## 2. Implemente a função que recebe as localidades

  **PRIORIDADE 1**
  
  A função deve comparar a localidade do usuario, com a localidade da carreta obtida por meio de API da defensoria.

<details>
  <summary><strong> Observações técnicas:</strong></summary>

  * Ao obter a localização do usuario, uma requisição para a API da defensoria deve ser feita para obter o a localidade da carreta e comparar se estão em localidades iguais.

  * Exemplo : Gama === Gama, Taguatinga != Asa Sul
</details>
<br /><details>
  <summary><strong>O que será verificado</strong></summary>

  * Será validado que...
</details>

---

## 3. Implementando a página Home

>Obs: A página inicial tem o caminho `src/pages/Home.js`

  **PRIORIDADE 1**
  
  A tela inicial deve conter um Header (Com informações das redes sociais), um carrosel (Com as personas criadas pelos grupos de pesquisa e design) e um painel de exposição de noticias da defensoria.
 
<details>
  <summary><strong> Observações técnicas:</strong></summary>

  * será...
</details>
<br /><details>
  <summary><strong>O que será verificado</strong></summary>

  * será...
</details>

---

## 4. Desenvolvemos a estrutura do projeto e criamos funções base para auxiliar no entendimento de como funciona a página

> :bulb: Obs: É importante entender os conceitos de programação modular em React, recomendo que todos assistam a videos do tema e se interem nisso.

> :hand: Obs: Vale ressaltar que dentro de toda função existem comentários e instruções em niveis mais detalhados do que aquele componente deve fazer.

  **PRIORIDADE 1**
  
  Compreender como cada função é independente da outra e como adaptar os codigos de forma padrão

<details>
  <summary><strong> Observações técnicas:</strong></summary>

  * Ultilizaremos os padrões de código limpo.
</details>
<br />

---

