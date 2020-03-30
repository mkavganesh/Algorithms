/* Finding any spanning tree of undirected unweighted graph */

#include <bits/stdc++.h>
using namespace std;

const int N = 64; // max # of vertices
int vertexCount, edgeCount;
vector<int> g[N+1];
int visited[N+1];
vector<pair<int, int>> st; // contains edges that form a spanning tree

void _reset_visited();

void dfs(int i) {
  visited[i] = 1;
  for (auto j : g[i]) {
    if (visited[j] == 0) {
      st.push_back({i, j});
      dfs(j);
    }
  }
}

void _reset_visited() {
  for (int i = 1; i <= vertexCount; i++) visited[i] = 0;
}

int main() {
  cin >> vertexCount >> edgeCount;
  for (int i = 0; i < edgeCount; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  _reset_visited();
  dfs(1);
  cout << "Following edges form the spanning tree of given graph\n";
  for (auto i : st) {
    cout << "(" << i.first << ", " << i.second << "), ";
  }
  cout << "\n";
  return 0;
}
