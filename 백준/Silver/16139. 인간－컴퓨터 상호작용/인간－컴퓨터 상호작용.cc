#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin>> S;
    vector<vector<int> > v(26, vector<int>(S.length()));

    v[(int)(S[0]-'a')][0] = 1;

    for(int i=1;i<S.length();i++){
        char tmp = 'a';
        tmp = S[i] - tmp;
        v[(int)tmp][i]++;
        for(int j=0;j<26;j++){
            v[j][i]+=v[j][i-1];
        }
    } 
    int q;

    cin>> q;
    char a;
    int b,c;
    for(int i=0; i< q;i++){
        cin>>a>>b>>c;
        int tmp = (int)(a-'a');
        if(b!=0) cout<<v[tmp][c]-v[tmp][b-1]<<'\n';
        else cout<<v[tmp][c]<<'\n';
    }

    return 0;
}
