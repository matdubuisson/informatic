public class CompareString{
    public static void compare(String str0, String str1){
        int value = str0.compareTo(str1);
        if(value == 0){
            System.out.println(String.format("%s is equal to %s", str0, str1));
        } else if(value < 0){
            System.out.println(String.format("%s is smaller than %s", str0, str1));
        } else{
            System.out.println(String.format("%s is greater than %s", str0, str1));
        }
    }

    public static void compare2(String str0, String str1){         
        int value = str0.compareToIgnoreCase(str1);
        if(value == 0){           
            System.out.println(String.format("%s is equal to %s", str0, str1));
        } else if(value < 0){     
            System.out.println(String.format("%s is smaller than %s", str0, str1));
        } else{                   
            System.out.println(String.format("%s is greater than %s", str0, str1));
        }                         
    }

    public static void main(String[] args){
        String name = new String("Racteur");
        String name2 = "Joe"; // Equivalent of : new String("Joe");
        compare("abba", "abba");
        compare("racteur", "apple");
        compare("linux", "windows");
        compare("Linux", "linux");
        compare2("Linux", "linux");
        compare2("Linux", "LINUX");

        System.out.println(name.equals(name));
        System.out.println(name.equals(name2));

        System.out.println(name.contains("act"));
        System.out.println(name.contains("e"));
        System.out.println(name.contains("yolo"));

        System.out.println(name.isEmpty() + " " + "".isEmpty());
    }
}
