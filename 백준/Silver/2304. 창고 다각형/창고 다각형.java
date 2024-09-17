import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class Loc{
    private static int max = Integer.MIN_VALUE;
    private int x;
    private int y;

    Loc(int x, int y){
        this.x = x;
        this.y = y;
    }

    static int getMax(){
        return max;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int x){
        this.x = x;
    }
    void setY(int y){
        this.y = y;
    }
    static void setMax(int m){
        max = m;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Loc> locs = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            locs.add(new Loc(x, y));

            if(y>Loc.getMax()) Loc.setMax(y);
        }

        Collections.sort(locs, Comparator.comparing(Loc::getX));
        int lx=locs.get(0).getX();
        int tx =locs.get(0).getX();
        int rx=locs.get(locs.size()-1).getX();
        int bar = locs.get(0).getY();
        int result = 0;
        int i=0;
        //왼쪽
        while(true){
            if(locs.get(i).getY() > bar){
                result+=bar*(locs.get(i).getX()-tx);
                tx=locs.get(i).getX();
                bar=locs.get(i).getY();
            }
            lx = locs.get(i).getX();
            if(locs.get(i).getY()==Loc.getMax()) break;
            ++i;
        }
        bar = locs.get(locs.size()-1).getY();
        tx=locs.get(locs.size()-1).getX();
        i=locs.size()-1;
        //오른쪽
        while(true){
            if(locs.get(i).getY() > bar){
                result+=bar*(tx-locs.get(i).getX());
                tx=locs.get(i).getX();
                bar=locs.get(i).getY();
            }
            rx = locs.get(i).getX();
            if(locs.get(i).getY()==Loc.getMax()) break;
            --i;
        }

        result+=(rx-lx+1)*Loc.getMax();
        System.out.println(result);

    }
}
