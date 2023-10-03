#if 0
#include "../include/head.h"
#include <benchmark/benchmark.h>



int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    int cost = -1;

    for(int i = 0;i < keyboards.size();i++)
    {
        for(int j = 0 ; j < drives.size();j++)
        {
            int total = drives[j] + keyboards[i];
            if(total <= b && total > cost) cost = total;
        }
    }

    return cost;

}

int getMoneySpent1(vector<int> keyboards, vector<int> drives, int b) 
{
    sort(keyboards.begin(),keyboards.end());
    sort(drives.begin(),drives.end());

    int total = -1;

    for(int i = 0,j = drives.size()-1; i < keyboards.size() && j >=0;)
    {
        int t = keyboards[i] + drives[j];

        // closer
        if(t <= b)
        {
            i++;
            if(t > total) total = t;
        }
        else
        {
            j--;
        }

    }
    return total;
}


void MyBenchmarkFunction(benchmark::State& state)
{
    auto a = get_array(1,100000,state.range(0));
    auto b = get_array(1,100000,state.range(0));
    auto have = *std::max_element(a.begin(),a.end());
    have += *std::max_element(b.begin(),b.end());

    for (auto _ : state)
    {
         getMoneySpent(a,b,have);
    }
    state.SetComplexityN(state.range(0));
}

void MyBenchmarkFunction1(benchmark::State& state)
{
    auto a = get_array(1,100000,state.range(0));
    auto b = get_array(1,100000,state.range(0));
    auto have = *std::max_element(a.begin(),a.end());
    have += *std::max_element(b.begin(),b.end());
    for (auto _ : state)
    {
        getMoneySpent1(a,b,have);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(MyBenchmarkFunction)->Range(1,10000)->Complexity();  // 定义基准测试函数
BENCHMARK(MyBenchmarkFunction1)->Range(1,10000)->Complexity(); 
//BENCHMARK(MyBenchmarkFunction1)->Range(1,2)->Complexity();  // 定义基准测试函数
BENCHMARK_MAIN(); 
// Range(min,max),it will auto select the step length
// DenseRange(min,max,step_length) same as Range
// RangeMultiplier(2)->Range(1, 16) 1,2,4,8,16
//Repetitions

//when link g++ -lbenchmark
#endif