public abstract class Vehicle {
    public String plate;
    public String model;
    public String brand;

    public Vehicle(String plate, String model, String brand) {
        this.plate = plate;
        this.model = model;
        this.brand = brand;

    }

    public abstract int calculateParkingFee(int hours);

    public String getPlate() {
        return plate;
    }

    public void setPlate(String plate) {
        this.plate = plate;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public abstract String toString();
}



