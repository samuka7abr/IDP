import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class Compras {
    public static void main(String[] args) {

        Path entrada = Path.of(args[0]);
        Path saida = Path.of(args[1]);

        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totalCompra = new ArrayList<>();

        try {
            List<String> linhas = Files.readAllLines(entrada);

            for (int i = 0; i < linhas.size(); i++) {
                String linha = linhas.get(i);
                String[] partes = linha.split(",");

                if (partes.length < 3) {
                    continue;
                }

                String nomeCliente = partes[0].trim();
                String valorCheio = partes[2].trim();

                Double valor;
                try {
                    valor = Double.parseDouble(valorCheio);
                } catch (NumberFormatException e) {
                    continue;
                }

                int index = clientes.indexOf(nomeCliente);
                if (index >= 0) {
                    double total = totalCompra.get(index) + valor;
                    totalCompra.set(index, total);
                } else {
                    clientes.add(nomeCliente);
                    totalCompra.add(valor);
                }
            }

            List<String> linhaDeSaida = new ArrayList<>();

            for (int i = 0; i < clientes.size(); i++) {
                String linhaSaida = clientes.get(i) + ": " + totalCompra.get(i);
                linhaDeSaida.add(linhaSaida);
            }
            Files.write(saida, linhaDeSaida);
            System.out.println("saída: " + saida.toString());

        } catch (IOException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}