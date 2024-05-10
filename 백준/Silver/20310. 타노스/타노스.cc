#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int one=0,zero=0;

    for(auto c : s){
        if(c=='0')zero++;
        else one++;
    }

    int hz = zero/2;
    int ho = one/2;
    
    while(hz!=zero){
        int idx=s.rfind('0');
        if(idx != string::npos){
            s.erase(idx,1);
            zero--;
        }
    }

    while(ho!=one){
        int idx=s.find('1');
        if(idx != string::npos){
            s.erase(idx,1);
            one--;
        }
    }

    cout<<s<<endl;
}