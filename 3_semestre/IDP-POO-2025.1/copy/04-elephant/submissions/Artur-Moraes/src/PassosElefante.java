import java.util.Scanner;

public class PassosElefante{ //classe agora com nome correto
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite a posição da casa do amigo: ");
        int x = scanner.nextInt();
        if (x<1 || x>1000000){
            System.out.println("O número deve estar no intervalo de 1 a 1.000.000");
        } else {
            int resultado = calcularPassosMinimos(x);
            String saidaFormatada = formatarSaida(resultado);
            System.out.println(saidaFormatada);
        }
        scanner.close();
    }
    public static int calcularPassosMinimos(int x){
        int resultado;
        if (x%5==0){
            resultado = x/5;
        }else{
            resultado = x/5 + 1;
        }
        return resultado;
    }

    public static String formatarSaida( int resultado){
        return String.format("O número mínimo de passos necessários é: %d", resultado);
    }
}