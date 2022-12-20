#include<iostream>
using namespace std;
int main(){
    int a,b,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<"Case #"<<i<<": "<<a+b<<endl;
    }
}