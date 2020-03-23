#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define reset memset(visited, false, sizeof(visited))

/**
 * Global variables defined in this module:
 * N <int>: number of vertices in the graph
 * E <int>: number of edges in the graph
 * visited[] <bool>: array used for dfs and related algorithms, needs to be reset before every use
 * cycle_detected <bool>: stores whether given graph contains cycle, first we need to run iscyclic() routine to find the same
 * 
 * Functions derfined in this module:
 * dfs() <void>: Basic DFS traversal of the graph
 * iscyclic() <void>: Routine to check whether the graph contains cycle or not
 *
 */

const int N = 64;
vector<int> g[N];
bool visited[N+1];
bool cycle_detected = false;

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

signed main() {
#ifdef HP
  freopen("input.txt", "r", stdin);
#endif
  int E; // no. of edges
  cin >> E;
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  reset;
  return 0;
}
