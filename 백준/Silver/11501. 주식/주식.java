import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T  = Integer.parseInt(br.readLine());

        for(int i=0;i<T;i++){
            int N = Integer.parseInt(br.readLine());
            ArrayList<Integer> list = new ArrayList<>();
            long result = 0;

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<N;j++){
                list.add(Integer.parseInt(st.nextToken()));
            }
            int max = -1;
            for(int j=N-1;j>=0;j--){
                max = Math.max(max,list.get(j));
                result += max-list.get(j);
            }
            System.out.println(result);
        }
    }
}
