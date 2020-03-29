/* Implementation of Directed Acyclic Graphs */

#include <bits/stdc++.h>
using namespace std;

const int N = 64; // Max # of vertices
vector<int> g[N+1];
vector<int> l[N+1]; // contains nodes for given level
int visited[N+1];
int parent[N+1];
int vertexCount, edgeCount;
int t1, t2; // time stamps
int Entry[N+1];
int Exit[N+1];
vector<pair<int ,int>> levelExit; // same as Exit
int level[N+1];

void _reset_visited();
void _reset_parent();
void dfs();
void _dfs(int);
void levelling();

bool cmp(pair<int, int>& a, pair<int, int>& b) {
  return a.second < b.second;
}

void levelling() {
  /**
   * Utility to determine levels of each node in the graph
   */
  dfs();
  sort(levelExit.begin(), levelExit.end(), cmp);
  for (auto i : levelExit) {
    int mx = -1;
    for (auto j : g[i.first]) {
      if (level[j] > mx) mx = level[j];
    }
    level[i.first] = mx + 1;
  }
  for (int i = 1; i <= vertexCount; i++) {
    l[level[i]].push_back(i);
  }
}

void dfs() {
  /**
   * Utility to perform DFS traversal with timestamping
   */
  t1 = 0, t2 = 0;
  _reset_parent(); _reset_visited();
  for (int i = 1; i <= vertexCount; i++) {
    if (visited[i] == 0) _dfs(i);
  }
  cout << "\n";
}

void _dfs(int i) {
  /**
   * Helper function for dfs()
   */
  visited[i] = 1;
  Entry[i] = ++t1;
  cout << i << " -> ";
  for (auto j : g[i]) {
    if (visited[j] == 0) {
      parent[j] = i;
      _dfs(j);
    }
  }
  Exit[i] = ++t2;
  levelExit.push_back({i, t2});
}

void _reset_visited() {
  for (int i = 1; i <= vertexCount; i++) visited[i] = 0;
}

void _reset_parent() {
  for (int i = 1; i <= vertexCount; i++) parent[i] = -1;
}

int main() {
  #ifdef HP
  freopen("input.txt", "r", stdin);
  #endif
  cin >> vertexCount >> edgeCount;
  for (int i = 0; i < edgeCount; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }
  levelling();
  for (int i = 1; i <= vertexCount; i++) {
    printf("Level of node%3d is %3d\n", i, level[i]);
  }
}
