import java.util.Scanner;

public class Fibonacci {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número inteiro não negativo: ");
        
        int n = scanner.nextInt();
        scanner.close();
        
        if (n < 0) {
            System.out.println("Número inválido. Digite um inteiro não negativo.");
            return;
        }
        
        long resultado = calcularFibonacci(n);
        System.out.println(formatarSaida(n, resultado));
    }
    
    public static long calcularFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long a = 0, b = 1, temp;
        for (int i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
    
    public static String formatarSaida(int n, long resultado) {
        return "O " + n + "º número de Fibonacci é: " + resultado;
    }
}
