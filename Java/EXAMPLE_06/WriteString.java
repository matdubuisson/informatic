public class WriteString{
    public static void main(String[] args){
        String name = new String("Racteur");
        System.out.println(name.toLowerCase());
        System.out.println(name.toUpperCase());
        System.out.println(name.concat(name));
        System.out.println(name);
        name = name.concat("aaaaa");
        name = name.concat(name);
        System.out.println(name);
        System.out.println(name.replace('a', 'Z'));

        // Equivalent of printf() in C
        System.out.println(String.format("The string is %s the float is %4.2f the integer is %6d !!", "Yolo !!", 16.01, 14));

        char[] chn = new char[]{'Y', 'o', 'l', 'o', ' ', '!', '!'};
        name = name.copyValueOf(chn, 0, chn.length);
        System.out.println(name);

        name = "       \n\n Racteur     \n    ";                          
        System.out.println(name.trim()); // Equivalent of split() in python
    }
}
