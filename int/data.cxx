#include <climits>
#include <fstream>
#include <random>

std::ofstream cout("data.in");

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;

std::random_device sd;
std::mt19937_64 data(sd());
std::uniform_int_distribution<i64> itg(LLONG_MIN, LLONG_MAX);

int main() {
  std::ios::sync_with_stdio(false);

  int n = 3000000;
  cout << n << '\n';
  while (n--)
    cout << data() << ' ';

  return 0;
}
