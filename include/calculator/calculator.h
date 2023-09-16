#ifndef _calculator_h_
#define _calculator_h_

#include <bits/stdc++.h>
using namespace std;

//define priority table
//without ()
inline int priority(char x)
{
    if (x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    return 0;
}

inline static void calculate_once(stack<char> & ops,stack<int> & num )
{
    int n = num.top();
    num.pop();

    char x = ops.top();
    ops.pop();

    int n1 = num.top();
    num.pop();

    if(x == '+') n = n + n1;
    else if(x == '-') n = n1 - n;
    else if(x == '*') n = n * n1;
    else if(x == '/') n = n1 / n;

    num.push(n);
}

inline int calculator(const std::string & s)
{

    stack<char> ops;
    stack<int> num;

    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == '(') ops.push(s[i]);
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
        {
            //comapre priority 
            while(ops.size() && priority(s[i]) <= priority(ops.top()))
            {
                calculate_once(ops,num);
            }

            ops.push(s[i]);
        }
        else if(s[i] == ')')
        {
            //calculator until last '('
            while(ops.top() != '(') calculate_once(ops,num);
            ops.pop();
        }
        else
        {
            // input whole num
            std::string x = "";

            for(;i<s.size() &&  (isdigit(s[i]) || s[i] == '.');i++)  x+=s[i];
            i--;
            num.push(stod(x));
        }
    }


    while(num.size() != 1)
    {
        calculate_once(ops,num);
    }

    return num.top();
}

inline double calculator_required_parentheses(const std::string & s)
{
    // Init 

    stack<char> ops;
    stack<double> num;

    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == '(');
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') ops.push(s[i]);
        else if(s[i] == ')')
        {
            //calculate
            char x = ops.top();
            double n = num.top();
            ops.pop();
            num.pop();

            if(x == '+') n = n + num.top();
            else if(x == '-') n = num.top() - n;
            else if(x == '*') n = n * num.top();
            else if(x == '/') n = num.top() / n;


            num.pop();
            num.push(n);
        }
        else
        {
            // input whole num
            std::string x = "";

            for(;i<s.size() &&  (isdigit(s[i]) || s[i] == '.'  );i++)  x+=s[i];
            i--;
            num.push(stod(x));
        }
    }

    return num.top();
}

#endif