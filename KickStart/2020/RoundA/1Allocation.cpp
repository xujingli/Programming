#include <bits/stdc++.h>
using namespace std;

int maxNumberOfHouse(vector<int>& A, int B) {
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, B;
    cin >> N >> B;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << "Case #" << t << ": " << maxNumberOfHouse(A, B) << endl;
  }

  return 0;
}