public class TestString{
    public static void sep(){
        System.out.println("====================================");
    }

    public static void main(String[] args){
        String str = new String("This is a chain of characters ii test i");

        // length()
        System.out.println(str.length());

        // charAt(), codePointAt(), codePointCount()
        char chr = str.charAt(5);
        System.out.println("The character has index 5 is : " + chr);
        System.out.println("Its value is : " + (int) chr);
        // Same thing than :
        int value_of_chr = str.codePointAt(5);
        System.out.println("Its value is : " + value_of_chr);

        System.out.println("There are " + str.codePointCount(0, str.length()) + " unicode value !!");

        sep(); /* ============================================= */

        String name = new String("Racteur");
        if(name.compareTo(str) == 0){
            System.out.println("name == str");
        }
        else{
            System.out.println("name != str");
        }

        if(name.compareTo("Racteur") == 0){     
            System.out.println("name == \"Racteur\"");
        }
        else{                         
            System.out.println("name != \"Racteur\"");
        }

        if(name.compareTo("RACtEuR") == 0){     
            System.out.println("name == \"RACtEuR\"");
        }
        else{                         
            System.out.println("name != \"RACtEuR\"");
        }

        if(name.compareToIgnoreCase("RAcTEur") == 0){     
            System.out.println("name == \"RAcTEur\" (compareToIgnoreCase)");
        }
        else{                         
            System.out.println("name != \"RAcTEur\" (compareToIgnoreCase)");
        }

        sep(); /* ============================================= */

        name = name.concat("____");
        System.out.println(name);
        name = name.concat(name);
        System.out.println(name);

        sep(); /* ============================================= */

        // Java format as C format :
        String formated_string = String.format("str = %s\nint = %d\n", "test_str", 14);
        System.out.println(formated_string);

        formated_string = formated_string.concat("test\ntest");
        String[] sl = formated_string.split("\n");
        for(int i = 0; i < sl.length; i++){
            System.out.print(sl[i] + " ");
        }
        System.out.println();

    }
}
