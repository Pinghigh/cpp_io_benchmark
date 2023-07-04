#include <fstream>

using namespace std;

std::ifstream fin("data.in");
std::ofstream fout("res.out");

using i64 = long long;

i64 a, b;

int main() {
    // std::ios::sync_with_stdio(false);
    fin >> a;
    while (a--) {
        fin >> b;
        fout << b << ' ';
    }

    return 0;
}
