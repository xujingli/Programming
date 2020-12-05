#include <bits/stdc++.h>
using namespace std;

int minimumDifficultyP(vector<int> &M, int K) {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N, K;
    cin >> N >> K;
    vector<int> M(N, 0);
    for (int j = 0; j < N; j++) {
      cin >> M[j];
    }
    cout << "Case #" << i << ": " << minimumDifficultyP(M, K) << endl;
  }

  return 0;
}