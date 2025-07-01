import java.util.Scanner;
import java.util.HashMap;

public class Fibonacci {
    private static HashMap<Integer, Long> memo = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um número inteiro não negativo: ");
        int n = scanner.nextInt();

        if (n < 0) {
            System.out.println("O número deve ser não negativo.");
        } else {
            long resultado = calcularFibonacci(n);
            System.out.println(formatarSaida(resultado, n));
        }

        scanner.close();
    }

    public static long calcularFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo.containsKey(n)) return memo.get(n);

        long fib = 0, anterior = 1, atual = 1;
        for (int i = 2; i < n; i++) {
            fib = anterior + atual;
            anterior = atual;
            atual = fib;
        }

        memo.put(n, atual);
        return atual;
    }

    public static String formatarSaida(long resultado, int n) {
        return String.format("O %dº número de Fibonacci é: %d", n, resultado);
    }
}