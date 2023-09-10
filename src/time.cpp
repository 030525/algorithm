#if 1
#include "../include/head.h"
#include <benchmark/benchmark.h>


void MyBenchmarkFunction(benchmark::State& state)
{
    auto a = get_array(1,100000,state.range(0));

    for (auto _ : state)
    {
        merge_sort(0,a.size()-1,a);
    }
    state.SetComplexityN(state.range(0));
}

void MyBenchmarkFunction1(benchmark::State& state)
{

    for (auto _ : state)
    {

    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(MyBenchmarkFunction)->Range(1,100000)->Complexity();  // 定义基准测试函数
//BENCHMARK(MyBenchmarkFunction1)->Range(1,2)->Complexity();  // 定义基准测试函数
BENCHMARK_MAIN(); 
// Range(min,max),it will auto select the step length
// DenseRange(min,max,step_length) same as Range
// RangeMultiplier(2)->Range(1, 16) 1,2,4,8,16
//Repetitions

//when link g++ -lbenchmark
#endif