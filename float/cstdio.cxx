#include <cstdio>

using u64 = unsigned long long;
using f64 = double;

u64 a;
f64 c;

int main() {
  freopen("data.in", "r", stdin);
  freopen("res.out", "w", stdout);

  scanf("%llu", &a);
  while (a--) {
    scanf("%lf", &c);
    printf("%lf ", c);
  }

  return 0;
}
