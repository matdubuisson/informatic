package myLib;

public class Pack{
    private static int number_of_packs = 0;

    public static void printNumberOfPacks(){
        System.out.println("There are " + number_of_packs + " created packs !!");
    }

    private int id;
    public String name;
    public int age;

    public Pack(String name, int age){
        this.id = number_of_packs;
        number_of_packs++;
        this.name = name;
        this.age = age;
    }

    public boolean equals(Pack p){
        return this.name.compareTo(p.name) == 0 && this.age == p.age;
    }

    public String toString(){
        return String.format("Name : %s\nAge : %d\n", this.name, this.age);
    }
}
