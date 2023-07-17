#include<iostream>
#include<vector>

using namespace std;

int N;
long long M;
vector<long long> v;

long long LengthSum(long long value){
    long long sum =0;
    for(auto i : v){
        sum += i>value?i-value:0;
    }

    return sum;
}

void BinarySearch(long long end){
    long long start = 0, mid = 0;
    long long result;
    
    while(end>=start){
        mid = (end+start)/2;
        long long sum=LengthSum(mid);

        if (sum<M){
            end=mid-1;
        }
        else{
            result = mid;
            start = mid+1;
        }
    }

    cout<<result<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    long long maximum=0;

    v.resize(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
        maximum=max(maximum,v[i]);
    }

    BinarySearch(maximum);
}