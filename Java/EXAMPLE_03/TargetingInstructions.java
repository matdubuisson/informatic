public class TargetingInstructions{
    static final int limit = 3;
    public static void main(String[] args){
        int test = -1;
        start:
        if(test == 0){
            System.out.println("The program has already been executed !!");
            continue end;
        }
        myLoop: {
            System.out.println("From strange loop : " + test);
            test++;
            if(test < limit){
                continue myLoop;
            }
            else{
                break myLoop;
            }
        }
        end:
        System.out.println("Good bye !!");
    }
}
