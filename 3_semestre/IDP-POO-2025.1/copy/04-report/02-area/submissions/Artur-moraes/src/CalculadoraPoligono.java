import java.util.Scanner;
// colocado na pasta correta agora
public class CalculadoraPoligono {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o número de lados do polígono: ");
        int n = scanner.nextInt(); // n= numero de lados
        
        System.out.println("Digite o comprimento do lado em metros: ");
        double s = scanner.nextDouble(); // s= comprimento
        
        double area = calcularArea(n,s);
        String resultadoFormatado = formatarSaida(area);
        System.out.println(resultadoFormatado); //A= Area
        scanner.close();
    }

    public static double calcularArea(int n, double s){
        double area = (s*s* n/4) * (1/Math.tan(Math.PI/n));
        return area;
    }
    
    public static String formatarSaida(double area){
        String resultadoFormatado = String.format("A área do polígono é: %.2f metros quadrados", area);
        return resultadoFormatado;
    }
}