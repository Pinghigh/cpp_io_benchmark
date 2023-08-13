#include <cstdio>

#ifdef __WINDOWS__
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif

#ifdef __LINUX__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <typename __inputType>
void read(__inputType& x) {
    x = 0;
    static char ch;
    do {
        ch = getchar();
    } while (ch < 48 || ch > 57);
    do {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    } while (ch > 47 && ch < 58);
}

template <typename __inputType, typename... __inputArgs>
void read(__inputType& x, __inputArgs&... __args) {
    read(x);
    read(__args...);
}

static unsigned char __output_stack[64], __pos;
template <typename __outputType>
void write(__outputType __x, char __ch = ' ') {
    __pos = 0;
    do {
        __output_stack[__pos++] = __x % 10 ^ 48;
        __x /= 10;
    } while (__x);
    while (__pos--) {
        putchar(__output_stack[__pos]);
    }
    putchar(__ch);
}

template <typename __outputType, typename... __outputArgs>
void write(__outputType __x, char __ch, __outputArgs... __args) {
    write(__x, __ch);
    write(__args...);
}

using u64 =unsigned long long;

u64 a, b;

int main() {
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);

    read(a);
    while (a--) {
        read(b);
        write(b, ' ');
    }

    return 0;
}
