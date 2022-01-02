#include<iostream>
using namespace std;
long cal (long long n, long long p, long long q){
        if(n==0) return 1;
        return cal(n/p,p,q) + cal(n/q,p,q);
}
int main()
{
    long long n,p,q;
    cin>>n>>p>>q;
    cout<<cal(n,p,q)<<endl;
    return 0;
}