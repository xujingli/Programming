#include <bits/stdc++.h>
using namespace std;


// 复习一下背包问题：
/* 0-1 背包
  问题：有一个可装载重量为W的背包，和 N 个物品； 第i个物品的重量为wt[i],价值为val[i]
        现在让你用这个背包装物品，最多能装的价值是多少？
  状态： 背包容量 、 可选择的物品
  选择： 装进背包 、 不装进背包
  dp数组定义：描述问题局面的一个数组，把状态表达出来；
    dp[i][w]： 对于前i个物品，当前背包容量为W，这种情况下可以装的最大价值(i从1开始)
    最终的答案就是 dp[N][W]
  状态转移逻辑： 选择将第i个物品放进背包： dp[i][w] = dp[i-1][w-wt[i-1]] + val[i-1];(wt的i从0开始)
                选择不将第i个物品放进背包： dp[i][w] = dp[i-1][w]
*/
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
  vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int w = 1; w <= W; w++) {
      if(w - wt[i-1] >= 0){
        dp[i][w] = max(dp[i-1][w],
                        dp[i-1][w - wt[i-1]] + val[i-1]);
      } else {
        dp[i][w] = dp[i-1][w];
      }
    }
  }
  return dp[N][W];
}

/* 子集背包问题：
  问题描述：给一个可装载重量为sum/2的背包，和 N 个物品； 第i个物品的重量为 nums[i]。
            是否存在一种装法，能够恰好将背包装满？
  状态： 背包容量 、 可选择的物品
  选择： 装进背包 、 不装进背包
  dp数组定义： dp[i][j] = true 表示对于前i (i>=1)个物品,当前背包的容量为j时，可以恰好将背包装满
              dp[i][j] = false  表示无法将背包恰好装满
  状态转移逻辑： 选择把第i个物品装进背包： 是否能够恰好装满背包，取决于上一个状态dp[i-1][j]
                选择不把第i个物品装进背包: 是否能够装满背包，取决于状态dp[i-1][j-第i个物品重量]
*/
bool canPartition(vector<int>& nums){ // LC 416
  int sum = 0;
  for(auto num : nums) sum += num;
  if(sum % 2 != 0) return false;
  int n = nums.size();
  sum /= 2;
  vector<vector<bool> > dp(n+1, vector<bool>(sum + 1, false));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sum; j++){
      if(j - nums[i-1] < 0){
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j] || 
                    dp[i-1][j-nums[i-1]];
      }
    }
  }
  return dp[n][sum];
}

// 状态压缩： dp[i][j] 都是通过上一行的dp[i-1][..]转移过来的； 可以压缩为一维
bool canPartition1(vector<int>& nums){ // LC 416
  int sum = 0;
  for(auto num : nums) sum += num;
  if(sum % 2 != 0) return false;
  int n = nums.size();
  sum /= 2;
  vector<bool> dp(sum + 1, false);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sum; j++){
      // if(j - nums[i-1] < 0){
      //   dp[j] = dp[j]; // 可以省略
      // } else {
      //   dp[j] = dp[j] || 
      //           dp[j-nums[i-1]];
      // }
      if(j - nums[i-1] >= 0){
        dp[j] = dp[j] || dp[j-nums[i-1]];
      }
    }
  }
  return dp[sum];
}

/* 完全背包问题：
  问题描述：背包容量为amount， 有n种物品，每种物品的数量无限多， 第i种物品的重量为coins[i]
          问有多少种方式将背包恰好装满？
          有无穷多个硬币，面值存在coins数组种，给定一个amount,请问有几种组合成amount的方法？
  状态： 背包容量 、 可选择的物品
  选择： 装进背包 、 不装进背包
  dp数组定义： dp[i][j] 只使用前i个物品，当背包容量为j时，有dp[i][j]种方法可以装满背包
              dp[0][..] = 0  dp[..][0] = 1
              最终的答案就是dp[N][amount]
  状态转移方程： 把第i个物品放进背包： dp[i][j] = dp[i-1][j]
                不把第i个物品放进背包： dp[i][j] = dp[i][j-coins[i-1]]
                将两种凑发相加
*/
int change(int amount, vector<int>& coins) {
  int n = coins.size();
  vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
  // base case
  for (int i = 0; i <= n; i++) dp[i][0] = 1;

  for (int i = 1; i <= n; i++) {
    for(int j = 1; j <= amount; j++) {
      if(j-coins[i-1] >= 0)
        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
      else 
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][amount];
}
// 状态压缩：状态转移只和dp[i][..]和dp[i-1][]有关
int change1(int amount, vector<int>& coins) {
  int n = coins.size();
  vector<int> dp(amount+1, 0);
  // base case
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for(int j = 1; j <= amount; j++) {
      // if(j-coins[i-1] >= 0)
      //   dp[j] = dp[j] + dp[j-coins[i-1]];
      // else 
      //   dp[j] = dp[j]; // 相同
      if(j-coins[i-1] >= 0)
        dp[j] = dp[j] + dp[j-coins[i-1]];
    }
  }
  return dp[amount];
}


int maxNumberOfHouse(vector<int>& A, int B) {
  sort(A.begin(), A.end());

  int count = 0;
  int res = 0;
  for(int i = 0; i < A.size(); i++) {
    count += A[i];
    if(count <= B) 
      res++;
  }

  return res;
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