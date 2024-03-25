#include<iostream>

using namespace std;

int line[20];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int tc;
    cin>>tc;

    for(int t=0; t<tc; ++t){
        int result =0;
        int test;
        cin>>test;
        cout<<test<<" ";
        for(int i=0; i<20; ++i){
            int h;
            cin>>h;
            line[i] = h;
            for(int j=i; j>0; j--){
                if(line[j-1] > line[j]){
                    result++;
                    int tmp = line[j];
                    line[j] = line[j-1];
                    line[j-1] = tmp;
                }
                else break;
            }
        }

        cout<<result<<'\n';
    }
}