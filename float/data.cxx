#include <climits>
#include <fstream>
#include <random>

std::ofstream cout("data.in");

using u64 = unsigned long long;
using f64 = double;

std::random_device sd;
std::mt19937_64 data(sd());
std::uniform_real_distribution<f64> fl(-100000, 100000);

int main() {
    std::ios::sync_with_stdio(false);

    int n = 3000000;
    cout << n << '\n';
    while (n--)
        cout << fl(data) << ' ';

    return 0;
}
