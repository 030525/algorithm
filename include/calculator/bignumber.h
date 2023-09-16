#ifndef _bignumber_h_
#define _bignumber_h_

#include <bits/stdc++.h>
using namespace std;

class Bignumber
{
public:
    Bignumber() = default;
    ~Bignumber() = default;
    Bignumber(const Bignumber & b);
    //Bignumber()
    Bignumber(const std::string & s);
    Bignumber(int s);
    Bignumber operator + (const Bignumber & b);
    //TODO b[1]
    void out();
private:
    vector<char> num;
};

void Bignumber::out()
{
    for(int i = this->num.size() - 1;i >=0 ;i--)
    {
        std::cout << this->num[i];
    }
}


Bignumber::Bignumber(const std::string & s)
{
    for(int i = s.size()-1;i >=0 ;i--)
    {
        this->num.push_back(s[i]);
    }
}


Bignumber::Bignumber(const Bignumber & b)
{
    this->num = b.num;
}


inline static void add(int & total,int add,std::vector<char> & c)
{
    total += add;
    c.push_back((total % 10) + '0');

    if(total >= 10) total = 1;
    else total = 0;
}


Bignumber Bignumber::operator + (const Bignumber & b)
{
    Bignumber c;
    int total = 0;

    //add total
    int i = 0;
    for(; i < this->num.size() && i < b.num.size();i++)
    {
        add(total,(this->num[i] - '0' + b.num[i] - '0'),c.num);
    }

    //deal rest
    //TODO simplify
    for(;i < this->num.size();i++)
    {
        add(total,this->num[i] - '0',c.num);
    }

    for(;i < b.num.size();i++)
    {
        add(total, b.num[i] - '0',c.num);
    }

    if(total) add(total,0,c.num);

    return c;

}

#endif