import java.util.Comparator;

interface DoSomething{
    public void doIt();
}

interface DoSomethingElse{
    public Object doIt(Object arg);
}

class Person{
    String name;
    int age;
    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }
}

public class Lambda{
    public static void main(String[] args) {
        DoSomething print = () -> System.out.println("Yolo !!");
        print.doIt();
        DoSomethingElse concat = (str) -> {
            return str + " CONCAT";
        };
        System.out.println(concat.doIt("Test !! "));
        // Comparator is an interface
        Comparator<Person> cmp = (thisPerson, otherPerson) -> thisPerson.name.equals(otherPerson.name) ? thisPerson.age - otherPerson.age : thisPerson.name.compareTo(otherPerson.name);
        Person a = new Person("a", 0);
        Person a1 = new Person("a", 1);
        Person b = new Person("b", 0);
        System.out.println(cmp.compare(a, a1) < 0);
        System.out.println(cmp.compare(a, b) < 0);
    }
}