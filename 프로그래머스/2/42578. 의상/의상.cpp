#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> um;
    
    for(vector<string> vs : clothes){
        um[vs[1]]++;
    }
    
    for(auto it : um){
        answer*=(it.second+1);
    }
    
    answer--;
    return answer;
}