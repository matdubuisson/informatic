public class ScopeOperators{
    public static void main(String[] args){
        int a = 14;
        System.out.println(a);
        {
            int b = 16;
            //int a; => ERROR
            System.out.println(b);
            a += b;
            System.out.println(a);
        }
        {
            int b = 30;
            //int a; => ERROR
            System.out.println(b);
            {
                int c = 16;
                System.out.println(a + b + c);
                //int a; => ERROR
            }
        }
        //System.out.println(b); => ERROR
        //System.out.println(c); => ERROR
    }
}
