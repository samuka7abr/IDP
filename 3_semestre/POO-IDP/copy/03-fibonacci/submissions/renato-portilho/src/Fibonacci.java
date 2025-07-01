import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número inteiro não negativo: ");
        int n = scanner.nextInt();

        long valor = calcularFibonacci(n); 
        String resultado = formatarSaida(n, valor); 

        System.out.println(resultado); 
    }

    public static long calcularFibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
        }
    }

    public static String formatarSaida(int n, long valor) {
        return String.format("O %dº número da sequência de Fibonacci é: %d", n, valor);
    }
}
