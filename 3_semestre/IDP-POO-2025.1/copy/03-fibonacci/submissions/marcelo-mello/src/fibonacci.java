import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite um número inteiro não negativo: ");
            int n = scanner.nextInt();

            long resultado = calcularFibonacci(n);
            String saida = formatarSaida(n, resultado);

            System.out.println(saida);
        }
    }

    public static long calcularFibonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        long a = 0, b = 1, temp;
        for (int i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    public static String formatarSaida(int n, long resultado) {
        return String.format("O %dº número de Fibonacci é: %d", n, resultado);
    }

    @Override
    public String toString() {
        return "Fibonacci []";
    }
}
