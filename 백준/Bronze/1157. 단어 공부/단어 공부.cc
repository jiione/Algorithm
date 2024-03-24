#include<iostream>
#include<string>

using namespace std;

int countArr[26] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    for(int i=0; i<s.length(); ++i){
        char c = s[i];
        int t;
        if(c>='A' && c<='Z'){
            t = c-'A';
            countArr[t]++;
        }
        else if(c>='a' && c<='z'){
            t= c-'a';
            countArr[t]++;
        }
    }
    int max=0;
    int maxIdx;
    bool check = false;
    for(int i=0; i<26; ++i){
        if(countArr[i] > max){
            max = countArr[i];
            maxIdx = i;
            check=false;
        }
        else if(countArr[i] == max){
            check = true;
        }
    }

    if(check) cout<<'?'<<endl;
    else cout<<(char)(maxIdx+'A')<<endl;
}