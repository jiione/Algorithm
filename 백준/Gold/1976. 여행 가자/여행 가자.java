import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int N, M;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        parent = new int[N+1];

        for(int i=1; i<=N; ++i){
            parent[i]=i;
        }

        String[] input;

        for(int i=0; i<N; ++i){
            input = br.readLine().split(" ");
            for(int j=0; j<N; ++j){
                if(Integer.parseInt(input[j])==1 && find(i+1)!=find(j+1)){
                    union(i+1,j+1);
                }
            }
        }

        input = br.readLine().split(" ");

        int pa = find(Integer.parseInt(input[0]));

        boolean answer = true;

        for(int i=1; i<M; ++i){
            if(pa!=find(Integer.parseInt(input[i]))){
                answer=false;
                break;
            }
        }

        System.out.println(answer?"YES":"NO");


    }

    static void union(int a, int b){
        
        a=find(a);
        b=find(b);

        if(a>b){
            parent[a]=find(b);
        }
        else{
            parent[b]=find(a);
        }
    }

    static int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }

}
