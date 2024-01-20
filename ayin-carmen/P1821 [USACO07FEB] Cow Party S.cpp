#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;

const int maxn = 1005;
const int maxm = 100005;

int n, m, s, ans[maxn], sum;

struct Edge {
    int nxt, to, w;
} e[maxm];

int head[maxn], cnt;

void addEdge(int u, int v, int w) {
    e[++cnt].nxt = head[u];
    e[cnt].w = w;
    e[cnt].to = v;
    head[u] = cnt;
}

int dis[maxn], vis[maxn];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
}

int main() {
    int u[maxm], v[maxm], w[maxm];
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        addEdge(u[i], v[i], w[i]);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) ans[i] = dis[i];
    cnt = 0;
    memset(dis, 0, sizeof(dis));
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) addEdge(v[i], u[i], w[i]);
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        ans[i] += dis[i];
        sum = max(sum, ans[i]);
    }
    cout << sum;
    return 0;
}
