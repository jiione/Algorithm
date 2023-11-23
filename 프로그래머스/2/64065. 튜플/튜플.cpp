#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

vector<int> solution(string s) {
    
    vector<vector<int>> v;
    int idx = 0;
    int val = 0;
    
    v.push_back(vector<int>{});
    for(int i=2; i<s.length()-1; i++){
        if(s[i]-'0'<=9 && s[i]-'0'>=0){
            val*=10;
            val+=s[i]-'0';
        }
        else if(s[i] == ',' && s[i-1] != '}' || s[i]=='}' && s[i+1] == '}'){
            v[idx].push_back(val);
            val=0;
        }
        else if(s[i] == '}' && s[i+1] != '}'){
            v[idx].push_back(val);
            val=0;
            v.push_back(vector<int>{});
            idx+=1;
        }
    
    }
    
    sort(v.begin(),v.end(),[](vector<int>v1, vector<int>v2){return v1.size()<v2.size();});
    for(int i =0 ; i<v.size();++i){
        sort(v[i].begin(),v[i].end());
    }

    
    vector<int> answer;
    answer.push_back(v[0][0]);
    for(int i=1; i<v.size(); ++i){
        vector<int> diff;
        set_difference(v[i].begin(),v[i].end(),v[i-1].begin(),v[i-1].end(),back_inserter(diff));
      
        answer.push_back(diff[0]);
    }
    
    
    return answer;
}