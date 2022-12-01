public class PrimitiveTypes{
    public static void main(String[] args){
        /*
            It's like in C !!
        */
        boolean flag = true;
        boolean cond = 4 == 5;
        int nbr = 14, nbr2 = 16;
        float fnbr = 3.14f;
        char letter = 'D', letter2 = 32;
        System.out.println(flag + " " + !flag);
        System.out.println(nbr + 16);
        System.out.println(fnbr / 3);
        System.out.println(letter + letter2 + letter);
        // Multi-Variables :
        int h;
        h = nbr = nbr2 = 1;
        System.out.println(h + nbr + nbr2);
    }
}
