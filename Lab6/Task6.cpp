#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack(int size = MAX) 
    { 
        top = -1; 
    }
    bool isEmpty() 
    { 
        return top == -1; 
    }
    void push(char c) 
    { 
        arr[++top] = c; 
    }
    char pop() 
    { 
        return arr[top--]; 
    }
    char peek() 
    { 
        return arr[top]; 
    }
};

class IntStack
{
    int arr[MAX];
    int top;

public:
    IntStack() 
    { 
        top = -1; 
    }
    bool isEmpty() 
    { 
        return top == -1; 
    }
    void push(int x) 
    { 
        arr[++top] = x; 
    }
    int pop() 
    { 
        return arr[top--]; 
    }
};

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix)
{
    string prefix = "";
    Stack st(infix.length());

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];

        if (isalnum(c))
            prefix = c + prefix;

        else if (c == ')')
            st.push(c);

        else if (c == '(')
        {
            while (!st.isEmpty() && st.peek() != ')')
                prefix = st.pop() + prefix;
            if (!st.isEmpty() && st.peek() == ')')
                st.pop();
        }

        else if (isOperator(c))
        {
            while (!st.isEmpty() && getPrecedence(st.peek()) >= getPrecedence(c))
                prefix = st.pop() + prefix;
            st.push(c);
        }
    }

    while (!st.isEmpty())
        prefix = st.pop() + prefix;

    return prefix;
}

int evaluatePrefix(string prefix)
{
    IntStack s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isdigit(c))
            s.push(c - '0');

        else
        {
            int val1 = s.pop();
            int val2 = s.pop();

            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }
    return s.pop();
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    cout << "Evaluated Result: " << evaluatePrefix(prefix) << endl;
    return 0;
}
