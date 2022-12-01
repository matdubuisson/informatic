public class Except extends Throwable{

    public static double divide(double a, double b) throws Exception, ArithmeticException{
        if(b == 0.0){
            throw new ArithmeticException("Can't divide number by zero !!");
        } else if(b == 14){
            throw new Exception();
        }
        return a / b;
    }

    public static void throwException() throws Exception{
        throw new Exception();
    }

    public static void main(String[] args){
        try{
            System.out.println(String.format("Division => %.2f", divide(16, 2)));
        } catch(ArithmeticException e){
            System.out.println("Division has failed !!");
        } catch(Exception e){
            System.out.println("Undefined error raised !!");
        } finally{
            System.out.println("============================");
        }

        try{
            System.out.println(String.format("Division => %f", divide(16, 0)));
        } catch(ArithmeticException e){
            System.out.println("Division has failed !! : " + e);
        } catch(Exception e){
            System.out.println("Undefined error raised !!");
        } finally{
            System.out.println("============================");
        }

        try{
            System.out.println(String.format("Division => %f", divide(16, 14)));
        } catch(ArithmeticException e){
            System.out.println("Division has failed !!");
        } catch(Exception e){
            System.out.println("Undefined error raised !!");
        } finally{
            System.out.println("============================");
        }
    }
}
