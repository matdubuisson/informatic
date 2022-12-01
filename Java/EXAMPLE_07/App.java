import myLib.Main;
//import myLib.Tool; => Not allowed
class AppForProtected extends Main{
    public static void usePrintPublic(){
        Main.printPublic();
    }
    public static void usePrintProtected(){
        Main.printProtected();
    }
}
public class App {
    public static void main(String[] args) {
        Main.printPublic();
        Main.usePrintPrivate();

        System.out.println("From AppForProtected : ");
        AppForProtected.usePrintPublic();
        AppForProtected.usePrintProtected();
        System.out.println("=======================");

        Main.testMain();
    }
}
