import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class FibonacciCalculator {
    private static Map<Integer, Long> cache = new HashMap<>();

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Informe um número inteiro não negativo: ");
        int numero = input.nextInt();

        if (numero < 0) {
            System.out.println("Por favor, insira um valor não negativo.");
        } else {
            long fibonacci = obterFibonacci(numero);
            mostrarResultado(fibonacci, numero);
        }

        input.close();
    }

    public static long obterFibonacci(int numero) {
        if (numero == 0) return 0;
        if (numero == 1) return 1;
        if (cache.containsKey(numero)) return cache.get(numero);

        long anterior = 1, atual = 1, resultado = 0;
        for (int i = 2; i < numero; i++) {
            resultado = anterior + atual;
            anterior = atual;
            atual = resultado;
        }

        cache.put(numero, atual);
        return atual;
    }

    public static void mostrarResultado(long valor, int posicao) {
        System.out.printf("O %dº termo da sequência de Fibonacci é: %d%n", posicao, valor);
    }
}
