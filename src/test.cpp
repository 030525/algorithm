#if 0
#define DEBUG
#include "../include/head.h"

int main(int argc, char const *argv[])
{
    int a;
    int b;
    cin >> a >> b;

    auto a1 = to_deque(a);
    auto b1 = to_deque(b);

    mul(a1,b1);


    //many_mul_unit(a1,b);

    return 0;
}


#endif