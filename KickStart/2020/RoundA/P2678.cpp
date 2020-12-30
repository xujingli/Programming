/*
跳石头问题 https://www.luogu.com.cn/problem/P2678
二分答案
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &D, int N, int M, int step) {
  // 判断最多能拿走M块石头的情况下，能否使得最小距离小于等于step
  int lastPos = 0;  // 上一次的起始位置
  for (int i = 0; i < N; i++) {
    if (D[i] - lastPos < step) {
      if (M == 0) return false;
      M--;
    } else {
      lastPos = D[i];
      continue;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int L, N, M;
  cin >> L >> N >> M;
  // 分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。
  vector<int> D(N + 1, 0);
  for (int i = 0; i < N; i++) cin >> D[i];
  D.push_back(L);  // 最后一个位置

  int left = 1, right = L;  // 最短跳跃距离的可能结果是[1, L]
  while (left < right) {
    int mid = left + (right - left) / 2;
    // 如果最短的跳跃距离可以为mid的话，说明可以更小或者就是mid
    if (check(D, N + 1, M, mid))
      left = mid + 1;
    else
      right = mid - 1;
  }
  cout << left << endl;

  return 0;
}