#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  int ans = 0x7ffffff;
  for (int i = 1; i <= 4; i++) {
    int temp = 0;
    for (auto x : A) {
      temp += abs(i - x);
    }
    ans = min(temp, ans);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}