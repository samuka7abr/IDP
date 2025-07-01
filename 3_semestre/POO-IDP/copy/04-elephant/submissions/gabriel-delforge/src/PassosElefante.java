import java.util.Scanner;

public class PassosElefante {
    
    // Método principal
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a posição da casa do amigo: ");
        int x = scanner.nextInt();
        
        if (x < 1 || x > 1_000_000) {
            System.out.println("Erro: A posição deve estar entre 1 e 1.000.000.");
        } else {
            int passos = calcularPassosMinimos(x);
            System.out.println(formatarSaida(passos));
        }
        
        scanner.close();
    }
    
    // Método para calcular o número mínimo de passos
    public static int calcularPassosMinimos(int x) {
        return (x + 4) / 5; // Equivalente a Math.ceil(x / 5.0)
    }
    
    // Método para formatar a saída
    public static String formatarSaida(int passos) {
        return "O número mínimo de passos necessários é: " + passos;
    }
}
