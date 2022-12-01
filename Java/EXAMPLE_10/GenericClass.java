class Pair{
    String name;
    int age;
    public Pair(String name, int age){
        this.name = name;
        this.age = age;
    }
}

class ImprovedPair<LeftType, RightType>{
    LeftType left;
    RightType right;
    public ImprovedPair(LeftType leftData, RightType rightData){
        this.left = leftData;
        this.right = rightData;
    }
}

public class GenericClass{
    public static void main(String[] args){
        Pair p = new Pair("Racteur", 19);
        System.out.println(p.name + " " + p.age);
        // p = new Pair(16, 14); => Rejected at the compilation !!
        ImprovedPair<Integer, Integer> ip0 = new ImprovedPair<Integer, Integer>(16, 14);
        System.out.println(ip0.left + " " + ip0.right);
        ImprovedPair<String, String> ip1 = new ImprovedPair<String, String>("Yolo !!", "Joe");
        System.out.println(ip1.left + " " + ip1.right);
        ImprovedPair<Integer, Character> ip2 = new ImprovedPair<Integer, Character>(30, '!');
        System.out.println(ip2.left + " " + ip2.right);
    }
}
