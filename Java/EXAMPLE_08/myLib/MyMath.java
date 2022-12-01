package myLib;

class Constants{
    static double PI = 3.14;
    protected static int strange(int a){
        return MyMath.add2(a, (int) a / 2) - MyMath.add3((int) a / 3, a * 4);
    }
}

public class MyMath{
    // Can define class inside other class
    private class AccessConstants{
        public static double getPI(){
            return Constants.PI;
        }
    }

    /* // Can't override if it doesn't extend
    @Override
    public static int strange(int a){
        return super.strange(a + 16);
    }
    */

    public static int useStrange(int a){
        return Constants.strange(a);
    }

    public int add(int a, int b){
        return a + b;
    }

    static int add2(int a, int b){
        return a + b;
    }

    protected static int add3(int a, int b){
        return a + b;
    }

    protected static double area(double r){
        return AccessConstants.getPI() * r * r;
    }
}
