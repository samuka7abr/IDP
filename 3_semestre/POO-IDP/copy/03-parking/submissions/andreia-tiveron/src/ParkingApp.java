<<<<<<< HEAD
import java.util.ArrayList;

public class ParkingApp{

    public static void main(String[] args) {
        ArrayList<Vehicle> vehicles = new ArrayList<>();
        
        int hours = 4;
        vehicles.add(new Car("ABC-1234", "Toyota", "Corolla"));
        vehicles.add(new Motorcycle("XYZ - 5678", "Honda", "CG 160"));
        vehicles.add(new Truck("KLM-9090", "Volvo", "FH 540"));

        for (Vehicle v : vehicles) {
            System.out.println(v);
            System.out.printf("Valor a pagar por %dh: R$ %.2f%n", hours, v.calculateParkingFee(hours));
        }
    }
=======
import java.util.ArrayList;

public class ParkingApp{

    public static void main(String[] args) {
        ArrayList<Vehicle> vehicles = new ArrayList<>();
        
        int hours = 4;
        vehicles.add(new Car("ABC-1234", "Toyota", "Corolla"));
        vehicles.add(new Motorcycle("XYZ - 5678", "Honda", "CG 160"));
        vehicles.add(new Truck("KLM-9090", "Volvo", "FH 540"));

        for (Vehicle v : vehicles) {
            System.out.println(v);
            System.out.printf("Valor a pagar por %dh: R$ %.2f%n", hours, v.calculateParkingFee(hours));
        }
    }
>>>>>>> d7082028bf082955b1353afe1e05e9f3a57b69c6
}