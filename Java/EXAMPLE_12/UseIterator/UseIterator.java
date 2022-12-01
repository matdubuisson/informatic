import java.util.LinkedList;
import java.util.Iterator;

public class UseIterator{
    Integer value;
    UseIterator next;
    public UseIterator(Integer value, UseIterator next){
        this.value = value;
        this.next = next;
    }

    public static void main(String[] args){
        System.out.println("Starting....");
        LinkedList<String> list = new LinkedList<String>();
        list.add("Joe");
        list.add("Racteur");
        list.add("Bob Lenon");
        list.add("Ibisibou");

        Iterator<String> ite = list.iterator();
        while(ite.hasNext()){
            System.out.println(ite.next());
        }
    }
}
