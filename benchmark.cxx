#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

// the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;
using namespace chrono;

using i32 = int;
using f64 = double;

std::random_device sd;
std::mt19937_64 eng(sd());

f64 clock(char* s) {
    auto start = system_clock::now();
    system(s);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return double(duration.count()) * microseconds::period::num / microseconds::period::den;
}

void int_float_mark() {
    cout << GREEN << "\nStart test 1.5e6 random long long int and 1.5e6 random double input and output" << std::endl;
    f64 cstd = 0, fstr = 0, iostr = 0;
    i32 n = 10;
    for (i32 i = 1; i <= n; ++i) {
        system("./out/i_f/data");
        cstd += clock("./out/i_f/cstdio");
        fstr += clock("./out/i_f/fstream");
        iostr += clock("./out/i_f/iostream");
    }
    cstd /= n, fstr /= n, iostr /= n;

    cout << '\n'
         << RESET << "freopen + scanf + printf " << CYAN << cstd << RESET << "sec\n"
         << RESET << "ifstream + ofstream " << CYAN << fstr << RESET << "sec\n"
         << RESET << "freopen + cin + cout " << CYAN << iostr << RESET << "sec\n";
}

void int_mark() {
    cout << GREEN << "\nStart test 3e6 random long long int input and output" << std::endl;
    f64 cstd = 0, fstr = 0, iostr = 0, ffstr = 0, fstd = 0;
    i32 n = 10;
    for (i32 i = 1; i <= n; ++i) {
        system("./out/int/data");
        cstd += clock("./out/int/cstdio");
        fstr += clock("./out/int/fstream");
        iostr += clock("./out/int/iostream");
        ffstr += clock("./out/int/fastio_with_fstream");
        fstd += clock("./out/int/fastio_with_stdio");
    }
    cstd /= n, fstr /= n, iostr /= n, ffstr /= n, fstd /= n;

    cout << '\n'
         << RESET << "freopen + scanf + printf " << CYAN << cstd << RESET << "sec\n"
         << RESET << "ifstream + ofstream " << CYAN << fstr << RESET << "sec\n"
         << RESET << "freopen + cin + cout " << CYAN << iostr << RESET << "sec\n"
         << RESET << "fastio + cstdio " << CYAN << fstd << RESET << "sec\n"
         << RESET << "fastio + fstream " << CYAN << ffstr << RESET << "sec\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout.setf(std::ios::fixed);
    cout << std::setprecision(3);

    system("echo IO Test By Tibrella | figlet | lolcat --spread=3 --speed=40");

    cout << CYAN << "This test program will generate data and test for 10 times, then take the average for the final result" << '\n';

    int_float_mark();

    int_mark();

    return 0;
}
