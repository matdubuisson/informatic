class DataPack{
    private static int a;
}

public class SpecialDeclarers{
    static int gvar = 2;
    static final int gfvar = 3;
    public static void main(String[] args){
        // static int errror = 14000; ==> Compilation error
        int _var = 4;
        final int fvar = 5;
        System.out.println(gvar + " " + gfvar + " " + _var + " " + fvar);       
        // fvar = 10; ==> Compilation error
    }
}
