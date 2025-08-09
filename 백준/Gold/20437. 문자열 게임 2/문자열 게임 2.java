import java.io.*;
import java.util.*;

public class Main {
    static final int ALPHA = 26;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            String W = br.readLine().trim();
            int K = Integer.parseInt(br.readLine().trim());
            
            List<Integer>[] pos = new ArrayList[ALPHA];
            for (int i = 0; i < ALPHA; i++) pos[i] = new ArrayList<>();

            for (int i = 0; i < W.length(); i++) {
                char ch = W.charAt(i);
                pos[ch - 'a'].add(i);
            }

            int minLen = Integer.MAX_VALUE;
            int maxLen = -1;
            
            for (int c = 0; c < ALPHA; c++) {
                List<Integer> p = pos[c];
                if (p.size() < K) continue;

                for (int i = 0; i + K - 1 < p.size(); i++) {
                    int l = p.get(i);
                    int r = p.get(i + K - 1);
                    int len = r - l + 1;

                    if (len < minLen) minLen = len;
                    if (len > maxLen) maxLen = len;
                }
            }

            if (maxLen == -1) {
                out.append("-1\n");
            } else {
                out.append(minLen).append(" ").append(maxLen).append("\n");
            }
        }

        System.out.print(out);
    }
}
