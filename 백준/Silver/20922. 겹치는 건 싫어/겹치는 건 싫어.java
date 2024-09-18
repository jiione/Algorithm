import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int K = Integer.parseInt(str[1]);

        int arr[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        HashMap<Integer, Integer> map = new HashMap<>();

        int si=0, ei=0;
        int max=0;
        int line=0;
        while(ei<N){
            if(map.containsKey(arr[ei])){
                if(map.get(arr[ei])<K){
                    map.put(arr[ei],map.get(arr[ei])+1);
                    line++;
                    ei++;
                }
                else{
                    map.put(arr[si],map.get(arr[si])-1);
                    si++;
                    line--;
                }
            }
            else{
                map.put(arr[ei],1);
                line++;
                ei++;
            }
            max=Math.max(max,line);
        }
        System.out.println(max);
    }
}
