#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rowNum = grid.size();
    int colNum = grid.size();
    int res = 0;

    vector<vector<int>> time(
        rowNum, vector<int>(colNum, INT_MIN));  // 时间片，初始化为MIN

    for (int i = 0; i < rowNum; i++) {
      for (int j = 0; j < colNum; j++) {
        if (grid[i][j] == 2) {
          time[i][j] = 0;

          queue<vector<int>> q;
          q.push({i, j});
          while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();

            cout << pos[0] << " " << pos[1] << endl;

            for (auto d : DIRECTIONS) {
              int x = pos[0] + d[0], y = pos[1] + d[1];  // 四个方向
              if (x < 0 || x >= rowNum || y < 0 || y >= colNum ||
                  grid[x][y] != 1 || time[x][y] >= time[pos[0]][pos[1]] + 1)
                continue;
              time[x][y] = time[pos[0]][pos[1]] + 1;
              q.push({x, y});
            }
          }
        }
      }
    }

    for (int i = 0; i < rowNum; i++) {
      for (int j = 0; j < colNum; j++) {
        if (grid[i][j] == 1) {
          res = max(res, time[i][j]);
        }
      }
    }
    return res;
  }

 private:
  vector<vector<int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  Solution s;
  cout << s.orangesRotting(grid) << endl;

  return 0;
}