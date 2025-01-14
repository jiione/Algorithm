import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        int B = Integer.parseInt(line[2]);

        int[][] board = new int[N][M];

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for(int i =0;i<N;i++){
            String[] str = br.readLine().split(" ");
            for(int j=0;j<M;j++){
                board[i][j] = Integer.parseInt(str[j]);
                if(board[i][j] < min){
                    min = board[i][j];
                }
                if(board[i][j] > max){
                    max = board[i][j];
                }
            }
        }

        int time=Integer.MAX_VALUE;
        int height=Integer.MIN_VALUE;
        for(int i =min;i<=max;i++){
            int tB = B;
            int t = 0;
            for(int j=0;j<N;j++){
                for(int k=0;k<M;k++){
                    if(board[j][k]>i){
                        t+=2*(board[j][k]-i);
                        tB+=board[j][k]-i;
                    }
                    else if(board[j][k]<i){
                        t+=1*(i-board[j][k]);
                        tB-=i-board[j][k];
                    }
                }
            }

            if(tB>=0){
                if(time>t){
                    time=t;
                    height=i;
                }
                else if(time==t){
                    height=Math.max(height,i);
                }
            }
        }

        System.out.println(time + " " +height);
    }
}
