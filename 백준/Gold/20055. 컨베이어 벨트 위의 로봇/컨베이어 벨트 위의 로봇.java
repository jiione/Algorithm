import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N,K;
    static boolean[] robots;
    static int[] belts;
    static int answer=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input;
        input = br.readLine().split(" ");

        N=Integer.parseInt(input[0]);
        K=Integer.parseInt(input[1]);
        robots = new boolean[N*2];
        belts = new int[N*2];

        input = br.readLine().split(" ");

        for(int i=0; i<2*N; ++i){
            belts[i] = Integer.parseInt(input[i]);
        }

        int cnt=0;

        while(cnt<K){
            //step01
            answer++;
            boolean temp = robots[N*2-1];
            int temp2 = belts[N*2-1];
            for(int i=N*2-1; i>0; --i){
                robots[i]=robots[i-1];
                belts[i]=belts[i-1];
            }
            robots[0]=temp;
            belts[0] = temp2;
            robots[N-1]=false;

            //step02
            for(int i=N*2-1; i>0; --i){
                if(robots[i]&& !robots[(i+1)%(N*2)] &&belts[(i+1)%(N*2)]>0){
                    robots[(i+1)%(N*2)] = true;
                    robots[i]=false;

                    belts[(i+1)%(N*2)]--;

                    if(belts[(i+1)%(N*2)]==0){
                        cnt++;
                    }
                }
            }
            robots[N-1]=false;

            //System.out.println(3);
            //step03
            if(belts[0]>0 && !robots[0]){
                robots[0]=true;
                belts[0]--;
                if(belts[0]==0) cnt++;
            }
        }

        System.out.println(answer);

    }


}
