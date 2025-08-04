import sandra from "../../Style/Icons/sandra.png"
import lucas from "../../Style/Icons/lucas.png"
import julia from "../../Style/Icons/julia.png"
import anderson from "../../Style/Icons/anderson.png"
import rodrigo from "../../Style/Icons/rodrigo.png"



export const Orientations = [
    {
        name: "Sandra",
        srcImage: sandra,
        documents: {
            Identificação: "RG e CPF",
            Residência: "Comprovante Atualizado",
            Filhos: "Certidões de Nascimento dos filhos",
            Habitação: "Cópia da ordem de despejo e comprovante de renda (ou ausência de renda).",
            Educação: "Provas de tentativa de matrícula na creche (e-mails, protocolos, etc.).",
            Discriminação: "Relatos documentados ou testemunhas de casos de assédio ou discriminação."
        },
        options: `Opções de Atendimento (Online e Presencial)

Online: Sandra pode acessar o site da Defensoria Pública do Distrito Federal para informações preliminares e agendamento: Defensoria Pública do DF.

Presencial: Caso prefira ou precise de atendimento presencial, deve comparecer a uma das unidades mencionadas acima, preferencialmente com agendamento prévio.
`,
        adress: [`Endereço (D.H): Praça Municipal, Lote 01, Palácio da Justiça, TJDFT, Bloco B, Anexo 2, Ala A, 4º andar — Brasília`, `Um dos Núcleos de Assistência Jurídica para o auxílio na questão de Defensoria dos direitos habitacionais: Avenida das Paineiras, EQ 3/5, Edifício Jardim Imperial, Bloco B, 2º andar, salas 209 a 218 — Jardim Botânico `],
    },
    {
        name: "Lucas",
        srcImage: lucas,
        documents: "Fui preso(a) injustamente e não posso pagar um advogado para me defender das acusações : como posso resolver?"
    },
    {
        name: "Júlia",
        srcImage: julia,
        documents: "Preciso de adaptações de acessibilidade em minha escola/trabalho, mas a instituição não oferece o suporte necessário para minha participação : como posso resolver?"
    },
    {
        name: "Anderson",
        srcImage: anderson,
        documents: "Sofri problemas de saúde devido às condições insalubres no trabalho, e agora a empresa e o sistema de seguridade social se recusam a me compensar ou fornecer apoio : como posso resolver?"
    },
    {
        name: "Rodrigo",
        srcImage: rodrigo,
        documents: "Sofri um acidente no trabalho e a empresa ou plataforma não quer assumir a responsabilidade, deixando-me sem assistência financeira ou médica : como posso resolver?"
    },
]