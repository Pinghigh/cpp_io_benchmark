#include <fstream>

std::ifstream cin("data.in");
std::ofstream cout("res.out");

template <typename __inputType>
void read(__inputType& x) {
    x = 0;
    bool f = 0;
    char ch;
    do {
        cin.get(ch);
        if (ch == '-') {
            f = 1;
        }
    } while (ch < 48 || ch > 57);
    do {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        cin.get(ch);
    } while (ch > 47 && ch < 58 && !cin.eof());
    x *= (f ? -1 : 1);
}

template <typename __inputType, typename... __inputArgs>
void read(__inputType& x, __inputArgs&... __args) {
    read(x);
    read(__args...);
}

template <typename __outputType>
void write(__outputType __x, char __ch = ' ') {
    static short int __output_stack[64], __pos;
    __pos = 0;
    do {
        __output_stack[__pos++] = __x % 10;
        __x /= 10;
    } while (__x);
    while (__pos--) {
        cout.put(__output_stack[__pos] ^ 48);
    }
    cout.put(__ch);
}

template <typename __outputType, typename... __outputArgs>
void write(__outputType __x, char __ch = ' ', __outputArgs... __args) {
    write(__x, __ch);
    write(__args...);
}

using i64 = long long;

i64 a, b;

int main() {
    read(a);
    while (a--) {
        read(b);
        write(b, ' ');
    }

    return 0;
}