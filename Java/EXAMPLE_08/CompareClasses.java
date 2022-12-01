interface FormatName{
    public String format();
}

class UseFormatName implements FormatName{
    String name;
    public UseFormatName(String name){
        this.name = name;
    }
    public String format(){
        return "Extern : [ " + this.name + " ];";
    }
}

public class CompareClasses{
    String name;
    public CompareClasses(String name){
        this.name = name;
    }

    class InnerUseFormatName implements FormatName{
        public String format(){
            return "Inner : [ " + CompareClasses.this.name + " ];";
            // Or : return "Format : [ " + name + " ];";
        }
    }

    public void run(){
        FormatName extern = new UseFormatName(this.name);
        System.out.println(extern.format());
        FormatName inner = new InnerUseFormatName();
        System.out.println(inner.format());
        FormatName anonymous = new FormatName() { // This class is sugar for syntax because it's exactly the same thing than an inner class
            @Override
            public String format(){
                return "Anonymous : [ " + CompareClasses.this.name + " ];";
                // Or : return "Anonymous : [ " + name + " ];";
            }
        };
        System.out.println(anonymous.format());
    }

    public static void main(String[] args) {
        CompareClasses test = new CompareClasses("Racteur");
        test.run();
    }
}