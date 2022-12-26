#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str;

    cin>>str;
    map<string,int> m;
    int n=1;
    while(n<=str.length()){
        for(int i=0;i<=(str.length()-n);i++){
            string tmp=str.substr(i,n);
            m[tmp]++;
        }
        n++;
    }
    cout<<m.size()<<'\n';
}