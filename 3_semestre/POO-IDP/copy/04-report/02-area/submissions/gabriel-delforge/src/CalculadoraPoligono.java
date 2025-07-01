import java.util.Scanner;

public class CalculadoraPoligono {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Solicitação de entrada do usuário
        System.out.print("Digite o número de lados do polígono: ");
        int n = scanner.nextInt();
        
        System.out.print("Digite o comprimento do lado em metros: ");
        double s = scanner.nextDouble();
        
        scanner.close();
        
        // Cálculo da área do polígono
        double area = calcularArea(n, s);
        
        // Exibição do resultado formatado
        System.out.println(formatarSaida(area));
    }
    
    public static double calcularArea(int n, double s) {
        return (1.0 / 4.0) * Math.pow(s, 2) * n / Math.tan(Math.PI / n);
    }
    
    public static String formatarSaida(double area) {
        return String.format("A área do polígono é: %.2f metros quadrados", area);
    }
}
