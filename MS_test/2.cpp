#include <bits/stdc++.h>
using namespace std;

struct tree {
  int x;
  tree *l, *r;
};

const int MAXN = 50010;
int ans = 0;
bool vis[MAXN];

void dfs(tree* T, int d) {
  vis[T->x] = true;
  ans = max(ans, d);
  if (T->l != NULL && !vis[T->l->x]) {
    dfs(T->l, d + 1);
  }
  if (T->r != NULL && !vis[T->r->x]) {
    dfs(T->r, d + 1);
  }
  vis[T->x] = false;
}

int solution(tree* T) {
  // write your code in C++14 (g++ 6.2.0)
  if (T == NULL) return 0;
  dfs(T, 1);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}