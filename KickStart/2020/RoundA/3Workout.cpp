#include <bits/stdc++.h>
using namespace std;

int minimumDifficultyP(vector<int> &M, int K) {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;  // 100
  for (int i = 1; i <= T; i++) {
    int N, K;
    cin >> N >> K;  // N 300  K 1e^5
    vector<int> M(N, 0);
    for (int j = 0; j < N; j++) {
      cin >> M[j];  // 大小为1e9
    }
    cout << "Case #" << i << ": " << minimumDifficultyP(M, K) << endl;
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