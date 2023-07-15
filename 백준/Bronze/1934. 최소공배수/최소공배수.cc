#include<iostream>

using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        cout<<a*b/gcd(a,b)<<'\n';
    }
}