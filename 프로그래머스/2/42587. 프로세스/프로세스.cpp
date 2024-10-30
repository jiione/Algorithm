#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int> > q;
    priority_queue<int> pq;
    int answer = 1;
    
    for(int i=0; i<priorities.size(); ++i){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(true){
        if(q.front().first == pq.top()){
            if(q.front().second == location){
                return answer;
            }
            
            pq.pop();
            q.pop();
            
            answer++;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    
    
    return answer;
}