import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.err.println("Uso: java RelatorioCompras <arquivoEntrada> <arquivoSaida>");
            System.exit(1);
        }
        Path input = Path.of(args[0]);
        List<String> linhas;
        try {
            linhas = Files.readAllLines(input);
        } catch (Exception e) {
            System.err.println("Erro ao ler arquivo de entrada: " + e.getMessage());
            return;
        }
        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totais  = new ArrayList<>();
        for (String linha : linhas) {
            String[] campos = linha.split(",");
            if (campos.length < 3) continue;
            String nome = campos[0].trim();
            double valor;
            try {
                valor = Double.parseDouble(campos[2].trim());
            } catch (NumberFormatException e) {
                continue;
            }
            int idx = clientes.indexOf(nome);
            if (idx >= 0) {
                totais.set(idx, totais.get(idx) + valor);
            } else {
                clientes.add(nome);
                totais.add(valor);
            }
        }
        List<String> saida = new ArrayList<>();
        for (int i = 0; i < clientes.size(); i++) {
            saida.add(clientes.get(i) + ": " + totais.get(i));
        }
        Path output = Path.of(args[1]);
        try {
            Files.write(output, saida);
        } catch (Exception e) {
            System.err.println("Erro ao gravar arquivo de saída: " + e.getMessage());
        }
    }
}
