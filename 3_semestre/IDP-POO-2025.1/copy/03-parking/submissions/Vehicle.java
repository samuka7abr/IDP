public abstract class Vehicle{

    private String plate;
    private String brand;
    private String model;


    public Vehicle(String plate, String brand, String model){
        this.plate = plate;
        this.brand = brand;
        this.model = model;

    }

    public String getPlate(){
        return this.plate;
    }
    public void setPlate(String plate){
        this.plate = plate;
    }

    public String getBrand(){
        return this.brand;
    }
    public void setBrand(String brand){
        this.brand = brand;
    }

    public String getModel(){
        return this.model;
    }
    public void setModel(String model){
        this.model = model;
    }

    public abstract double calculateParkingFee(int hours);

    @Override
    public String toString(){
        return "Veículo: " + this.getClass().getSimpleName() + 
        " - Placa" + this.plate + 
        " - Marca: " + this.brand +
        " - Modelo: " + this.model;
    }

}
  