public class Truck extends Vehicle {
    public Truck(String plate, String brand, String model) {
        super(plate, model, brand);
    }

    @Override
    public int calculateParkingFee(int hours) {
        return 10 * hours;
    }
    public String toString(){

        return "Caminhão - Placa: " +getPlate()+ " - Marca: " +getBrand()+ " - Modelo: " +getModel();
        }

}
