#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    vector<int> distance(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      distance[i] = x - a[i];
    }
    // TODO : 咋办啊？？？？？？
    for (int i = 0; i < n; i++) {
      cout << distance[i] << "\t";
    }
  }

  return 0;
}