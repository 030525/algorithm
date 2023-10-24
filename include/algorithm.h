#ifndef _algorithm_h_
#define _algorithm_h_
#include <bits/stdc++.h>
using namespace std;


/*
*   description :
*   start  date :
*   finish date :
*
*/


long get_all(vector<long> & dp,vector<long> &c,int n)
{
    if(n < 0 ) return 0;
    if(n == 0) return 1;

    if(dp[n]) return dp[n];

    int all = 0;

    for(auto & i : c)
    {
        all += get_all(dp,c,n-i);
    }

    return dp[n] = all;

}

long getWays(int n, vector<long> c) 
{
    vector<long> dp(n+1,0);

    int ret = 0;

    ret += get_all(dp,c,n);

    return ret;
}

#endif