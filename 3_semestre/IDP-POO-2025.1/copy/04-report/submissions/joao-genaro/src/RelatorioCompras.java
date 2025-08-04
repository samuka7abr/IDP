import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {
    public static void main(String[] parametros) {
        if (parametros.length < 2) {
            System.err.println("Uso correto: java RelatorioCompras <entrada> <saida>");
            System.exit(1);
        }

        Path caminhoEntrada = Path.of(parametros[0]);
        List<String> conteudo;
        try {
            conteudo = Files.readAllLines(caminhoEntrada);
        } catch (Exception erro) {
            System.err.println("Erro na leitura do arquivo: " + erro.getMessage());
            return;
        }

        ArrayList<String> nomes = new ArrayList<>();
        ArrayList<Double> valores = new ArrayList<>();

        for (String linhaAtual : conteudo) {
            String[] partes = linhaAtual.split(",");
            if (partes.length < 3) continue;

            String cliente = partes[0].trim();
            double total;

            try {
                total = Double.parseDouble(partes[2].trim());
            } catch (NumberFormatException ex) {
                continue;
            }

            int pos = nomes.indexOf(cliente);
            if (pos >= 0) {
                valores.set(pos, valores.get(pos) + total);
            } else {
                nomes.add(cliente);
                valores.add(total);
            }
        }

        List<String> resultadoFinal = new ArrayList<>();
        for (int i = 0; i < nomes.size(); i++) {
            resultadoFinal.add(nomes.get(i) + ": " + valores.get(i));
        }

        Path caminhoSaida = Path.of(parametros[1]);
        try {
            Files.write(caminhoSaida, resultadoFinal);
        } catch (Exception erro) {
            System.err.println("Erro ao escrever o arquivo: " + erro.getMessage());
        }
    }
}