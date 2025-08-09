import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int h, idx;
        Pair(int h, int idx) { this.h = h; this.idx = idx; }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        StringTokenizer st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();
        Deque<Pair> stack = new ArrayDeque<>(); 

        for (int i = 1; i <= N; i++) {
            int h = Integer.parseInt(st.nextToken());

           
            while (!stack.isEmpty() && stack.peek().h < h) {
                stack.pop();
            }
            
            if (stack.isEmpty()) sb.append(0).append(' ');
            else sb.append(stack.peek().idx).append(' ');

            
            stack.push(new Pair(h, i));
        }

        System.out.println(sb.toString().trim());
    }
}
