#include<iostream>
#include<algorithm>

using namespace std;

bool check(int n, int val, vector<int> &arr){
    int idx=0;

    for(int i=0; i<arr.size(); ++i){
        if(arr[i]-val<=idx) idx=arr[i]+val;
        else return false;
    }
    if(idx<n) return false;
    return true;
}

int binary_search(int n, int m, vector<int> &arr){
    int right = n;
    int left = 1;
    int mid;
    int result=0;
    while(right>=left){
        mid = (right+left)/2;
        if(check(n,mid,arr)) {
            result = mid;
            right = mid-1;
        }
        else left=mid+1;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,m;
    cin>>n;
    cin>>m;

    vector<int> arr(m);
    for(int i=0; i<m; ++i){
        cin>>arr[i];
    }

    cout<<binary_search(n,m,arr)<<endl;


}