class Parent{
    public void parentYolo(){
        System.out.println("Yolo from parent !!");
    }
    public void test(){
        System.out.println("!! TEST OF PARENT !!");
    }
}

class Child extends Parent{
    public void childYolo(){
        System.out.println("Yolo from child !!");
    }
    @Override
    public void test(){
        System.out.println("!! RETEST OF CHILD !!");
    }
}

public class CastingOperators{
    public static void main(String[] args){
        // Changes data types
        int value = (int) ' ';
        char chr = (char) 33;
        System.out.println(value + " " + chr);
        // Casting for objects
        {
            Child c = new Child();
            c.parentYolo();
            c.childYolo();
            c.test();
        }
        System.out.println("===================");
        {
            Parent p = new Child();
            p.parentYolo();
            // p.childYolo(); // => Not allowed because typed of Parent
            p.test();
            Child c = (Child) p;
            c.parentYolo();
            c.childYolo(); // But allowed after Child casting
            c.test();
        }
    }
}
