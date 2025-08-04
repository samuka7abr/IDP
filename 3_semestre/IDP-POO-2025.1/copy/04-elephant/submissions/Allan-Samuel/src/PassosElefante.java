/* Nome: Allan Samuel Alves do Monte
   Matrícula: 24101279     */
   
import java.util.Scanner;

public class PassosElefante {

    public static int calcularPassosMinimos(int x) {
        int passos = x / 5;
        if (x % 5 != 0) {
            passos++;
        }
        return passos;
    }

    public static String formatarSaida(int passos) {
        return "O número mínimo de passos necessários é: " + passos;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a posição da casa do amigo: ");
        int x = scanner.nextInt();

        if (x < 1 || x > 1000000) {
            System.out.println("A posição deve estar entre 1 e 1.000.000.");
            return;
        }

        int resultado = calcularPassosMinimos(x);

        System.out.println(formatarSaida(resultado));
        
        scanner.close();
    }
}
