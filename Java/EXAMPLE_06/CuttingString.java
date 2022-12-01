public class CuttingString{
    public static void printArray(String[] array){
        System.out.print("[");
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + "][");
        }
        System.out.println("]");
    }

    public static void main(String[] args){
        String sentence = "Bonsoir a comment allez vous ? a bientot. bien a vous a";
        printArray(sentence.split("a"));
        System.out.println(sentence.substring(0, 10));
        System.out.println(sentence.substring(14, 16));
    }
}
