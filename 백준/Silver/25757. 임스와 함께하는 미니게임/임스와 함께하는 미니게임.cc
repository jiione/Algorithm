#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(){
    set<string> s;

    int N;
    char c;
    cin>>N>>c;

    int pers=0;

    if(c=='Y') pers=1;
    else if(c=='F') pers=2;
    else if(c=='O') pers=3;

    string str;

    for(int i=0; i<N; ++i){
        cin>>str;
        s.insert(str);
    }

    cout<<s.size()/pers<<endl;
}