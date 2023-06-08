import java.util.*;

public class MovingZeros{
      static void moveZeros(int arr[]){
            int i=0;int j=0;
            while(i<arr.length){
                  if(arr[i]==0){
                        i++;
                  }
                  else{
                        arr[i]=arr[j];
                        i++;
                        j++;
                  }
            }
      }
      public static void main(String[] args) {
            Scanner s = new Scanner(System.in);
            int n=s.nextInt();
            int arr[]=new int[n];
            for(int i=0;i<n;i++){
                  arr[i]=s.nextInt();
            }
            moveZeros(arr);
            for(int i:arr){
                  System.out.println(i);
            }
            s.close();
      }

}