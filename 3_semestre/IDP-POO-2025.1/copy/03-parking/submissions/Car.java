public class Car extends Vehicle{
    
    public Car(String plate, String brand, String model){
        super(plate, brand, model);
    }

    @Override
    public double calculateParkingFee(int hours){
        return 5.00 * hours; 
    }       
}