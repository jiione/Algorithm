#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    queue<int> q;
    vector<bool> visited(n,false);
    int answer = 0;
    for(int k=0; k<n; ++k){
        if(!visited[k]){
            answer++;
            visited[k] = true;
            q.push(k);
        }
        while(!q.empty()){
            int m = q.front();
            q.pop();

            for(int i=0; i<n; ++i){
                int j = computers[m][i];
                if(j==1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        
    }
    return answer;
}