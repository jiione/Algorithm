#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string,int> map;
    for(int i=0; i<name.size();++i){
        map[name[i]]=yearning[i];
    }
    vector<int> answer;
    
    for(vector<string> p : photo){
        int sum = 0;
        for(string s : p){
            sum += map[s];
        }
        answer.push_back(sum);
    }
    return answer;
}