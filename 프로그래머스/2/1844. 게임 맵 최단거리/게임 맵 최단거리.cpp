#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size(); // 행의 개수
    int m = maps[0].size(); // 열의 개수

    // 방향 벡터 (상, 하, 좌, 우)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 방문 여부를 확인하는 배열
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // BFS를 위한 큐
    queue<pair<pair<int, int>, int>> q; // ((x, y), 거리)

    // 시작점 초기화
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int distance = q.front().second;
        q.pop();

        // 목적지에 도달했을 때
        if (x == n - 1 && y == m - 1) {
            return distance;
        }

        // 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 격자 내에 있고, 벽이 아니며, 방문하지 않은 위치일 때
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true; // 방문 표시
                q.push({{nx, ny}, distance + 1});
            }
        }
    }

    // 목적지에 도달할 수 없는 경우
    return -1;
}