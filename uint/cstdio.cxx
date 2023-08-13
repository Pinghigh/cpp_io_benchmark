#include <cstdio>

using u64 = unsigned long long;
using f64 = double;

u64 a, b;

int main() {
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);

    scanf("%llu", &a);
    while (a--) {
        scanf("%llu", &b);
        printf("%llu ", b);
    }

    return 0;
}
