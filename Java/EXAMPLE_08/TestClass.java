import myLib.*;

// All class inherits of the public things of MyMath
// All extended class on MyMath inherits of protected things
// All class defined in the same file of the class MyMath
// inherits of its default and protected things
// All private things are reserved for inside MyMath class

// TestClass is a subclass of MyMath
// It inherits of all protected attributes and methods
public class TestClass extends MyMath{
    // The first class has always the same name than the file
    public static void main(String[] args){
        Pack p = new Pack("Racteur", 19);
        System.out.println(p.toString());
        Pack p2 = new Pack("Racteur", 19);
        Pack p3 = new Pack("Joe", 4);
        System.out.println(p.equals(p2) + " " + p.equals(p3));
        Pack.printNumberOfPacks();

        System.out.println(TestClass.area(2.2));
        System.out.println(MyMath.area(2.2));

        System.out.println((new TestClass()).add(14, 16));
        System.out.println((new MyMath()).add(14, 16));

        System.out.println("Strange : " + MyMath.useStrange(14));
    }

    // How to modify an existant parent-method with @Override and super keywords
    @Override
    public int add(int a, int b){
        return super.add(a, b) + 1;
    }

    public static int test(){
        class Local{
            public static int retest(){
                return 14;
            }
        };
        return Local.retest() + 2;
    }
}

class Test{
    public static void ProduceError(){
        MyMath m = new MyMath();
        // It raises compilation error :
        // System.out.println("From Test : " + m.area(4.4));
        // System.out.println(MyMath.area(2.2));
  }
}

// It works :
class Test2 extends MyMath{
    public static void ProduceError(){
        MyMath m = new MyMath();
        System.out.println("From Test : " + m.area(4.4));
        System.out.println(MyMath.area(2.2));
    }
}
