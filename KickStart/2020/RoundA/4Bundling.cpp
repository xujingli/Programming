#include <bits/stdc++.h>
using namespace std;

int maximumSumScore(vector<string> &strs, int K) {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N, K;
    cin >> N >> K;
    vector<string> strs(N);
    for (int j = 0; j < N; j++) {
      cin >> strs[i];
    }
    cout << "Case #" << i << ": " << maximumSumScore(strs, K) << endl;
  }

  return 0;
}