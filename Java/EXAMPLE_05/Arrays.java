public class Arrays{
    public static void printArray(int[] array){
        System.out.print("Printer for int : ");
        System.out.print("[ ");
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println("]");
    }

    public static void printArray(double[] array){
        System.out.print("Printer for double : ");
        System.out.print("[ "); 
        for(int i = 0; i < array.length; i++){     
            System.out.print(array[i] + " ");      
        }                       
        System.out.println("]");     
    }

    public static void printMatrix(int[][] matrix){
        System.out.println("Printer for matrix : ");
        System.out.println("=====================");
        for(int i = 0; i < matrix.length; i++){
            printArray(matrix[i]);
        }
        System.out.println("=====================");
    }

    public static void main(String[] args){
        int[] p0; // This a pointer of array
        double[] p1 = null; // As default it takes null value
        int[] p2 = new int[4]; // Give to p2 the address of an new array of length 4
        
        p0 = new int[5];
        p0 = new int[3]; // p0 loses its previous array
        p0[0] = p0[2] = 4; p0[1] = 6;
        printArray(p0);

        p1 = new double[]{1.2, 4.7, 1.4, 1.6, 8.8};
        printArray(p1);

        printArray(p2);

        int[][] p3 = new int[][]{p0, p2, {2, 1, 0}, {1, 2, 3, 44, 56382, 4, 5, 6}};
        printMatrix(p3);
    }
}
