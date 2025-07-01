/* Nome: Allan Samuel Alves do Monte
   Matrícula: 24101279     */
   
import java.util.Scanner;

public class Fibonacci {
    
    public static long calcularFibonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);  // Dessa vez utilizando recursividade ao invés de loop.
    }
    
    public static String formatarSaida(int n, long fib) {
        return String.format("O %dº número de Fibonacci é: %d", n, fib);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um número inteiro não negativo: ");
        int n = scanner.nextInt();

        if (n < 0) {
            System.out.println("Por favor, insira um número não negativo.");
            return;
        }

        long resultado = calcularFibonacci(n);
        System.out.println(formatarSaida(n, resultado));
        scanner.close();
    }
}

