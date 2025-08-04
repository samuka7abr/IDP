import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {

    public static void main(String[] argumentos) {
        if (argumentos.length != 2) {
            System.out.println("Uso correto: java RelatorioCompras <arquivo_entrada> <arquivo_saida>");
            return;
        }

        String entrada = argumentos[0];
        String saida = argumentos[1];

        ArrayList<String> nomesClientes = new ArrayList<>();
        ArrayList<Double> valoresTotais = new ArrayList<>();

        try {
            Path entradaPath = Paths.get(entrada);
            List<String> linhasArquivo = Files.readAllLines(entradaPath);

            for (String linha : linhasArquivo) {
                String[] partes = linha.split(",");

                if (partes.length != 3) {
                    continue; // pula linha malformada
                }

                String cliente = partes[0].trim();
                double valor;

                try {
                    valor = Double.parseDouble(partes[2].trim());
                } catch (NumberFormatException e) {
                    System.err.println("Linha ignorada por valor inválido: " + linha);
                    continue;
                }

                int posicao = nomesClientes.indexOf(cliente);
                if (posicao == -1) {
                    nomesClientes.add(cliente);
                    valoresTotais.add(valor);
                } else {
                    valoresTotais.set(posicao, valoresTotais.get(posicao) + valor);
                }
            }

            List<String> conteudoFinal = new ArrayList<>();
            for (int i = 0; i < nomesClientes.size(); i++) {
                String linhaFormatada = String.format("%s: %.1f", nomesClientes.get(i), valoresTotais.get(i));
                conteudoFinal.add(linhaFormatada);
            }

            Path saidaPath = Paths.get(saida);
            Files.write(saidaPath, conteudoFinal);

            System.out.println("Arquivo gerado com sucesso: " + saida);

        } catch (IOException e) {
            System.err.println("Erro durante o processamento dos arquivos: " + e.getMessage());
        }
    }
}
