import java.util.Scanner;

public class Fibonacci {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número inteiro não negativo: ");
        int n = scanner.nextInt();

        if (n < 0) {
            System.out.println("Número inválido. Por favor, insira um número inteiro não negativo.");
        } else {
            long resultado = calcularFibonacci(n);
            String saida = formatarSaida(resultado, n);
            System.out.println(saida);
        }
        scanner.close();
    }

    public static long calcularFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        long anterior = 0;
        long atual = 1;
        long proximo = 0;

        for (int i = 2; i <= n; i++) {
            proximo = anterior + atual;
            anterior = atual;
            atual = proximo;
        }
        return atual;
    }

    public static String formatarSaida(long resultado, int n) {
        return String.format("O %dº número de Fibonacci é: %d", n, resultado);
    }
}
