import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int arr[] = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int k=1;
        while(st.hasMoreTokens()){
            int t = Integer.parseInt(st.nextToken());
            int idx=0;
            int cnt=0;
            while(cnt!=t){
                if(arr[idx]==0) cnt++;
                idx++;
            }
            while(idx<N){
                if(arr[idx]==0){
                    arr[idx]=k++;
                    break;
                }
                idx++;
            }

        }
        for(int j: arr){
            System.out.print(j+" ");
        }
    }
}
