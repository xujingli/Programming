#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> a = {1,      1,      5,       1,      21,      1,
                   85,     73,     341,     89,     1365,    1,
                   5461,   4681,   21845,   1,      87381,   1,
                   349525, 299593, 1398101, 178481, 5592405, 1082401};
  map<int, int> mp;

  int ptr = 0;
  for (int i = 3; i <= (1 << 25) - 1; i = i * 2 + 1) {
    int mx = 0;
    mp[i] = a[ptr++];
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (mp.count(n)) {
      cout << mp[n] << "\n";
    } else {
      int x = 1;
      while (x < n) {
        x = x * 2 + 1;
      }
      cout << x << "\n";
    }
  }

  return 0;
}