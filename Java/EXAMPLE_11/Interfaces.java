import myLib.Animal;

interface Car{
    // All cars need to have these methods !!
    public void speedUp();
    public void type();
    public void location();
}

abstract class DefaultType implements Car{
    @Override
    public void type(){
        System.out.println("Ferrari type");
    }
}

abstract class BelgianCar extends DefaultType implements Car{
    @Override
    public void location(){
        System.out.println("Belgium");
    }
}

class Manual{
    public static interface Rally{
        public void lights();
    }
    public static interface Road{
        public void wheels();
    }
}

class Ferrari extends DefaultType implements Car{
    @Override
    public void speedUp(){
        System.out.println("Drive to 300km/h");
    }
    @Override
    public void location(){
        System.out.println("Ferrari is from Italia !!");
    }
}

class FerrariF1 extends Ferrari implements Car, Manual.Road{
    @Override
    public void type(){
        System.out.println("Ferrari F1");
    }
    @Override
    public void wheels(){
        System.out.println("Robuste wheels for Ferrari F1 !!");
    }
}

class Mazda extends BelgianCar implements Car, Manual.Rally{
    @Override
    public void speedUp(){
        System.out.println("Mazda go up !!");
    }
    @Override
    public void type(){
        System.out.println("Mazda-type");
    }
    @Override
    public void lights(){
        System.out.println("Distance of the lights : 100m");
    }
}

class GuineaPig implements Animal{
    String name;

    public GuineaPig(String name){
        this.name = name;
    }

    @Override
    public void run(){
        System.out.println(this.name + " is running !!");
    }

    public void noise(){
        System.out.println("KOUIKOUI");
    }
}

public class Interfaces{
    public static void main(String[] args){
        Car f = new Ferrari(), f1 = new FerrariF1(), m = new Mazda();
        f.speedUp();
        f.type();
        f.location();
        f1.type();
        f1.location();
        // f1.wheels(); => Bad pointer
        m.speedUp();
        m.type();
        m.location();
        // m.lights(); => Bad pointer

        FerrariF1 f1_ = (FerrariF1) f1;
        f1_.wheels();
        ((Mazda) m).lights();

        // Reject all instance of abstract class
        // BelgianCar f_ = new Ferrari();
        // BelgianCar b = new BelgianCar();

        Animal oscar = new GuineaPig("Oscar");
        oscar.run();
        // oscar.noise(); => Animal type doesn't make pointers able to use this method !!
        GuineaPig gerald = new GuineaPig("Gérald");
        gerald.run();
        gerald.noise();
    }
}
