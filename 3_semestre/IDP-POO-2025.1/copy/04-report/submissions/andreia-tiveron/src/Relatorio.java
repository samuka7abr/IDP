import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class Relatorio{
    public static void main(String[] args) {

        Path entrada = Path.of(args[0]);//aqui as strings de entrada e saída
        Path saida = Path.of(args[1]);

        List<String> linhas;
        try {
            linhas = Files.readAllLines(entrada);
        } catch (IOException e) {
            System.out.println("Erro no arquivo de entrada: " + e.getMessage());
            return;
        }

        ArrayList<String> clientes = new ArrayList<>();
        ArrayList<Double> totais = new ArrayList<>();

        for (String linha : linhas) {
            String[] partes = linha.split(",");

            if (partes.length < 3) {//menos de 3 campos
                System.out.println("Linha malformada ignorada: " + linha);
                continue;
            }

            String nomeCliente = partes[0].trim();
            String valorS = partes[2].trim();//valor da compra em string

            double valor;
            try {
                valor = Double.parseDouble(valorS);
            } catch (NumberFormatException e) {
                System.out.println("Valor inválido ignorado: " + valorS);
                continue;
            }

            int indice = clientes.indexOf(nomeCliente);
            if (indice == -1) {
                clientes.add(nomeCliente);
                totais.add(valor);
            } else {
                totais.set(indice, totais.get(indice) + valor);
            }
        }

        List<String> linhasSaida = new ArrayList<>();
        for (int i = 0; i < clientes.size(); i++) {
            String linhaSaida = clientes.get(i) + ": " + totais.get(i);
            linhasSaida.add(linhaSaida);
        }

        try {
            Files.write(saida, linhasSaida);
            System.out.println("Relatório gerado no caminho: " + saida.toAbsolutePath());
        } catch (IOException e) {
            System.out.println("Erro ao escrever o arquivo de saída: " + e.getMessage());
        }
    }
}
