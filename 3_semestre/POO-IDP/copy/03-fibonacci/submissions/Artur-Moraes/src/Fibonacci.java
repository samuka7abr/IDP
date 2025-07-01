import java.util.Scanner;
public class Fibonacci{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite um número inteiro não negativo: ");
        int n = scanner.nextInt();

        if (n<0){
            System.out.println("O número não pode ser negativo");
        } else {
            long resultado = calcularFibonacci(n);
            String saidaFormatada = formatarSaida(resultado, n);
            System.out.println(saidaFormatada);
        }
        scanner.close();
    }

    public static long calcularFibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        long a = 0, b = 1, temp;
        for (int i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
    
    public static String formatarSaida(long resultado, int n){
        String saidaFormatada = String.format("O %dº número de Fibonacci é: %d", n, resultado);
        return saidaFormatada;
    }
}
