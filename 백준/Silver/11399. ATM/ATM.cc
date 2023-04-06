#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int > arr;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int cnt=0;

    cin>>N;
    
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());

    int sum=0;
    int tSum=0;
    for(int i=0;i<N;i++){
        tSum+=arr[i];
        sum+=tSum;
    }
    cout<<sum;
    return 0;
}
