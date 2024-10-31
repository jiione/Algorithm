#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i : scoville){
        pq.push(i);
    }
    
    int answer = 0;
    
    while(pq.top() < K){
        if(pq.size()<2) return -1;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + (b*2);
        pq.push(c);
        answer++;
    }
    return answer;
}