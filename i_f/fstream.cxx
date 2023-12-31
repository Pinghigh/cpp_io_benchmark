#include <fstream>

using namespace std;

std::ifstream fin("data.in");
std::ofstream fout("res.out");

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;

u64 a;
i64 b;
f64 c;

int main() {
  // std::ios::sync_with_stdio(false);

  fin >> a;
  while (a--) {
    fin >> b >> c;
    fout << b << ' ' << c << ' ';
  }

  return 0;
}
