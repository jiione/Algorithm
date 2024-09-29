import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] arr = br.readLine().toCharArray();

        int n = arr.length;

        int cnt=0;
        for(int i=0; i<n; ++i)
            if(arr[i]=='a') cnt++;

        int si = 0;
        int ei = cnt-1;
        int result = Integer.MAX_VALUE;
        int tmp=0;

        for(int i=0; i<cnt; ++i){
            if(arr[i]=='b') tmp++;
        }

        result = Math.min(result,tmp);

        while(si<n){
            if(arr[si++] == 'b') tmp--;
            if(arr[++ei%n] == 'b') tmp++;

            result = Math.min(result,tmp);
        }

        System.out.println(result);
    }
}
