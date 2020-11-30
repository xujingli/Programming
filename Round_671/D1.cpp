#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  if (n % 2 == 1) {
    cout << n / 2 << "\n";
    for (int i = 0; i < n / 2; i++) {
      cout << a[i + n / 2] << " " << a[i] << " ";
    }
    cout << a[n - 1] << endl;
  } else {
    cout << (n - 1) / 2 << "\n";
    for (int i = 0; i < (n - 1) / 2; i++) {
      cout << a[i + (n - 1) / 2] << " " << a[i] << " ";
    }
    cout << a[n - 2] << " " << a[n - 1] << endl;
  }

  return 0;
}