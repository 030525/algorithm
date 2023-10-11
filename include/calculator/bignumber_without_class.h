#ifndef _bignumber_without_class_h_
#define _bignumber_without_class_h_

#include <bits/stdc++.h>
using namespace std;

deque<char> to_deque(int num) 
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

deque<char> add(const deque<char> & a, const deque<char> & b)
{
    deque<char> ret;

    int sum = 0;
    int overflow = 0;

    for(int i = 0;i < a.size() || i < b.size();i++)
    {
        sum = 0;
        sum += overflow;

        if(i < a.size()) sum += a[i] - '0';
        if(i < b.size()) sum += b[i] - '0';

        ret.push_back((sum % 10) + '0');

        overflow = sum / 10;
    }

    if(overflow) ret.push_back(overflow + '0');

#ifdef DEBUG
    for(auto & i : ret)
    {
        std::cout << i << " " ;
    }
    std::cout << std::endl;
#endif

    return ret;
}

inline static deque<char> many_mul_unit(const deque<char> & a,char unit)
{
    deque<char> ret;
    if(unit == '0') return ret;

    int overflow = 0;


    for(auto & i : a)
    {
        int total = ((i-'0') * (unit-'0')+overflow);

        ret.push_back(total % 10 + '0');

        overflow = total / 10;

    }

    if(overflow) ret.push_back(overflow + '0');

    return ret;
}

static deque<char> front_mul_back(const deque<char> & a, const deque<char> & b)
{
    deque<deque<char>> all;

    deque<char> once = a;
    int weight = 0;

    all.push_back(many_mul_unit(once,b[0]));

    for(int i = 1;i < b.size();i++)
    {
        once.push_front('0');
        all.push_back(many_mul_unit(once,b[i]));
    }

    once = all[0];

    for(int i = 1;i < all.size();i++)
    {
        once = add(once,all[i]);
    }

    return once;
}

deque<char> mul(const deque<char> & a, const deque<char> & b)
{
    int size1 = a.size();
    int size2 = b.size();

    deque<char> ret;

    // find the fewest index number use for cycle
    if(size1 < size2) ret = front_mul_back(b,a);
    else ret = front_mul_back(a,b);

    return ret;
}

void extraLongFactorials(int n) {
    
    deque<char> total = to_deque(1);

    for(int i = 2;i <=n;i++)
    {
        total = mul(total,to_deque(i));
    }

    //output
    for(auto i = total.rbegin();i!= total.rend();i++)
    {
        std::cout << *i;
    }

}

#endif