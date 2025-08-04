import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class ArquivoManipulado {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Uso: java RelatorioComprasPorCliente <arquivoEntrada> <arquivoSaida>");
            return;
        }

        Path caminhoEntrada = Path.of(args[0]);
        Path caminhoSaida = Path.of(args[1]);

        List<String> linhas;
        try {
            linhas = Files.readAllLines(caminhoEntrada);
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo de entrada: " + e.getMessage());
            return;
        }

        ArrayList<String> nomesClientes = new ArrayList<>();
        ArrayList<Double> totaisClientes = new ArrayList<>();

        for (String linha : linhas) {
            String[] partes = linha.split(",");

            // Ignora linhas malformadas
            if (partes.length < 3) continue;

            String nomeCliente = partes[0].trim();
            String valorStr = partes[2].trim();

            double valorCompra;
            try {
                valorCompra = Double.parseDouble(valorStr);
            } catch (NumberFormatException e) {
                System.out.println("Valor inválido na linha: " + linha);
                continue;
            }

            int indice = nomesClientes.indexOf(nomeCliente);
            if (indice != -1) {
                // Cliente já existe, acumula valor
                totaisClientes.set(indice, totaisClientes.get(indice) + valorCompra);
            } else {
                // Novo cliente
                nomesClientes.add(nomeCliente);
                totaisClientes.add(valorCompra);
            }
        }

        List<String> saida = new ArrayList<>();
        for (int i = 0; i < nomesClientes.size(); i++) {
            String linha = nomesClientes.get(i) + ": " + totaisClientes.get(i);
            saida.add(linha);
        }

        try {
            Files.write(caminhoSaida, saida);
            System.out.println("Relatório gerado com sucesso em: " + caminhoSaida);
        } catch (IOException e) {
            System.out.println("Erro ao escrever o arquivo de saída: " + e.getMessage());
        }
    }
}
