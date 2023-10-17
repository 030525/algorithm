#ifndef _hamming_h_
#define _hamming_h_
#define DEBUG
#include <bits/stdc++.h>
using namespace std;

/*
*   description : implement of Hamming code 
*   start  date : 10/17/2023
*   finish date : 10/17/2023
*
*/

inline deque<char> to_deque(int num)
{
    // number 123 to deque:3 2 1
    deque<char> ret;
    string s = to_string(num);

    for(auto i = s.rbegin();i != s.rend();i++)
    {
        ret.push_back(*i);
    }

    return ret;
}

static int get_k(int n)
{
    int k = 1;

    while(true)
    {
        if(pow(2,k) >= n + k + 1) break;
        else k++;
    }

    return k;
}

inline static string D_to_B(int num)
{
    std::bitset<32> b(num);

    return b.to_string();
}

static void add_to_hashtable(int value,int index,int size_of_k,deque<int> & d)
{
    // get binary of index , index start from zero
    string s = D_to_B(index+1);

    // classify binary index
    int i = 0;
    for(auto it = s.rbegin(); i < size_of_k; it++, i++)
    {
        if(*it == '1') d[i] ^= value;
    }

}

deque<char> to_hamming(const deque<char> & d )
{
    // get k for validation

    // n for inf
    int n = d.size();
    int k = get_k(n);
    
    deque<char> ret(n + k,'0');

    // set k in 
    for(int i = 0;i < k;i++)
    {
        int index = pow(2,i);
        ret[index-1] = 'p';
    }

    // set inf in
    deque<int> de(k,0);
    for(int i = 0,j = 0;i < n;)
    {
        if(ret[j] == 'p') j++;
        else 
        {
            // use j for hashtable
            add_to_hashtable(d[i] - '0',j,k,de);

            ret[j] = d[i];
            j++;
            i++;
        }
    }

    for(int i = 0;i < k;i++)
    {
        int index = pow(2,i);
        ret[index-1] = de[i] + '0';
    }

    return deque<char>(ret.rbegin(),ret.rend());
}

#endif