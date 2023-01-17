#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

long w[21][21][21];

int dp(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return dp(20, 20, 20);
    else if (w[a][b][c] != 0) return w[a][b][c];
    else if(a<b&&b<c) w[a][b][c] = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);
    else w[a][b][c] = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);

    return w[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << endl;
    }
   

}