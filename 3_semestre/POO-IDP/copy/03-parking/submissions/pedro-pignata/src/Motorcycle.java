public  class Motorcycle extends Vehicle{
    public Motorcycle(String plate, String brand, String model){
        super(plate, brand, model);
    }

    @Override
    public double calculateParkingFee(int hours){
        return hours * 3.0; // 3 reais por hora
    }
    @Override
    public String toString(){
        return "Moto" + super.toString();
    }
    
}
