#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    vector<int> v;
    while(true){
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0)break;
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.rbegin(),v.rend());
        if(v[0]*v[0]==v[1]*v[1]+v[2]*v[2]) cout<<"right\n";
        else cout<<"wrong\n";
    }
}