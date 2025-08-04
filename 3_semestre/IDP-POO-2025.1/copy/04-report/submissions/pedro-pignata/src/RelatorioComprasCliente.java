import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class RelatorioComprasCliente {
    public static void main(String[] args) {
        if (args.length < 2) {
            return;
        }

        String caminhoEntrada = args[0];
        String caminhoSaida = args[1];

        Path arquivoEntrada = Paths.get(caminhoEntrada);
        Path arquivoSaida = Paths.get(caminhoSaida);

        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totais = new ArrayList<>();

        try {
            List<String> linhas = Files.readAllLines(arquivoEntrada);

            for (String linha : linhas) {
                String[] partes = linha.split(",");
                if (partes.length != 3) {
                    System.out.println("Linha ignorada (malformada): " + linha);
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
                    System.out.println("Erro ao converter valor numérico na linha: " + linha);
                }
            }

            List<String> linhasSaida = new ArrayList<>();
            for (int i = 0; i < clientes.size(); i++) {
                linhasSaida.add(clientes.get(i) + ": " + totais.get(i));
            }

            Files.write(arquivoSaida, linhasSaida);
            System.out.println("Relatório gerado com sucesso em: " + caminhoSaida);

        } catch (IOException e) {
            System.out.println("Erro ao processar o arquivo: " + e.getMessage());
        }
    }
}
