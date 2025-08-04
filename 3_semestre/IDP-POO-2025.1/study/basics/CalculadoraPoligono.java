import java.utils.Scanner;

public class CaluladoraPoligono{
    public static double calcularArea(double numLados, double tamLados){
        return (1.0 / 4) * Math.pow(s, 2) * n * (1 / Math.tan(Math.PI / n)); 
    }

    public static String formatarSaida(double area){
        return String.format("area: %.2f", area);
    }

    public static void main(String[] args){
        System.out.print("numero de lados: ");
        double lados = scanner.nextDouble();

        System.out.print("tamanho dos lados em m: ");
        double tamanho = scanner.nextDouble();

        double area = calcularArea(lados, tamanho);
        String saida = formatarSaida(area);

        System.out.println(saida);
        
        scanner.close();
    }
}