import java.util.Scanner;

public class CalculadoraPoligono {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite a quantidade de lados do polígono: ");
        int n = scanner.nextInt();

        System.out.println("Digite o comprimento de um lado: ");
        double s = scanner.nextDouble();

        double area = calcularArea(n,s);
        System.out.println("A área do polígono é: " +area);
    }
    public static double calcularArea(int n, double s){
        return (n * Math.pow(s,2)) / (4 * Math.tan(Math.PI / n));
    }
}

