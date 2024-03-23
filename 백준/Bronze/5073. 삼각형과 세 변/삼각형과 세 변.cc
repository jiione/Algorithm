#include<iostream>
#include<vector>
#include<algorithm>

#define E "Equilateral\n"
#define I "Isosceles\n"
#define S "Scalene\n"
#define In "Invalid\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(3,1);
    while(true){
        cin>>v[0]>>v[1]>>v[2];
        if(v[0] == 0 && v[1] ==0 && v[2] == 0) break;

        sort(v.begin(),v.end());
        if(v[0] + v[1] <= v[2]) cout<<In;
        else if(v[0] == v[1] && v[1] == v[2]) cout<<E;
        else if(v[0]!=v[1] && v[1]!=v[2] && v[2]!=v[0]) cout<<S;
        else cout<<I;
    }

}