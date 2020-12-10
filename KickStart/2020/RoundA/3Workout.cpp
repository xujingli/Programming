#include <bits/stdc++.h>
using namespace std;

int minimumDifficultyP(priority_queue<int> &pq, int K) {
  if (pq.size() == 0) return 1;
  for (int i = 0; i < K; i++) {
    int maxD = pq.top();
    pq.pop();
    if (maxD == 1) return 1;
    pq.push(maxD / 2);
    pq.push(maxD - maxD / 2);
  }

  return pq.top();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N, K;
    cin >> N >> K;  // N 300  K 1e^5
    vector<int> M(N, 0);
    priority_queue<int> pq;
    for (int j = 0; j < N; j++) {
      cin >> M[j];
      if (j > 0) pq.push(M[j] - M[j - 1]);
    }
    cout << "Case #" << i << ": " << minimumDifficultyP(pq, K) << endl;
  }

  return 0;
}

/*
3
5 2
10 13 15 16 17
5 6
9 10 20 26 30
8 3
1 2 3 4 5 6 7 10

Case #1: 2
Case #2: 3
Case #3: 1
*/