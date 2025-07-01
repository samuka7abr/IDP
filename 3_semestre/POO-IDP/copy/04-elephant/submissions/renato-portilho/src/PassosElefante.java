import java.util.Scanner;

public class PassosElefante {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite a posição da casa do amigo: ");
        int n = scanner.nextInt();
        int passos = calcularPassosMinimos(n);
        System.out.println("O número de passos para chegar na casa do amigo é: " + passos);
    }
    public static int  calcularPassosMinimos(int n){
        int contagem = 0; 
        while(n != 0){
            if(n >=5){
                n -= 5;
            }else if (n == 4) {
                  n -= 4;
            }else if (n == 3) {
                  n -= 3;
            }else if (n == 2) {
                  n -= 2;
            }else{
                  n -= 1;
            }
            contagem++;
        }
        return contagem;
        }
    }

