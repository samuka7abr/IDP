import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.nio.charset.StandardCharsets;
import java.text.DecimalFormat;

public class RelatorioCompras {

    public static void main(String[] args) {
        // Verifica se o número correto de argumentos foi passado
        if (args.length != 2) {
            System.out.println("Uso: java RelatorioCompras <caminho_entrada> <caminho_saida>");
            return;
        }

        String caminhoEntrada = args[0];
        String caminhoSaida = args[1];

        // Listas para armazenar os nomes dos clientes e seus totais de compras
        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totais = new ArrayList<>();

        try {
            // Lê todas as linhas do arquivo de entrada
            List<String> linhas = Files.readAllLines(Paths.get(caminhoEntrada), StandardCharsets.UTF_8);

            for (String linha : linhas) {
                // Divide a linha em partes
                String[] partes = linha.split(",");

                // Ignora linhas malformadas
                if (partes.length < 3) {
                    continue;
                }

                String nomeCliente = partes[0].trim();
                double valor;

                // Tenta converter o valor para double
                try {
                    valor = Double.parseDouble(partes[2].trim());
                } catch (NumberFormatException e) {
                    // Ignora linha com valor inválido
                    continue;
                }

                // Acumula o total de compras por cliente
                int index = clientes.indexOf(nomeCliente);
                if (index == -1) {
                    // Cliente não encontrado, adiciona novo cliente e valor
                    clientes.add(nomeCliente);
                    totais.add(valor);
                } else {
                    // Cliente encontrado, acumula o valor
                    totais.set(index, totais.get(index) + valor);
                }
            }

            // Formata os totais para uma casa decimal
            DecimalFormat df = new DecimalFormat("#0.0");

            // Prepara as linhas de saída
            List<String> linhasSaida = new ArrayList<>();
            for (int i = 0; i < clientes.size(); i++) {
                String linhaSaida = clientes.get(i) + ": " + df.format(totais.get(i));
                linhasSaida.add(linhaSaida);
            }

            // Escreve o relatório no arquivo de saída
            Path caminhoArquivoSaida = Paths.get(caminhoSaida);
            Files.write(caminhoArquivoSaida, linhasSaida, StandardCharsets.UTF_8);

            System.out.println("Relatório gerado com sucesso em: " + caminhoSaida);

        } catch (IOException e) {
            System.out.println("Erro ao ler ou escrever arquivos: " + e.getMessage());
        }
    }
}
