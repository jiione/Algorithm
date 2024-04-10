#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    int result=0;

    for(int i=0; i<s.length(); ++i){
        if(s[i]=='P'){
            for(int j=i-k; j<=i + k; j++) {
                if(0 <= j && j < n && s[j] == 'H') {
                    s[j]='-';
                    result++;
                    break;
                }
            }
        }   
    }

    cout<<result<<endl;


}