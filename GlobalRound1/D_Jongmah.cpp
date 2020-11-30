#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> tiles(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    tiles[x]++;
  }

  vector<vector<int>> dp(3, vector<int>(3, 0));
  for (int c : tiles) {
    vector<vector<int>> new_dp(3, vector<int>(3, 0));
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
          if (x + y + z <= c) {
            new_dp[y][z] =
                max(new_dp[y][z], dp[x][y] + z + (c - x - y - z) / 3);
          }
        }
      }
    }
    swap(dp, new_dp);
  }

  cout << dp[0][0] << '\n';

  return 0;
}