import java.util.Scanner;

public class PassosElefante{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a posição da casa do amigo: ");
        int x = scanner.nextInt();

        if(x >= 1 && x <= 1000000){
            int res = calcularPassosMinimos(x);
                System.out.println(formatarSaida(res));
        }else{
            System.out.println("Digite números entre 1 e 1,000,000");
        }
    }

    public static int calcularPassosMinimos(int x) {
    int res = (x % 5 == 0) ? (x / 5) : (x / 5 + 1);
    return res;
    }

    public static String formatarSaida(int res){
        return String.format("O número mínimo de passos necessários é: %d", res);
    }
}