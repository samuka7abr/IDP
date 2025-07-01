/* Nome: Allan Samuel Alves do Monte
   Matrícula: 24101279     */
   
import java.util.Scanner;
import java.lang.Math;
 
public class CalculadoraPoligono {

    public static double calcularArea(int n, double s){
        
        double areaPoligono = (1.0 / 4.0) * Math.pow(s, 2) * n * (1.0 / Math.tan(Math.PI / n));
    
        return areaPoligono;
    }
    
    public static String formatarSaida(double area){
		
		return String.format("A área do polígono é: %.2f metros quadrados", area);
    }
    
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o número de lados do polígono: ");
		int lado_poligono = scanner.nextInt();
		
		System.out.print("Digite o comprimento do lado em metros: ");
		double comprimento_lado = scanner.nextDouble();
		
		double areaFormatada = calcularArea(lado_poligono, comprimento_lado);
		
		String formatacao = formatarSaida(areaFormatada);
		System.out.println(formatacao);
		
		scanner.close();
	}
}
