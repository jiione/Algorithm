#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> map;
    for(int i=0; i<players.size(); ++i){
        map[players[i]]=i;
    }
    for(int i=0; i<callings.size();++i){
        int idx = map[callings[i]]--;
        map[players[idx-1]]++;
        string tmp = players[idx-1];
        players[idx-1] = players[idx];
        players[idx] = tmp;
    }
    return players;
}