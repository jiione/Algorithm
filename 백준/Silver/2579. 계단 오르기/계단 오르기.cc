#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[301];
    int N;
    cin >> N;
    int tmp;
    cin >> tmp;
    arr[1] = tmp;
    cin >> tmp;
    arr[2] = tmp + arr[1];
    int tmp2 = tmp;
    
    cin >> tmp;
    arr[3] = max(arr[1], tmp2) + tmp;

    tmp2 = tmp;
    

    for (int i = 4; i <= N; i++) {
        cin >> tmp;
        arr[i] = max(arr[i - 2] + tmp, arr[i - 3] + tmp2 + tmp);
        tmp2 = tmp;
    }

    cout << arr[N];
    
}