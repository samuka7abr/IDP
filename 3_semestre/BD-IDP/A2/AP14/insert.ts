import { MongoClient } from "mongodb";

interface Cliente { nome: string; cpf: string; telefone: string; plano: string }
interface Veiculo { placa: string; tipo: string; cor: string; proprietario: { cpf: string; nome: string } }
interface Estacionamento { nome: string; localizacao: string; capacidade: number }
interface Registro { entrada: Date; saida: Date; vaga: number; valor: number; cliente: { cpf: string; nome: string }; estacionamento: { nome: string; localizacao: string } }

async function main() {
  const client = new MongoClient("mongodb://localhost:27017");
  await client.connect();
  const db = client.db("estacionamento");

  const clientes: Cliente[] = [
    { nome: "Ana Silva", cpf: "111.111.111-11", telefone: "(61)90000-0001", plano: "diária" },
    { nome: "Bruno Souza", cpf: "222.222.222-22", telefone: "(61)90000-0002", plano: "mensalista" }
  ];

  const veiculos: Veiculo[] = [
    { placa: "ABC-1001", tipo: "carro", cor: "branco", proprietario: { cpf: "111.111.111-11", nome: "Ana Silva" } },
    { placa: "DEF-2002", tipo: "moto", cor: "preto", proprietario: { cpf: "222.222.222-22", nome: "Bruno Souza" } }
  ];

  const estacionamentos: Estacionamento[] = [
    { nome: "Central Park", localizacao: "Águas Claras", capacidade: 50 },
    { nome: "Setor Sul", localizacao: "Brasília", capacidade: 75 }
  ];

  const registros: Registro[] = [
    {
      entrada: new Date("2025-05-01T08:00:00Z"),
      saida: new Date("2025-05-01T12:00:00Z"),
      vaga: 12,
      valor: 15.0,
      cliente: { cpf: "111.111.111-11", nome: "Ana Silva" },
      estacionamento: { nome: "Central Park", localizacao: "Águas Claras" }
    },
    {
      entrada: new Date("2025-05-02T09:30:00Z"),
      saida: new Date("2025-05-02T11:00:00Z"),
      vaga: 5,
      valor: 10.0,
      cliente: { cpf: "222.222.222-22", nome: "Bruno Souza" },
      estacionamento: { nome: "Setor Sul", localizacao: "Brasília" }
    }
  ];

  const resultClientes = await db.collection<Cliente>("clientes").insertMany(clientes);
  console.log("Clientes inseridos:", resultClientes.insertedCount, resultClientes.insertedIds);

  const resultVeiculos = await db.collection<Veiculo>("veiculos").insertMany(veiculos);
  console.log("Veículos inseridos:", resultVeiculos.insertedCount, resultVeiculos.insertedIds);

  const resultEst = await db.collection<Estacionamento>("estacionamentos").insertMany(estacionamentos);
  console.log("Estacionamentos inseridos:", resultEst.insertedCount, resultEst.insertedIds);

  const resultRegs = await db.collection<Registro>("registros").insertMany(registros);
  console.log("Registros inseridos:", resultRegs.insertedCount, resultRegs.insertedIds);

  await client.close();
}

main();
