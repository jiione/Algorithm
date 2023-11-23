#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool visited[8];
set<string> s; //중복 포함 x

void DFS(vector<string>& user_id, vector<string>& banned_id, int index) {
    if (index == banned_id.size()) {
        string st;
        for (int i = 0; i < user_id.size(); i++) {
            //제재아이디 조합
            if (visited[i] == true)
                st += user_id[i];
        }
        s.insert(st); //추가
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        //이전 탐색한 경우
        if (visited[i] == true)
            continue;
        //아이디 길이가 다를 경우
        if (user_id[i].size() != banned_id[index].size())
            continue;
        
        bool check = true;
        for (int j = 0; j < user_id[i].size(); j++) {
            if (banned_id[index][j] == '*') {
                continue;
            }
            //같지 않을 경우 false
            if (banned_id[index][j] != user_id[i][j]) {
                check = false;
                break;
            }
        }
        if (check == true) {
            visited[i] = true; //방문
            DFS(user_id, banned_id, index + 1);
            visited[i] = false; //방문 x
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    DFS(user_id, banned_id, 0);
    answer = s.size();
    return answer;
}