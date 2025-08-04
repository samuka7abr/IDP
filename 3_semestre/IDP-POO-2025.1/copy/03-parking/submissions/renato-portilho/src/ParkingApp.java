import java.util.ArrayList;

public class ParkingApp {
    public static void main(String[] args) {
        ArrayList <Vehicle> veiculos = new ArrayList<>();

        veiculos.add(new Car("DEF5678", "Honda", "Civic"));
        veiculos.add(new Motorcycle("LMN5678", "Honda", "CB500"));
        veiculos.add(new Truck("GJS-9804", "Volvo", "FH"));
        
        int hours = 4;

        for (int i = 0; i < veiculos.size(); i++) {
            Vehicle veiculo = veiculos.get(i);
            System.out.println(veiculo);
            System.out.println("Valor a pagar por 4 horas: R$: "+veiculo.calculateParkingFee(hours) );
            System.out.println("");
            
        }
    }
}
