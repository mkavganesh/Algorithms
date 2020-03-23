#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define reset memset(visited, false, sizeof(visited))

const int MAXN = 64;
vector<int> g[MAXN + 1];
bool visited[MAXN+1];
bool cycle_detected = false;
int componentCount = 0;
int comp[MAXN+1];
int N, E;

/* DFS related algorithm implemented here */

void dfs(int i) {
  /* Basic DFS algorithm implemented here */
  visited[i] = true;
  cout << i << " -> ";
  for (auto j : g[i]) {
    if (!visited[j]) dfs(j);
  }
}

void iscyclic (int i, int parent = 0) {
  /**
   * Detecting cycles in given graph using DFS algorithm 
   * Caution: If the graph has node 0, use parent = -1 in the first call
  */
  visited[i] = true;
  for (auto j : g[i]) {
    if (visited[j] && j != parent) {
      cycle_detected = true;
      break;
    }
    if (!visited[j]) iscyclic(j, i);
  }
}

void isConnected (int i, int k, bool& flag) {
  /**
   * Checking whether vertex i and vertex k are connected or not
   * Initially, during the first call, flag is false
   * 
   * Algorithm: node 'i' is connected to node 'j' if either of the condition is satisfied:
   *  1. 'j' is successor of 'i'
   *  2. successor of 'i is connected to 'j'
   * 
   * Due to this recursive definition, DFS can be used to implement the routine
   */

  visited[i] = true;
  for (auto j : g[i]) {
    if (j == k) {
      flag = true;
      break;
    }
    if (!visited[j]) isConnected(j, k, flag);
  }
}

void _dfs_comp(int i) {
  /* Helper routine for dicover_components() */
  visited[i] = true;
  comp[i] = componentCount;
  for (auto j : g[i]) {
    if(!visited[j]) _dfs_comp(j);
  }
}

int discover_components() {
  /* Routine to discover the disconnected components and fill comp[]<int> accordingly */
  memset(comp, 0, sizeof(comp));
  for (int i = 1; i <= N; i++) {
    if (visited[i]) continue;
    ++componentCount;
    _dfs_comp(i);
  }
  return componentCount;
}

/* BFS related algorithm are implemented here */

void bfs(int i) {
  /* Simple BFS algorithm */
  visited[i] = true;
  cout << i << " -> ";
  queue<int> Q;
  Q.push(i);
  while (!Q.empty()) {
    auto j = Q.front();
    Q.pop();
    if (visited[j] == false) {visited[j] = true; cout << j << " -> ";}
    for (auto k : g[j]) {
      if (!visited[k]) Q.push(k);
    }
  }
}

signed main() {
#ifdef HP
  freopen("input.txt", "r", stdin);
#endif
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  reset;
  bfs(1);
  cout << "\n";
  return 0;
}
