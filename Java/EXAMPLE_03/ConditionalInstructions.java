public class ConditionalInstructions{
    public static void main(String[] args){
        int test = 14;
        if(test == 16){
            System.out.println("Test equals 16 !!");
        }
        else{
            System.out.println("Test doesn't equal 16 !!");
        }
        test = 16;
        if(test == 16){                   
            System.out.println("Test equals 16 !!");
        }
        else if(test == 22){
            System.out.println("Test = 22....");
        }
        else{                             
            System.out.println("Test doesn't equal 16 !!");
        }


        for(test = 0; test < 5; test++){
            switch(test){
                case 0:
                    System.out.println("It's the first loop !!");
                    break;
                case 1:
                    System.out.println("It's the second loop !!");
                    break;
                default:
                    System.out.println("It's the " + (test + 1) + "th loop.");
            }
        }

    }
}
