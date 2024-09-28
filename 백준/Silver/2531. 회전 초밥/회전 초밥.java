import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] check = new int[d+1];
        int[] belt = new int[n];

        for (int i = 0; i < n; i++) {
            belt[i] = Integer.parseInt(br.readLine());
        }
        int result = 0;
        int cnt = 0;
        for(int i=0; i<k;++i){
            if(check[belt[i]] == 0){
                cnt++;
            }
            check[belt[i]]++;
        }
        if(check[c] == 0) result = Math.max(result, cnt+1);
        else result = Math.max(result, cnt);

        int si = 0;
        int ei = k-1;
        final int MOD = n;

        while(si<n){
            if(check[belt[si]] == 1){
                cnt--;
            }
            check[belt[si]]--;
            si++;
            ei++;
            if(check[belt[ei%MOD]] == 0){
                cnt++;
            }
            check[belt[ei%MOD]]++;

            if(check[c] == 0) result = Math.max(result, cnt+1);
            else result = Math.max(result, cnt);

        }

        System.out.println(result);
    }
}
