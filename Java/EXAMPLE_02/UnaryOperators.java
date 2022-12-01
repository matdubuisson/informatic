public class UnaryOperators{
    static final int limit = 3;
    public static void main(String[] args){
        // Unary operators :
        int i, j;
        for(i = j = limit; i >= 0; i--, --j){
            System.out.println("i : "+ i +"\nj : " + j);
        }
        i = j = 0;
        int test;
        test = i++; // Postfix
        System.out.println("Has old value of i : " + test);
        test = ++j; // Prefix
        System.out.println("Has new value of j : " + test);
        System.out.println("i : " + i + "\nj : " + j);

        i = 14;
        test = +i;
        System.out.println("Test : " + test + "\ni : " + i);
    }
}
