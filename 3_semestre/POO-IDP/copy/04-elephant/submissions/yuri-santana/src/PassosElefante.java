import java.util.Scanner;

public class PassosElefante {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Digite a posição da casa do amigo: ");
    int n = scanner.nextInt();
    scanner.close();
    int ans = calcularPassosMinimos(n);
    String resposta = formatarSaida(ans);
    System.out.println(resposta);
  }
  public static int calcularPassosMinimos(int n) {
    int count = 0;
    while (n > 0) {
      if (n/5 > 0) {
        count += n/5;
        n = n%5;
      }
      else if(n/4 > 0){
        count += n/4;
        n = n%4;
      }
      else if(n/3 > 0){
        count += n/3;
        n = n%3;
      }
      else if(n/2 > 0){
        count += n/2;
        n = n%2;
      }
      else{
        count += n;
        n = 0;
      }
    }
    return count;
  }
  public static String formatarSaida(int n) {
    return "O número mínimo de passos necessários é: " + n;
  }
}
