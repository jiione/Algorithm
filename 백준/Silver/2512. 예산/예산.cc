#include<iostream>
#include<vector>

using namespace std;


int binary_search(int max,int budget, vector<int>& arr){
    int min=0;
    int mid;
    int result;
    while(min<=max){
        mid=(min+max)/2;
        int sum=0;
        for(int i=0; i<arr.size(); ++i){
            sum+= arr[i]>mid?mid:arr[i];
        }
        if(sum>budget){
            max=mid-1;
        }
        else {
            min=mid+1;
            result=mid;
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int max=0;
    vector<int> arr(N);
    for(int i=0; i<N;++i){
        cin>>arr[i];
        max = max<arr[i]?arr[i]:max;
    }

    int budget;

    cin>>budget;

    cout<< binary_search(max,budget,arr)<<endl;



}