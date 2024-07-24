import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; ++i){
            int input = Integer.parseInt(br.readLine());
            if(input == 0){
                if(pq.isEmpty()) System.out.println(0);
                else{
                    System.out.println(pq.poll());
                }
            }
            else pq.add(input);
        }

    }
}

