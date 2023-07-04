#include <cstdio>

using u64 = unsigned long long;
using f64 = double;

u64 a, b;
f64 c;

int main() {
  freopen("data.in", "r", stdin);
  freopen("res.out", "w", stdout);

  scanf("%llu", &a);
  while (a--) {
    scanf("%llu %lf", &b, &c);
    printf("%llu %lf ", b, c);
  }

  return 0;
}
