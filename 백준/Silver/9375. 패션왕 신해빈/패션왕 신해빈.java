import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < T; i++) {
            Map<String, Integer> map = new HashMap<>();
            int n = Integer.parseInt(br.readLine());
            for (int j = 0; j < n; j++) {
                String[] words = br.readLine().split(" ");

                if (map.containsKey(words[1])) {
                    map.put(words[1], map.get(words[1]) + 1);
                } else map.put(words[1], 1);
            }

            int result = 1;
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                result *= entry.getValue()+1;
            }
            result--;
            sb.append(result + "\n");
        }

        System.out.println(sb);
    }
}
