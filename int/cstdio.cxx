#include <cstdio>

using i64 = long long;
using f64 = double;

i64 a, b;

int main() {
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);

    scanf("%lld", &a);
    while (a--) {
        scanf("%lld", &b);
        printf("%lld ", b);
    }

    return 0;
}
