import java.util.Scanner;

public class CaminhoElefante {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Informe a posição da casa do amigo: ");
        int destino = input.nextInt();

        if (destino >= 1 && destino <= 1_000_000) {
            int passos = calcularMinimoPassos(destino);
            exibirResultado(passos);
        } else {
            System.out.println("Por favor, insira um número entre 1 e 1.000.000.");
        }

        input.close();
    }

    public static int calcularMinimoPassos(int distancia) {
        return (distancia + 4) / 5;  // Alternativa matemática para arredondamento para cima
    }

    public static void exibirResultado(int passos) {
        System.out.printf("Quantidade mínima de passos necessários: %d%n", passos);
    }
}

