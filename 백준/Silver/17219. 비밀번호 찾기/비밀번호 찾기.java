import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int [] cmd = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        Map<String, String> map = new HashMap<>();

        for(int i=0; i<cmd[0]; ++i){
            String [] words = br.readLine().split(" ");
            map.put(words[0], words[1]);
        }

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<cmd[1]; ++i){
            String email = br.readLine();
            sb.append(map.get(email)+"\n");
        }

        System.out.println(sb);
    }
}
