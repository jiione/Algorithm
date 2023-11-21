#include <string>
#include<iostream>
#include <vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    int size = board.size();
    for(int n : moves){
        int i=0;
        if(!board[size-1][n-1]) continue;
        while(!board[i][n-1]) ++i;
        int tmp = board[i][n-1];
        board[i][n-1]=0;
        if(!s.empty()){
            if(s.top() == tmp){
                s.pop();
                answer+=2;
            }
            else s.push(tmp);
        }
        else s.push(tmp);
    }
    return answer;
}