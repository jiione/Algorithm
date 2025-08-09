import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input;

        input=br.readLine().split(" ");

        int H = Integer.parseInt(input[0]);
        int W = Integer.parseInt(input[1]);

        input=br.readLine().split(" ");

        int[] arr = new int[W];
        int[] L = new int[W];
        int[] R = new int[W];

        for(int i=0; i<W; ++i){
            arr[i]=Integer.parseInt(input[i]);
        }

        int cl=0, cr=0;

        for(int i=0; i<W; ++i){
            cl=L[i]=Math.max(cl,arr[i]);
            cr=R[W-i-1]=Math.max(cr,arr[W-i-1]);
        }

        int ans=0;
        for(int i=0; i<W; ++i){
            ans+=Math.max(Math.min(L[i],R[i])-arr[i], 0);
        }

        System.out.println(ans);
    }
}
