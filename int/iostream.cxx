#include <iostream>

using namespace std;

using i64 = long long;

i64 a, b;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);

    cin >> a;
    while (a--) {
        cin >> b;
        cout << b << ' ';
    }

    return 0;
}
