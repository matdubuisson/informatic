public class TernaryOperators{
    public static String answer(String msg){
        return msg.compareTo("test") == 0 ? "This is a test !!" : msg.compareTo("retest") == 0 ? "This is a new test !!" : "This isn't a test !!";
    }

    public static void main(String[] args){
        // Ternary operators :
        int test = 1;
        test = test == 1 ? 0 : 2;
        System.out.println(test);
        test = test == 1 ? 0 : 5;
        System.out.println(test);

        System.out.println(answer("test"));
        System.out.println(answer("retest"));
        System.out.println(answer("yolo"));
   }
}
