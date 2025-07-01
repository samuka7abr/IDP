// Nome: Pedro Pignata'
import java.util.ArrayList;

public class ParkingApp {
    public static void main(String[] args) {
        // Criação do ArrayList de veículos
        ArrayList<Vehicle> vehicles = new ArrayList<>();

        vehicles.add(new Car("ABC1234", "BMW", "BMW Série 5/i5"));
        vehicles.add(new Motorcycle("XYZ5678", "Kawasaki", "Ninja H2R"));
        vehicles.add(new Truck("DEF9012", "Mercedes Benz", "Actros"));

        int hours = 4;
        for (Vehicle vehicle : vehicles) {
            System.out.println(vehicle);
            System.out.println("Valor a pagar por " + hours + " horas: R$ " + vehicle.calculateParkingFee(hours));
            System.out.println("-----------------------------------");
        }
    }
}