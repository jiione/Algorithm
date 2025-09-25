import java.io.*;
import java.util.*;

public class Main {

    static int N,M;
    static ArrayList<Edge>[] graph;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input;

        input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt((Edge e) -> e.dist));
        int[] dist = new int[N+1];
        Arrays.fill(dist,100_000_000);

        graph = new ArrayList[N+1];
        for(int i=1; i<=N; ++i){
            graph[i] = new ArrayList<>();
        }

        for(int i=0; i<M; ++i){
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int c = Integer.parseInt(input[2]);

            graph[a].add(new Edge(b,c));
            graph[b].add(new Edge(a,c));
        }

        pq.offer(new Edge(1,0));
        dist[1] = 0;


        while(!pq.isEmpty()){
            Edge e = pq.poll();
            int cv = e.v;
            int cd = e.dist;

            for(Edge ne : graph[cv]){
                int nv = ne.v;
                int nd = cd + ne.dist;

                if(nd<dist[nv]){
                    dist[nv] = nd;
                    pq.offer(new Edge(nv,nd));
                }
            }
        }

        System.out.println(dist[N]);
    }
}

class Edge {
    int v;
    int dist;

    Edge(int v, int dist){
        this.v = v;
        this.dist = dist;
    }
}
