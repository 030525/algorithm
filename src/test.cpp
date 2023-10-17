#if 1
#define DEBUG
#include "../include/head.h"
#include "../include/work/HammingCode/hamming.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;

    auto a = to_hamming(to_deque(num));

    for(auto & i : a)
    {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    return 0;
}


#endif