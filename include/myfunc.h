#ifndef _myfunc_h_
#define _myfunc_h_

#include <bits/stdc++.h>

inline std::vector<int> get_array(int low, int high, int times)
{
    std::vector<int> result;
    
    std::random_device rd; // 使用随机设备生成种子
    std::mt19937 gen(rd()); // 使用Mersenne Twister引擎
    
    std::uniform_int_distribution<int> distribution(low, high); // 定义分布范围
    
    for (int i = 0; i < times; ++i)
    {
        int random_num = distribution(gen); // 生成随机数
        result.push_back(random_num); // 将随机数添加到数组
    }
    
    return result;
}

inline std::vector<int> get_rise_array(int low,int high,int times)
{
    auto a = get_array(low,high,times);

    std::sort(a.begin(),a.end());

    return a;
}

inline std::vector<int> get_down_array(int low,int high,int times)
{
    auto a = get_array(low,high,times);

    std::sort(a.begin(),a.end(),[](int a1,int b){ return a1 > b;});

    return a;
}

void output(std::vector<int> & a)
{
    for(auto & i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

#endif