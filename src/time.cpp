#if 0
#include <benchmark/benchmark.h>
#include "../include/head.h"


void MyBenchmarkFunction(benchmark::State& state)
{
    

    for (auto _ : state)
    {
        squares(1,state.range(0));
    }
    state.SetComplexityN(state.range(0));

}

void MyBenchmarkFunction1(benchmark::State& state)
{

    for (auto _ : state)
    {
        squares1(1,state.range(0));
    }
    state.SetComplexityN(state.range(0));

}
BENCHMARK(MyBenchmarkFunction)->Range(1,10000000000)->Complexity();  // 定义基准测试函数
BENCHMARK(MyBenchmarkFunction1)->Range(1,10000000000)->Complexity();  // 定义基准测试函数
BENCHMARK_MAIN(); 
// Range(min,max),it will auto select the step length
// DenseRange(min,max,step_length) same as Range
// RangeMultiplier(2)->Range(1, 16) 1,2,4,8,16
//Repetitions

//when link g++ -lbenchmark
#endif