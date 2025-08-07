import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int[] seq;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        seq=new int[n];
        dp=new int[n];
        String[] input = br.readLine().split(" ");

        for(int i=0; i<n; ++i){
            seq[i] = Integer.parseInt(input[i]);
            dp[i]=1;
        }

        int max=1;
        int idx=0;

        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(seq[i]>seq[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;

                    if(dp[i]>max){
                        max=dp[i];
                        idx=i;
                    }
                }
            }
        }

        Deque<Integer> st = new ArrayDeque<>();
        st.push(seq[idx]);
        int len=max-1;
        int prev = seq[idx];

        for(int i=idx-1; i>=0; --i){
            if(dp[i]==len && seq[i]<prev){
                len--;
                prev=seq[i];
                st.push(prev);
            }
        }

        StringBuilder answer = new StringBuilder();
        answer.append(max).append('\n');
        while(!st.isEmpty()){
            answer.append(st.pop()).append(' ');
        }

        System.out.println(answer);
        
    }


}
