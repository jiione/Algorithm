#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

int rgb[1001][3] = { 0, };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + r;
        rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + g;
        rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + b;
    }

    cout << min(rgb[N][0], min(rgb[N][1], rgb[N][2]));
}