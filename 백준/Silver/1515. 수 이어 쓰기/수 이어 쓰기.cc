#include<iostream>
#include<string>

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin>>s;
    int result=1;
    int idx=0;
    while(result){
        string ss = to_string(result);
        for(int i=0; i<ss.length();++i){
            if(s[idx]==ss[i]){
                idx++;
            }
        }
        if(idx==s.length()) break;

        result++;
    }

    cout<<result<<endl;
}