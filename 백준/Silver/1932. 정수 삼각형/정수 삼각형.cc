#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

int tree[501][501];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            int n;
            cin >> n;
            tree[i][j] = max(tree[i - 1][j - 1], tree[i - 1][j]) + n;
        }
    }

    int max = -100;
    for (int i = 1; i <= N; i++) {
        if (max < tree[N][i])max = tree[N][i];
    }
    cout << max;
}