#include <bits/stdc++.h>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
const int MAXN = 410;
int count5[410][410];
int count2[410][410];

int f[MAXN][MAXN][4];
int g[MAXN][MAXN][4];

int solution(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int m = A[0].size();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = A[i][j];
            while (x % 5 == 0) x /= 5, count5[i][j]++;
            while (x % 2 == 0) x /= 2, count2[i][j]++;
        }
    }

    for (int i = 0; i < n; ++i) { // 向下
        for (int j = 0; j < m; ++j) { // 向右
            f[i][j][0] += count2[i][j];
            g[i][j][0] += count5[i][j];
            f[i][j][2] += count2[i][j];
            g[i][j][2] += count5[i][j];
            if (j > 0) {
                f[i][j][0] += f[i][j - 1][0];
                g[i][j][0] += g[i][j - 1][0];
            }
            if (i > 0) {
                f[i][j][2] += f[i - 1][j][2];
                g[i][j][2] += g[i - 1][j][2];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) { // 向上
        for (int j = m - 1; j >= 0; --j) { // 向左
            f[i][j][1] += count2[i][j];
            g[i][j][1] += count5[i][j];
            f[i][j][3] += count2[i][j];
            g[i][j][3] += count5[i][j];
            if (j < m - 1) {
                f[i][j][1] += f[i][j + 1][1];
                g[i][j][1] += g[i][j + 1][1];
            }
            if (i < n - 1) {
                f[i][j][3] += f[i + 1][j][3];
                g[i][j][3] += g[i + 1][j][3];
            } 
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d1 = 0; d1 < 4; ++d1) {
                for (int d2 = 0; d2 < 4; ++d2) {
                    if (d1 == d2) continue;
                    int t = min(f[i][j][d1] + f[i][j][d2] - count2[i][j], g[i][j][d1] + g[i][j][d2] - count5[i][j]);
                    ans = max(ans, t); 
                }
            }
        }
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}