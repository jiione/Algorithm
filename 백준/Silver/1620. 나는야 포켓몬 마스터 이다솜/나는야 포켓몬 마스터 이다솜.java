import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N,M;
        String[] input = br.readLine().split(" ");

        N=Integer.parseInt(input[0]);
        M=Integer.parseInt(input[1]);

        Map<Integer,String> intToString = new HashMap<>();
        Map<String,Integer> StringToInt = new HashMap<>();

        for(int i=1; i<=N; ++i){
            String str = br.readLine();
            StringToInt.put(str,i);
            intToString.put(i,str);
        }

        StringBuilder sb = new StringBuilder();

        for(int i=0;i<M;++i){
            String str = br.readLine();
            if(str.matches("\\d+")){
                sb.append(intToString.get(Integer.parseInt(str))).append('\n');
            }
            else sb.append(StringToInt.get(str)).append('\n');
        }

        System.out.println(sb);


    }


}
