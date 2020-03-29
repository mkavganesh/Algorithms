#include <bits/stdc++.h>
using namespace std;

const int N = 64; // Max # of vertices

vector<int> g[N+1];
int visited[N+1];
int parent[N+1];
int vertexCount, edgeCount;
int timeStamp;
int Entry[N+1];
int Exit[N+1];
vector<pair<int, int>> treeEdges, forwardEdges, crossEdges, backEdges;

void _reset_visited();
void _reset_parent();
void _dfs(int);
void dfs();
void dfs_timestamp();
void _dfs_timestamp(int);

void labelEdges() {
  /**
   * Utility to identify various types of edges in the graph
   */
  dfs_timestamp();
  for (int i = 1; i <= vertexCount; i++) {
    for (auto j : g[i]) {
      if (parent[j] == i && Entry[j] > Entry[i] && Exit[j] < Exit[i]) {
        treeEdges.push_back({i, j});
        continue;
      }
      if (parent[j] != i) {
        if (Entry[j] > Entry[i] && Exit[j] < Exit[i]) {
          forwardEdges.push_back({i, j});
          continue;
        }
        if (Entry[i] > Entry[j] && Exit[i] < Exit[j]) {
          backEdges.push_back({i, j});
          continue;
        }
      }
      crossEdges.push_back({i, j});
    }
  }
}

void dfs_timestamp() {
  /**
   * Time-stamping DFS traversal
   */
  _reset_visited(); _reset_parent();
  timeStamp = 0;
  for (int i = 1; i <= vertexCount; i++) {
    if (visited[i] == 0) _dfs_timestamp(i);
  }
}

void _dfs_timestamp(int i) {
  /**
   * Helper utility for time-stamping DFS traversla
   */
  visited[i] = 1;
  cout << i << " -> ";
  Entry[i] = ++timeStamp;
  for (auto j : g[i]) {
    if (visited[j] == 0) {
      parent[j] = i;
      _dfs_timestamp(j);
    }
  }
  Exit[i] = ++timeStamp;
}

void dfs() {
  /**
   * Simple DFS traversal
   */
  _reset_parent(); _reset_visited();
  for (int i = 1; i <= vertexCount; ++i) {
    if (visited[i] == 0) _dfs(i);
  }
}

void _dfs(int i) {
  /**
   * Helper function for the simple DFS traversal
   */
  visited[i] = 1;
  cout << i << " -> ";
  for (auto j : g[i]) {
    if (visited[j] == 0) {
      parent[j] = i;
      _dfs(j);
    }
  }
}

void _reset_visited() {
  /** 
   * Utility to rest the visited array
   */
  for (int i = 1; i <= vertexCount; ++i) visited[i] = 0;
}

void _reset_parent() {
  /**
   * Utility to reset the parent array
   */
  for (int i = 1; i <= vertexCount; ++i) parent[i] = -1;
}

int main() {
  cin >> vertexCount >> edgeCount;
  for (int i = 0; i < edgeCount; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }
}
