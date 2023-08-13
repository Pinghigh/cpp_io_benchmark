#include <iostream>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;

u64 a;
i64 b;
f64 c;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("data.in", "r", stdin);
  freopen("res.out", "w", stdout);

  cin >> a;
  while (a--) {
    cin >> b >> c;
    cout << b << ' ' << c << ' ';
  }

  return 0;
}
