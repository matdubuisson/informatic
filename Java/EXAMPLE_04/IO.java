public class IO{
    public static String input(){
        String str = "";
        try{
            int chr = System.in.read();
            while(chr != '\n'){
                str += (char) chr;
                chr = System.in.read();
            }
        } catch(Exception e){ // The try catch here is forced by the compiler
            System.out.println("Error to read buffer !!");
        }
        return str;
    }

    public static String input(String msg){
        System.out.print(msg);
        return input();
    }

    public static void main(String[] args){
        System.out.println("Test"); // stdout
        System.out.print("Test\n");
        System.err.println("Test"); // stderr
        String name = input("What is your name ? ");
        System.out.println("Your name is : " + name);

        for(int i = 0, j; i < name.length(); i++){
            for(j = 0; j < i; j++){
                System.out.write(32);
            }
            System.out.write(name.charAt(i));
            System.out.write('\n');
        }
        System.out.println();
    }
}
