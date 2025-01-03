import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] line = new String[N];
        List<String> result = new ArrayList<>();
        Set<Character> set = new HashSet<>();

        //문장 저장
        for (int i = 0; i < N; i++) {
            line[i] = br.readLine();
        }

        for(int i = 0; i < N; i++){
            boolean flag = false;
            String[] words = line[i].split(" ");

            //첫 단어 확인
            for(int j = 0; j < words.length; j++){
                char shortCut = Character.toLowerCase(words[j].charAt(0));
                if(!set.contains(shortCut)){
                    set.add(shortCut);
                    words[j] = "[" + words[j].charAt(0) + "]" + words[j].substring(1);
                    flag = true;
                    break;
                }
            }

            for(int j = 0; j < words.length; j++){
                if(!flag){
                    for(int k = 0; k < words[j].length(); k++){
                        char ch = Character.toLowerCase(words[j].charAt(k));
                        if(!set.contains(ch)){
                            set.add(ch);
                            flag = true;
                            words[j] = words[j].substring(0, k) + "[" +words[j].charAt(k) + "]" +words[j].substring(k + 1);
                            break;
                        }
                    }
                }
            }

            result.add(String.join(" ", words));
        }

        for(String s : result){
            System.out.println(s);
        }
    }
}
