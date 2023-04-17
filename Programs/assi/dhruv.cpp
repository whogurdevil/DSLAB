#include <bits/stdc++.h>

using namespace std;

bool oper(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

string inf_to_post(string exp)
{
    stack<char> s;
    string post = "";
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (isalnum(c))
        {
            post += c;
        }
        else if (oper(c))
        {
            while (s.empty() && oper(s.top()) && prec(s.top()) >= prec(c) != 0)
            {
                post += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                post += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        post += s.top();
        s.pop();
    }
    return post;
}

int main()
{
    cout << "Enter the string: ";
    string exp;
    cin >> exp;
    cout << inf_to_post(exp) << endl;
    return 0;
}