#include<iostream>
#include<vector>

using namespace std;

int getParent(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = getParent(parent[x], parent);

}

void unionParent(int a, int b, vector<int>& parent){
    a = getParent(a, parent);
    b = getParent(b, parent);

    if(a>b) parent[a]=b;
    else parent[b]=a;
}

void check(int a, int b, vector<int> &parent){
    a = getParent(a,parent);
    b= getParent(b,parent);

    if(a==b){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin>>n>>m;

    vector<int> parent(n+1);

    for(int i=1; i<=n; ++i) parent[i] = i;

    for(int i=0;i<m;++i){
        int c,a,b;

        cin>>c>>a>>b;

        if(c==0){
            unionParent(a,b,parent);
        }
        else if(c==1){
            check(a,b,parent);
        }
    }
}