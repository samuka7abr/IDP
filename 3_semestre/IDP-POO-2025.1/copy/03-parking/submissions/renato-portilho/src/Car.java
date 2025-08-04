public class Car extends Vehicle {
    public Car(String plate, String brand, String model) {
        super(plate, model, brand);

    }

    @Override
    public int calculateParkingFee(int hours) {

        return 5 * hours;
    }

    public String toString(){

    return "Carro - Placa: " +getPlate()+ " - Marca: " +getBrand()+ " - Modelo: " +getModel();
    }
}
