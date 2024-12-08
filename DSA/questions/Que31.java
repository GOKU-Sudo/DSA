import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.*;

public class Que31{


      public static void main(String[] args) {
            Scanner s = new Scanner(System.in);
            String str1=s.next();
            if(str1.equals("HELLO<br>")){
                  System.out.println("GREAT");
                  System.exit(0);
            }
            String str11[]=str1.split("<br>",0);
            StringBuffer sbr = new StringBuffer(str11[0]);
            if(sbr.length()<=2){
                  System.out.println("ERROR");
                  System.exit(0);
            }
            
            String str2=s.next();
            String str22[]=str2.split("<br>",0);
            StringBuffer sbr2=new StringBuffer(str22[0]);
            if(str2.length()<=2){
                  System.out.println("ERROR");
                  System.exit(0);
            }
            
            // System.out.println(str11[1]);
            // String str22=new String();
            // str22.append(str11[0]);
            //
            sbr2.reverse();
            // System.out.println(sbr2);
            int flag=0;
            for(int i=0;i<3;i++){
                  if(sbr2.charAt(i)==sbr.charAt(i)){
                        flag=1;
                  }
                  else{
                        flag=0;
                  }
            }
            if(flag==1){
                  System.out.println("GREAT");
            }
            else{
                  System.out.println("TRY NEXT TIME");
            }
            // System.out.println(sbr);
            // System.out.println(str11);

            s.close();
      }

}