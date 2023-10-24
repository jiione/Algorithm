#include <string>
#include<stdlib.h>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2);
    int y = park.size();
    int x = park[0].length();
    for(int i=0; i<y;++i){
        for(int j=0;j<x;++j){
            if(park[i][j] == 'S'){
                park[i][j] = 'O';
                answer[0] = i;
                answer[1] = j;
                break;
            }
        }
    }
    
    for(string cmd: routes){
        int n = cmd[2]-'0';
        int ty= answer[0];
        int tx= answer[1];
        if(cmd[0] == 'E'){
            if(tx+n<x){
                answer[1] +=n;
                for(int i=1; i<=n; ++i){
                    if(park[ty][tx+i]=='X'){
                        answer[1] = tx;
                        break;
                    }
                } 
            }
        }
        else if(cmd[0] == 'N'){
            if(ty-n>=0){
                answer[0] -=n;
                for(int i=1; i<=n; ++i){
                    if(park[ty-i][tx]=='X'){
                        answer[0] = ty;
                        break;
                    }
                } 
            }
        }
        else if(cmd[0] == 'W'){
            if(tx-n>=0){
                answer[1] -=n;
                for(int i=1; i<=n; ++i){
                    if(park[ty][tx-i]=='X'){
                        answer[1] = tx;
                        break;
                    }
                } 
            }
        }
        else if(cmd[0] == 'S'){
            if(ty+n<y){
                answer[0] +=n;
                for(int i=1; i<=n; ++i){
                    if(park[ty+i][tx]=='X'){
                        answer[0] = ty;
                        break;
                    }
                } 
            }
        }
                
    }
    
    return answer;
}