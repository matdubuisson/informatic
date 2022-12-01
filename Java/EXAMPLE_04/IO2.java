import java.io.*;

class IO2{
    static final OutputStreamWriter osw = new OutputStreamWriter(System.out);
    public static void print(String msg){
        BufferedWriter bw = new BufferedWriter(osw);
        try{
            bw.write(msg.concat("\n"));
            bw.close(); // Write on stdout after closing
        } catch(Exception e){}
    }

    public static void main(String[] args){
        print("Yolo !!");
        print("This is Racteur !!");
    }
}
