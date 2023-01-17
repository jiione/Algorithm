#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

long arr[41];
int cnt = 0, cnt2 = 0;

long fib(int n) {
    if (n == 1 || n == 2) {
        cnt++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
long fibonacci(int n) {
    arr[1] = arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        cnt2++;
    }
    return arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    fib(N);
    fibonacci(N);
    cout << cnt << " " << cnt2 << endl;
   
    

}