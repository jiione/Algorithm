#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dist[100001] ={0,};
int price[100001] ={0,};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int result = 0;
    cin>>N;

    for(int i=0;i<N-1;i++){
        cin>>dist[i];
    }

    for(int i=0; i<N;i++){
        cin>>price[i];
    }

    int max=1000000001;
    for(int i=0;i<N-1;i++){
        if(max>price[i]) max=price[i];
        result+=max*dist[i];
    }
    cout<<result;
    return 0;
}
