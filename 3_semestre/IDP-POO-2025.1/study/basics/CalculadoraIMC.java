import java.utils.Scanner;

public class CalculadoraIMC{
    Scanner scanner = new Scanner(System.in);
    public static double calcularIMC(double altura, double peso){
        return peso / Math.pow(altura, 2);
    }
    
    public static String classificarIMC(double imc){
        if (imc < 18.5) return "Abaixo do peso";
        else if (imc >= 18.5 && imc < 24.99) return "Eutrófico";
        else if (imc >= 25.0 && imc < 29.99) return "Sobrepeso";
        else if (imc >= 30.0 && imc < 34.99) return "Obesidade grau I";
        else if (imc >= 35.0 && imc < 39.99) return "Obesidade grau II";
        else return "Obesidade grau III";
    }


    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("peso: ");
        double peso = scanner.nextDouble();

        System.out.print('altura: ');
        double altura = scanner.nextDouble();

        double imc = calcularIMC(altura, peso);
        String resultado = classificarIMC(imc);

        System.out.printf("Seu IMC é: %.2f%n", imc);
        System.out.println("Classificação: " + classificacao);

        scanner.close();
    }
}