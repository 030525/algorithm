#ifndef _merge_sort_h_
#define _merge_sort_h_

#include "../myfunc.h"
#include <bits/stdc++.h>


void merge(int lo,int hi,std::vector<int> & v);

void merge_sort(int lo,int hi,std::vector<int> & v)
{
    if(lo >= hi) return;

    int mid = lo + (hi - lo) / 2;
    merge_sort(lo,mid,v);
    merge_sort(mid+1,hi,v);

    merge(lo,hi,v);
}

void merge(int lo,int hi,std::vector<int> & v)
{
    int size = hi - lo + 1;
    std::vector<int> a(size);

    for(int i = lo;i <= hi;i++)
    {
        a[i - lo] = v[i];
    }
    
    int l = 0,mid = l + (a.size() - 1 - l) / 2,r = mid + 1;
    int index = lo;

    while(l <= mid && r < a.size())
    {
        if(a[l] < a[r])
        {
            v[index++] = a[l++];
        }
        else if(a[l] > a[r])
        {
            v[index++] = a[r++];
        }
        else
        {
            v[index++] = a[l++];
            v[index++] = a[r++];
        }
    }

    //dispose rest of l or r

    while(l <= mid){v[index++] = a[l++];}
    while(r < a.size()){v[index++] = a[r++];}


}

#endif
