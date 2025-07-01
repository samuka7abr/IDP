import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class RelatorioCompras {

    public static void main(String[] args) {
   
        if (args.length != 2) {
            System.out.println("Uso: java RelatorioCompras <arquivo-entrada> <arquivo-saida>");
            return;
        }

        String arquivoEntrada = args[0];
        String arquivoSaida = args[1];

        try {
  
            ArrayList<String> clientes = new ArrayList<>();
            ArrayList<Double> totais = new ArrayList<>();

        
            Path pathEntrada = Paths.get(arquivoEntrada);
            List<String> linhas = Files.readAllLines(pathEntrada);

          
            for (String linha : linhas) {
                try {
                    String[] campos = linha.split(",");
                    
                 
                    if (campos.length != 3) {
                        continue; 
                    }
                    
                    String nomeCliente = campos[0].trim();
                    String valorStr = campos[2].trim();
                    
                  
                    double valor = Double.parseDouble(valorStr);
                    
           
                    int index = clientes.indexOf(nomeCliente);
                    
                    if (index == -1) {
               
                        clientes.add(nomeCliente);
                        totais.add(valor);
                    } else {
                    
                        double totalAtual = totais.get(index);
                        totais.set(index, totalAtual + valor);
                    }
                    
                } catch (NumberFormatException e) {
    
                    System.err.println("Valor inválido na linha: " + linha);
                }
            }

     
            StringBuilder conteudoSaida = new StringBuilder();
            for (int i = 0; i < clientes.size(); i++) {
                conteudoSaida.append(clientes.get(i))
                            .append(": ")
                            .append(totais.get(i))
                            .append(System.lineSeparator());
            }

       
            Path pathSaida = Paths.get(arquivoSaida);
            Files.write(pathSaida, conteudoSaida.toString().getBytes());

            System.out.println("Relatório gerado com sucesso em: " + arquivoSaida);

        } catch (IOException e) {
            System.err.println("Erro ao processar arquivos: " + e.getMessage());
        }
    }
}
