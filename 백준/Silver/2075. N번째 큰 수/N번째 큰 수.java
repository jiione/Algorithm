import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            while(st.hasMoreTokens()) {
                int num = Integer.parseInt(st.nextToken());
                pq.add(num);
                if(pq.size()>N) pq.poll();
            }
        }
        System.out.println(pq.poll());
    }
}
