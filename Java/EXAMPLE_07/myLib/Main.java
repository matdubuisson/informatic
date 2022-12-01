package myLib;

class Tool{
    public static int a = 1, b = 2, c = 3;
}

public class Main {
    public static void printPublic(){
        System.out.println("Public !!");
    }
    protected static void printProtected(){
        System.out.println("Protected !!");
    }
    static void printDefault(){
        System.out.println("Default !!");
    }
    private static void printPrivate(){
        System.out.println("Private !!");
    }
    public static void usePrintPrivate(){
        printPrivate();
    }

    public static void testMain() {
        // All rights !!
        System.out.println("From Main.main :");
        printPrivate();
        printDefault();
        printProtected();
        printPublic();
        System.out.println("=================");
    }
}

class SubMain{
    // An other class in the same package gives access at public, protected and default
    public static void usePrintPublic(){
    Main.printPublic();
}
    public static void usePrintProtected(){
        Main.printProtected();
    }
    public static void usePrintDefault(){
        Main.printDefault();
    }
}

class SubMain2 extends Main{
    // An other class in the same package gives access at public, protected and default
    public static void usePrintPublic(){
        Main.printPublic();
    }
    public static void usePrintProtected(){
        Main.printProtected();
    }
    public static void usePrintDefault(){
        Main.printDefault();
    }
}