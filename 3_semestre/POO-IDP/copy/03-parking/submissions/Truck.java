public class Truck extends Vehicle{
    public Truck(String plate, String brand, String model){
        super(plate, brand, model);
    }

    @Override
    public double calculateParkingFee(int hours){
    return 10.00 * hours; 
    }
}