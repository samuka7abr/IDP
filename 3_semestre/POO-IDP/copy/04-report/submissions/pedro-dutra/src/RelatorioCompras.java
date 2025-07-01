import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Uso: java RelatorioCompras <entrada.txt> <saida.txt>");
            return;
        }

        String caminhoEntrada = args[0];
        String caminhoSaida = args[1];

        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totais = new ArrayList<>();

        try {
            List<String> linhas = Files.readAllLines(Path.of(caminhoEntrada));

            for (String linha : linhas) {
                String[] partes = linha.split(",");

                if (partes.length < 3) {
                    continue;
                }

                String nomeCliente = partes[0].trim();
                String valorStr = partes[2].trim();

                try {
                    double valor = Double.parseDouble(valorStr);

                    int indice = clientes.indexOf(nomeCliente);
                    if (indice == -1) {
                        clientes.add(nomeCliente);
                        totais.add(valor);
                    } else {
                        totais.set(indice, totais.get(indice) + valor);
                    }

                } catch (NumberFormatException e) {
                    continue;
                }
            }

            ArrayList<String> saida = new ArrayList<>();
            for (int i = 0; i < clientes.size(); i++) {
                saida.add(clientes.get(i) + ": " + totais.get(i));
            }

            Files.write(Path.of(caminhoSaida), saida);
            System.out.println("Relatório gerado com sucesso em: " + caminhoSaida);

        } catch (IOException e) {
            System.out.println("Erro ao ler ou escrever o arquivo: " + e.getMessage());
        }
    }
}
