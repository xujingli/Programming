#include <bits/stdc++.h>
using namespace std;

void print2DVector(vector<vector<int>> &vec) {
  int m = vec.size(), n = vec[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << vec[i][j] << " ";
    }
    cout << endl;
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

    vector<vector<int>> dp(N + 1, vector<int>(P + 1, 0));
    // dp[i][j] 从前i个stack中，取j个盘子，值表示最大的value
    // i 取值从1开始 j从1开始
    // dp[N][P] 从前N个stack中，取P个盘子，值就是想要的值。
    vector<vector<int>> sum(N + 1, vector<int>(K + 1, 0));
    //  Let sum[i][x] denote the sum of first x plates from stack i.
    int val;

    for (int i = 1; i <= N; i++) {
      int lastVal = 0;
      for (int j = 1; j <= K; j++) {
        cin >> val;
        sum[i][j] = val + lastVal;
        lastVal = sum[i][j];
      }
    }

    // Let's say we pick x plates from the i-th stack, then dp[i][j] =
    // max(dp[i][j], sum[i][x]+dp[i-1][j-x]).
    // 从前 i-1个 stack中 取剩下的j-x个盘子
    for (int i = 1; i <= N; i++) {    // 从前i行取
      for (int j = 0; j <= P; j++) {  // 从前i行(包括)一共取了j个
        for (int k = 0; k <= min(P, K); k++) {  // 第i行可能取的盘子个数
          if (j - k >= 0)
            dp[i][j] = max(
                dp[i][j],
                sum[i][k] +
                    dp[i - 1][j - k]);  // 如果第i行取了k个，剩余的从i-1行里取
        }
      }
    }

    // cout << "dp:" << endl;
    // print2DVector(dp);
    // cout << "sum:" << endl;
    // print2DVector(sum);

    cout << "Case #" << i << ": " << dp[N][P] << endl;
  }

  return 0;
}

/*
2
2 4 5
10 10 100 30
80 50 10 50
3 2 3
80 80
15 50
20 10
*/