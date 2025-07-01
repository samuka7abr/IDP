// Nome: Allan Samuel Alves do Monte
// Matrícula: 24101279

import java.io.IOException;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {
    public static void main(String[] args) {
        Path caminhoEntrada = Paths.get("C:\\Users\\Nitro five\\Documents\\Aulas em Java\\challenge 04\\Desafio 04\\compras.txt");
        Path caminhoSaida = Paths.get("C:\\Users\\Nitro five\\Documents\\Aulas em Java\\challenge 04\\Desafio 04\\relatorio.txt");

        ArrayList<String> nomesClientes = new ArrayList<>();
        ArrayList<Double> totaisClientes = new ArrayList<>();

        try {
            List<String> linhas = Files.readAllLines(caminhoEntrada);

            for (String linha : linhas) {
                String[] partes = linha.split(",");

                if (partes.length < 3) continue;

                String nomeCliente = partes[0].trim();
                String valorStr = partes[2].trim();

                try {
                    double valor = Double.parseDouble(valorStr);

                    int indice = nomesClientes.indexOf(nomeCliente);
                    if (indice >= 0) {
                        double novoTotal = totaisClientes.get(indice) + valor;
                        totaisClientes.set(indice, novoTotal);
                    } else {
                        nomesClientes.add(nomeCliente);
                        totaisClientes.add(valor);
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Valor inválido (ignorado): " + valorStr);
                }
            }

            List<String> linhasSaida = new ArrayList<>();
            for (int i = 0; i < nomesClientes.size(); i++) {
                linhasSaida.add(nomesClientes.get(i) + ": " + totaisClientes.get(i));
            }

            Files.write(caminhoSaida, linhasSaida);
            System.out.println("Relatório gerado com sucesso em:\n" + caminhoSaida);

        } catch (IOException e) {
            System.out.println("Erro ao acessar os arquivos: " + e.getMessage());
        }
    }
}
