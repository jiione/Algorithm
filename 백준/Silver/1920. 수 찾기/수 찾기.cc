#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> A,B;

void binary(int key){
    int start = 0;
    int end = A.size() - 1;
    int mid;

    while(end>=start){
        mid = (start+end)/2;
        if(A[mid] == key){
            cout<<1<<'\n';
            return;
        }
        else if(key>A[mid]){
            start= mid+1;
        }
        else end = mid-1;
    }

    cout<<0<<'\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    
    cin>>N;
    for (int i=0; i<N;i++){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    sort(A.begin(),A.end());

    cin>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        binary(tmp);
    }
    

}