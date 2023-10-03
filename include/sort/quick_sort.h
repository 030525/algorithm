#ifndef _quick_sort_h_
#define _quick_sort_h_

#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

static int classify(vector<int> & v,int lo,int hi,int base)
{
    //classify two part , small | big
    int i = lo,j = hi;

#ifdef DEBUG
    cout << "base:" << base << endl;;
    for(auto & i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "   swap:" << endl;
#endif
    while(true)
    {
        //swap once
        //TODO debug
        while(i < j)
        {
            if(v[i] < base) i++;
            else break;
        }
        
        while(i < j)
        {
            if(v[j] > base) j--;
            else break;
        }

        if(i >= j) break;
        
        int num = v[i];
        v[i] = v[j];
        v[j] = num;

#ifdef DEBUG
    for(auto & i : v)
    {
        cout << i << " ";
    }
    cout << endl;
#endif 

        
    }

    if(v[i] > v[hi])
    {
        int num = v[hi];
        v[hi] = v[i];
        v[i] = num;
    }


#ifdef DEBUG
    cout << "       last:" << endl;
    for(auto & i : v)
    {
        cout << i << " ";
    }
    cout << endl << endl;
#endif 

    return i;

    
}

inline void quick_sort(vector<int>& v,int lo,int hi)
{
    if(lo >= hi) return;
    //double point classify two part;
    int re = classify(v,lo,hi,v[hi]);
    
    quick_sort(v,lo,re);
    quick_sort(v,re+1,hi);
}




#endif