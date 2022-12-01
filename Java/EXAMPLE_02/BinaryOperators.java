public class BinaryOperators{
    public static void main(String[] args){
        // Binary operators :
        System.out.println((1 & 1) + " " + (1 & 0) + " " + (0 & 1) + " " + (0 & 0));
        System.out.println((1 | 1) + " " + (1 | 0) + " " + (0 | 1) + " " + (0 | 0));
        System.out.println((1 ^ 1) + " " + (1 ^ 0) + " " + (0 ^ 1) + " " + (0 ^ 0));

        // 0001 << 1 = 0010           0001 << 3 = 1000
        System.out.println((1 << 1) + " " + (1 << 3));
        // 0010 >> 1 = 0001           1000 >> 3 = 0001
        System.out.println((2 >> 1) + " " + (8 >> 3));
        // ~ 00001000 = 11110111 = 1 + 2 + 4 + 16 + 32 + 64 - 128 = -9
        byte bnbr = 8; // Reverse all bits
        System.out.println((~ 8));
    }
}
