
#include <iostream>
#include <stack>


int pr(char x)
{
    if (x == '(')return 0;
    else if (x == ')') return 1;
    else if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 3;
    else if (x == '^') return 4;
}
using namespace std;

string RES(string str)
{
    string srpn;
    stack<char> stack;

    for (char c : str) 
    {
        if (!isdigit(c))
        {
           srpn += ' ';
            if (')' == c)
            {
                while (stack.top() != '(')
                {
                    srpn += stack.top();
                    stack.pop();
                   srpn += ' ';
                }
                stack.pop();
            }
            else if ('(' == c)
            {
                stack.push(c);
            }

            else if (stack.empty() || (pr(stack.top()) < pr(c)))
            {
                stack.push(c);
            }
            else
            {
                do
                {
                    srpn += stack.top();
                    srpn += ' ';
                    srpn += ' ';
                    stack.pop();
                } while (!(stack.empty()) && (pr(stack.top()) >= pr(c)));
                stack.push(c);
            }
        }
        else
        {
            srpn += c;
            
        }
    }
   
    
    
    while (!stack.empty())
    {
        srpn += ' ';
        srpn += stack.top();
       
        stack.pop();
    }
  

    return srpn;
}

int main()
{
    string str;
    cin >> str;
    string srpn = RES(str);
    cout << "Result: " << srpn;
    return 0;
}

























/*#include <iostream>
using namespace std;

int prior(char x)
{
    if ((x == '*') || (x == '/')) return 2;
    if ((x == '+') || (x == '-')) return 1;
    if ((x == '(') || (x == ')')) return 0;
}

class stack
{
    int top;
    char body[100];
public:
    stack() { top = 0; }
    bool empty() { return top == 0; }
    char get_top_element() { return body[top]; }
    int top_prior() { return prior(body[top]); }
    void push(char x)
    {
        top++;
        body[top] = x;
    }
    char pop()
    {
        top--;
        return body[top + 1];
    }

};

int main()
{
    char note[100], pnote[100];
    int i, p = 0;
    stack s;
    cin >> note;

    for (i = 0; i < strlen(note); i++)
    {
        if (note[i] == '(') s.push(note[i]);
        else if ((note[i] == '+') || (note[i] == '-') || (note[i] == '/') || (note[i] == '*'))
        {
            while ((!s.empty()) && (s.top_prior() > prior(note[i])))
            {
                p++;
                pnote[p] = s.pop();
            }
            s.push(note[i]);
        }
        else if (note[i] == ')')
        {
            while ((!s.empty()) && (s.get_top_element() != '('))
            {
                p++;
                pnote[p] = s.pop();
            }
            s.pop();
        }
        else
        {
            p++;
            pnote[p] = note[i];
        }
    }
    while (!s.empty())
    {
        p++;
        pnote[p] = s.pop();
    }
    for (i = 1; i <= p; i++)
        cout << pnote[i];
    cout << endl;
    return 0;
}*/
































/*char note[100], pnote[100];
int i, p = 0;
stack s;
cin >> note;

for (i = 0; i < strlen(note); i++)
{
    if (note[i] == '(') s.push(note[i]);
    else if ((note[i] == '+') || (note[i] == '-') || (note[i] == '/') || (note[i] == '*'))
    {
        while ((!s.empty()) && (s.top_prior() > prior(note[i])))
        {
            p++;
            pnote[p] = s.pop();
        }
        s.push(note[i]);
    }
    else if (note[i] == ')')
    {
        while ((!s.empty()) && (s.get_top_element() != '('))
        {
            p++;
            pnote[p] = s.pop();
        }
        s.pop();
    }
    else
    {
        p++;
        pnote[p] = note[i];
    }
}
while (!s.empty())
{
    p++;
    pnote[p] = s.pop();

}
for (i = 1; i <= p; i++)
cout << pnote[i];
cout << endl;
return 0;


int prior(char x)
{
    if ((x == '*') || (x == '/')) return 2;
    if ((x == '+') || (x == '-')) return 1;
    if ((x == '(') || (x == ')')) return 0;
}

class stack
{
    int top;
    char body[100];
public:
    stack() { top = 0; }
    bool empty() { return top == 0; }
    char get_top_element() { return body[top]; }
    int top_prior() { return prior(body[top]); }
    void push(char x)
    {
        top++;
        body[top] = x;
    }
    char pop()
    {
        top--;
        return body[top + 1];
    }

};*/