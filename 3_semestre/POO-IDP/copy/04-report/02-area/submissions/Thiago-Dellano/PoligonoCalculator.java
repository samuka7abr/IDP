import java.util.Scanner;

public class PoligonoCalculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Informe a quantidade de lados do polígono: ");
        int lados = input.nextInt();

        System.out.print("Informe o tamanho de cada lado (m): ");
        double comprimento = input.nextDouble();

        double areaPoligono = calcularAreaPoligono(lados, comprimento);
        exibirResultado(areaPoligono);

        input.close();
    }

    public static double calcularAreaPoligono(int lados, double comprimento) {
        return (0.25) * Math.pow(comprimento, 2) * lados * (1 / Math.tan(Math.PI / lados));
    }

    public static void exibirResultado(double area) {
        System.out.printf("A área do polígono é: %.2f metros quadrados%n", area);
    }
}
