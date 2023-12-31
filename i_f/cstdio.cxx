#include <cstdio>

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;

u64 a;
i64 b;
f64 c;

int main() {
  freopen("data.in", "r", stdin);
  freopen("res.out", "w", stdout);

  scanf("%llu", &a);
  while (a--) {
    scanf("%lld %lf", &b, &c);
    printf("%lld %lf ", b, c);
  }

  return 0;
}
