#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

#define MAX 2000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int> sol(N);

    for(int i=0; i<N;++i){
        cin>>sol[i];
    }

    sort(sol.begin(), sol.end());

    int left = 0;
    int right = N-1;

    int result= MAX;
    int rLeft = 0, rRight=N-1;

    while(left<right){
        int sum = sol[left] + sol[right];
        if(abs(sum) < abs(result)){
            result = sum;
            rLeft = left;
            rRight = right;
            if(sum == 0) break;
        }

        if(sum>=0){
            right--;
        }
        else left++;
    }

    cout<<sol[rLeft]<<" "<<sol[rRight]<<endl;

}