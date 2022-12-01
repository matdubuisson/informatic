public class LoopingInstructions{
    static final int limit = 3;
    public static void main(String[] args){

        int i;
        i = 0;
        while(i < limit){
            System.out.println("From while loop : " + i);
            i++;
        }

        i = 0;
        do{
            System.out.println("From do-while loop : " + i);
            i++;
        }while((i < limit) && (i != 0));

        int[] lst = new int[limit];
        for(i = 0; i < limit; i++){
            System.out.println("From for loop : " + i);
            lst[i] = i;
        }

        for(int each : lst){
            System.out.println("From for-each loop : " + each);
        }

        /*
            =================================================
        */

        i = 0;
        while(true){
            System.out.println("_TEST_BREAK_" + i + "_");
            if(i == limit){
                break;
            }
            System.out.println("From while-break loop : " + i);
            i++;
        }

        i = 0;
        boolean flag = true;
        while(i < limit){
            System.out.println("From while-continue loop : " + i);
            if(true){
                i++;
                continue;
            }
            System.out.println("Never printed !!");
            i = 0; // Never executed !!
        }

    }
}
