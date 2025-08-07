import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int T;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int t=0; t<T; ++t){
            String str = br.readLine();
            int start=0;
            int end=str.length()-1;
            int answer=0;

            while(end>=start){
                if(str.charAt(start)!=str.charAt(end)){
                    if(check(str,start+1,end) || check(str,start,end-1)){
                        answer=1;
                    }
                    else {
                        answer=2;
                    }

                    break;
                }

                start++;
                end--;
            }

            sb.append(answer).append('\n');
        }

        System.out.println(sb);

    }

    static boolean check(String str, int start, int end){
        while(end>start){
            if(str.charAt(start++) != str.charAt(end--)) return false;
        }

        return true;
    }


}
