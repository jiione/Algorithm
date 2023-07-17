#include<iostream>
#include<vector>

using namespace std;

vector<long long> v;
int N,M;

bool Check(long long value){
    int count = 0;
    for(long long num : v){
        count+=num/value;
    }

    return count>=M;
}

void BinarySearch(long long start, long long end){
    long long mid;
    long long idx = 1;
    while(end>=start){
        mid= (start+end)/2;
        if(Check(mid)){
            idx = max(idx,mid);
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    cout<<idx<<endl;
}

int main(){
    cin>>N>>M;

    v.resize(N);
    long long sum=0;
    for(int i =0;i<N;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int avg = sum/M;

    BinarySearch(1,avg);

    return 0;
}