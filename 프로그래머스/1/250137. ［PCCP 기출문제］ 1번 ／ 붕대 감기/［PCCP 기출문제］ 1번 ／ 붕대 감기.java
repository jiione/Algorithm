import java.util.*;
class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int time = 0;
        int t=bandage[0];
        int x = bandage[1];
        int y= bandage[2];
        
        int answer = health;
        
        for(int i=0; i<attacks.length; ++i){
            int currentTime = attacks[i][0] - 1;
            int timeDis = currentTime - time;
            answer += timeDis * x;
            if(timeDis >= t){
                answer += timeDis/t*y;
            }
            answer = Math.min(answer,health);
            answer -= attacks[i][1];
            if(answer<=0){
                answer = -1;
                break;
            }
            time = currentTime + 1;
        }
        return answer;
    }
}