#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> &stacks, int P) {
  vector<int> maxVal(P + 1, 0);
  for (int i = 0; i < stacks.size(); i++) {
    for (int j = 0; j < stacks[0].size(); j++) {
      
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N, K, P;
    cin >> N >> K >> P;
    vector<vector<int>> stacks(N, vector<int>(K, 0));
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < K; k++) {
        cin >> stacks[j][k];
      }
    }

    cout << "Case #" << i << ": " << findMaxValue(stacks, P) << endl;
  }

  return 0;
}