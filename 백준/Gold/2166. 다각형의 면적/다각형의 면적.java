import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());

        long[] x = new long[N];
        long[] y = new long[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Long.parseLong(st.nextToken());
            y[i] = Long.parseLong(st.nextToken());
        }

      
        long sum = 0;
        for (int i = 0; i < N; i++) {
            int j = (i + 1) % N; 
            sum += x[i] * y[j] - y[i] * x[j];
        }

        double area = Math.abs(sum) / 2.0; 
        System.out.printf("%.1f\n", area); 
    }
}
