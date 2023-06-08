import java.util.*;
public class PrimeFactor {
    public static void primeFactors(int n)
    {
        Set<Integer> ts1 = new TreeSet<>();
        int c = 2;
        while (n > 1) {
            if (n % c == 0) {
                ts1.add(c);
                n /= c;
            }
            else
                c++;
        }
        
        for(int i:ts1) System.out.print(i+" ");
    }
 
    /* Driver code */
    public static void main(String[] args)
    {
          Scanner s=new Scanner(System.in);
        int n =s.nextInt();
        if(10<=n && n<=50){
           primeFactors(n); 
        }
        
    }
}

      

