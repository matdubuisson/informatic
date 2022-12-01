public class ReadString{
    public static void main(String[] args){
        String name = new String("Racteur");
        System.out.println(name);
        System.out.println(name.toString());
        for(int i = 0; i < name.length(); i++){
            System.out.println("Char " + name.charAt(i) + " at " + i);
            System.out.println("Code : " + name.codePointAt(i));
        }
        String number = String.valueOf(14);
        System.out.println(number.concat("_prove"));
        number = String.valueOf(14.4f);
        System.out.println(number.concat("_prove"));
        System.out.println("First '_' is at index : " + number.indexOf('_'));
        number = number.concat("_prove");
        System.out.println("First '_' is at index : " + number.indexOf('_'));
    }
}
