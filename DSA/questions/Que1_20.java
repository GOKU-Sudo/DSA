import java.util.*;

public class Que1_20{

      float radius;
      Que1_20(float radius){
            if(radius<0){
                  radius=0;
            }else{

                  this.radius=radius;
            }
      }
      float getArea(){
            float ans=radius*radius*3.14f;
            return ans;
      }
      public static void main(String[] args) {
            Scanner s = new Scanner(System.in);
            int n=s.nextInt();
            float arr[]=new float[n];
            if(n<1){
                  System.out.println("Invalid input");
                  System.exit(0);
            }
            for(int i=0;i<n;i++){

                  float radius=s.nextFloat();
                  Que1_20 q=new Que1_20(radius);
                  arr[i]=q.getArea();
            }
            for(int i=0;i<n;i++){
                  if(arr[i]>=30){
                        
                        System.out.format("%.4f",arr[i]);
                  }
            }
            s.close();
      }

}