#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

int board[21][21];
bool check[22];
int N;
int ans = 10000000;

void dfs(int x, int cnt) {
    if (x == N / 2) {
        int start = 0;
        int link = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (check[i] == true && check[j] == true) {
                    start += board[i][j];
                    start += board[j][i];
                }
                else if (check[i] == false && check[j] == false) {
                    link += board[i][j];
                    link += board[j][i];
                }
            }
        }

        int tmp = abs(start - link);
        if (ans > tmp)ans = tmp;
        return;
    }

    for (int i = cnt; i <= N; i++) {
        check[i] = true;
        dfs(x + 1, i + 1);
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
   
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 1);
    cout << ans;

}
