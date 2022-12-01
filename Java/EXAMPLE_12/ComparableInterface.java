import java.lang.Comparable; // Imported as default
import java.util.Arrays;
import java.util.Comparator;

public class ComparableInterface{
    public static void main(String[] args){
        System.out.println("Starting....");
        Car[] cars = new Car[]{
            new Car("Ford", 150),
            new Car("Ferrari", 280),
            new Car("Ferrari F1", 350),
            new Car("Ford", 110),
            new Car("Ford", 220),
            new Car("Truck", 90),
            new Car("Assault Thank", 60),
            new Car("Mario Kart", 1000),
            new Car("Mario Kart", 10)
        };

        for(Car each : cars){
            each.print();
        }

        System.out.println("==================================");
        Arrays.sort(cars); // Normal sort

        for(Car each : cars){                                    
            each.print(); 
        }

        System.out.println("==================================");
        Arrays.sort(cars, new CompareCars());
/*
        // Or implement directly :
        Arrays.sort(cars, new Comparator<Car>(){ // New sort
            // Can be used to change comparaison method or implement comparaison
            // for objects without compareTo method
            @Override
            public int compare(Car me, Car other){
                return me.speed - other.speed;
            }
        });
*/
        for(Car each : cars){
            each.print();
        }
    }
}

class CompareCars implements Comparator<Car>{
    @Override                        
    public int compare(Car me, Car other){
        return me.speed - other.speed;   
    }
}

class Car implements Comparable{
    String name;
    int speed;
    public Car(String name, int speed){
        this.name = name;
        this.speed = speed;
    }
    @Override // As default all classes extend the class Object
    public String toString(){
        return String.format("%s can ride at %d km/h !!", this.name, this.speed);
        //return this.name + " can ride at " + to.speed + " km/h !!";
    }
    public void print(){
        System.out.println(this.toString());
    }
    
    @Override
    public int compareTo(Object o){ // From Comparable interface
        // O is a car
        Car other = (Car) o;
        int result = this.name.toLowerCase().compareTo(other.name.toLowerCase());
        if(result == 0){
            return this.speed - other.speed;
        } else {
            return result;
        }
    }
}
