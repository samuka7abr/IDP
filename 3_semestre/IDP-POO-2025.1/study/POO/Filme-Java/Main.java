import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Filme f1 = new Filme();

        System.out.print("Digite o título do filme: ");
        f1.setTitulo(scanner.nextLine());

        System.out.print("\nDigite o nome do Diretor do filme: ");
        f1.setDiretor(scanner.nextLine());

        System.out.print("\nDigite o Ano de Lançamento: ");
        f1.setAnoLancamento(scanner.nextInt());

        System.out.print("\nDigite a nota do filme: ");
        f1.setNota(Double.parseDouble(scanner.next().replace(",", ".")));

        f1.exibirInfo();

        scanner.close();
    }
}
