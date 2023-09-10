#ifndef _binary_serach_h_
#define _binary_serach_h_

#include <bits/stdc++.h>

int find_first(int lo,int hi,const std::vector<int> & v,int target)
{
    if(lo > hi) return -1;

    int mid = lo + (hi - lo) / 2;
    if(v[mid] > target){return find_first(lo,mid-1,v,target);}
    if(v[mid] == target)
    {
        int a = find_first(lo,mid-1,v,target);
        return (a == -1) ? mid : a; 
    }
    if(v[mid] < target){return find_first(mid+1,hi,v,target);}
}

#endif