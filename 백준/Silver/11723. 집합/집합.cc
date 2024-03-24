#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin>>M;

    int bit=0;
    string s;
    int n;
    for(int i=0; i<M; ++i){
        cin>>s;
        if(s=="add"){
            cin>>n;
            bit|=(1<<n);
        }
        else if(s=="remove"){
            cin>>n;
            bit&=~(1<<n);
        }
        else if(s=="check"){
            cin>>n;
            if(bit&(1<<n)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(s=="toggle"){
            cin>>n;
            if(bit&(1<<n)){
                bit&=~(1<<n);
            }
            else{
                bit|=(1<<n);
            }
        }
        else if(s=="all"){
            bit = (1<<21) - 1;
        }
        else if(s=="empty"){
            bit =0;
        }
    }
}