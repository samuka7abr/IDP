public class Motorcycle extends Vehicle {
    public Motorcycle(String plate, String brand, String model) {
        super(plate, model, brand);
    }

    @Override
    public int calculateParkingFee(int hours) {
        return 3 * hours;
    }

    public String toString(){

        return "Moto - Placa: " +getPlate()+ " - Marca: " +getBrand()+ " - Modelo: " +getModel();
        }
}
