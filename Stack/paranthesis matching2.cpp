#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

int isBalanced(char* exp)
{
    // Create Map
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';

    // Create map iterator
    map<char, char>::iterator itr;

    // Create stack
    stack<char> stk;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            stk.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (stk.empty())
            {
                return false;
            }
            else
            {
                char temp = stk.top();
                itr = mapping.find(exp[i]); //itr starts pointing to that specific pair

                if (temp == itr->second)
                {
                    stk.pop(); //removing the bracket
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return stk.empty() ? true : false;
}

int main()
{
    char A[] = "{([a+b]*[c-d]/e}";

    cout << isBalanced(A) << endl;

    return 0;
}
