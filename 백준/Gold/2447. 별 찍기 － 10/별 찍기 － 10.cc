#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void star(int i, int j, int num)
{
    if((i / num)%3 == 1 && (j / num)%3 == 1) {
        cout << ' ';
    }
    else
    {
        if(num / 3 == 0)
            cout <<'*';
        else
            star(i,j,num/3);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            star(i,j,N);
        }
        cout<<'\n';
    }
    return 0;
}