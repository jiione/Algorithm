import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static String S;
    static boolean isFinish=false;
    static int answer=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        StringBuilder T = new StringBuilder();
        T.append(br.readLine());


        dfs(T);

        System.out.println(answer);
    }

    static void dfs(StringBuilder T){
        if(isFinish) return;

        if(S.length()==T.length()){
            if(T.toString().equals(S)){
                answer=1;
                isFinish=true;
            }
            return;
        }
        if(T.charAt(0) == 'B' && T.charAt(T.length() - 1) == 'A'){
            StringBuilder addA = new StringBuilder(T);
            addA.deleteCharAt(T.length() - 1);

            StringBuilder addBAndReverse = new StringBuilder(T);
            addBAndReverse.deleteCharAt(0).reverse();

            dfs(addA);
            dfs(addBAndReverse);

        }
        else if(T.charAt(0) == 'B'){
            StringBuilder addBAndReverse = new StringBuilder(T);
            addBAndReverse.deleteCharAt(0).reverse();

            dfs(addBAndReverse);
        }
        else if(T.charAt(T.length() - 1) == 'A'){
            StringBuilder addA = new StringBuilder(T);
            addA.deleteCharAt(T.length() - 1);

            dfs(addA);
        }


    }
}
