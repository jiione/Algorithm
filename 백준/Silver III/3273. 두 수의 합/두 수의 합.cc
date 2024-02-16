#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;

    cin>>N;
    vector<int> graph(N);

    for(int i=0; i<N; ++i){
        cin>>graph[i];
    }

    sort(graph.begin(),graph.end());

    int start = 0;
    int end = N-1;

    int target;

    cin>>target;
    int result = 0;
    while(start<end){
        if(start == end){
            end++;
            continue;
        }

        int sum = graph[start] + graph[end];
        if(sum == target){
            result++;
            end--;
            start++;
        }
        else if(sum < target) start++;
        else if(sum > target) end--; 
    }
    cout<<result<<endl;
}