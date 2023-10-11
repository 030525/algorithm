#ifndef _algorithm_h_
#define _algorithm_h_
#include <bits/stdc++.h>
using namespace std;

//TODO debug
int nonDivisibleSubset(int k, vector<int> s) {
    // eliminate multiple
    set<int> set(s.begin(),s.end());

    // max count
    int count = INT32_MIN;

    // find a base must included
    for(auto & i : set)
    {
        deque<int> temp(1,i);

        for(auto & j : s)
        {
            if(j == i) continue;
            else
            {
                bool good = true;

                for(auto & m : temp)
                {
                    if((m + j) % k == 0)
                    {
                        good = false;
                        break;
                    }
                }

                if(good) temp.push_back(j);
            }
        }

        if(temp.size() > count) count = temp.size();
    }


#ifdef DEBUG
    cout << "count = " << count;
#endif

    return count;  
    
}

#endif