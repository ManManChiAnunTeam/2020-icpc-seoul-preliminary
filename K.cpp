#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct node{
    int x, y, d;
    bool operator<(const node & t) const{
        return d > t.d;
    }
};

int N, M, board[1001][1001], vst[1001][1001], dist[1001][1001];

bool is_ok(int x, int y) {
    return (0 <= x) && (x < M) && (0 <= y) && (y < N);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M; // N 줄임
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    if (board[0][0] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    // dijkstra
    priority_queue<node, vector<node>> PQ;
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + M, INF);
    }
    dist[0][0] = board[0][0];
    PQ.push({0, 0, dist[0][0]});
    while (!PQ.empty()) {
        node u = PQ.top();
        PQ.pop();
        if (vst[u.y][u.x]) continue;
        vst[u.y][u.x] = true;
        //cout << u.x << ' ' << u.y << ' ' << u.d << endl;
        for (int i = 0; i < 4; i++) {
            int vx, vy;
            vx = u.x + dx[i];
            vy = u.y + dy[i];
            
            if (!is_ok(vx, vy)) continue;
            if (board[vy][vx] < 0) continue;

            if (dist[vy][vx] > u.d + board[vy][vx]) {
                dist[vy][vx] = u.d + board[vy][vx];
                PQ.push({vx, vy, u.d + board[vy][vx]});
                //cout << vx << ' ' << vy << endl;
            }
        }
    }
    if (dist[N-1][M-1] == INF) cout << -1 << '\n';
    else cout << dist[N-1][M-1] << '\n';
}