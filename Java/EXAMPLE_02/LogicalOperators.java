public class LogicalOperators{
    public static void main(String[] args){
        // Conditional operators :
        System.out.println(!true);
        System.out.println(!!true);
        System.out.println(true || false);
        System.out.println(false || false);
        System.out.println(true && false);
        System.out.println(true && true);
        System.out.println(!false && true);
        System.out.println(!false || false);
        System.out.println("===============");
        /*
        Not permitted in Java, in C it's possible !!
        int test = 14;
        System.out.println(!test);
        System.out.println(!test);
        */
    }
}
