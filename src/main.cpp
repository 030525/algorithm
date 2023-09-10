#if 0

#include <bits/stdc++.h>
#include "../include/head.h"


int main(int argc, char const *argv[])
{
    std::vector<int> a = get_array(1,10,10);

    for(auto & i : a)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    merge_sort(0,a.size()-1,a);

        for(auto & i : a)
    {
        std::cout << i << " ";
    }

}

#endif
