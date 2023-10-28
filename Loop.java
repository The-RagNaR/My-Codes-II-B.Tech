import java.util.*;

public class Loop 
{
   public static void main(String[] args)
   {
    Scanner sc = new Scanner(System.in);
    System.out.println("Hello World");
    String name = sc.nextLine();
    for (int i=0;i<10;i++) 
    {
      System.out.println("Hello"+name);

    }
    sc.close();
   }
}