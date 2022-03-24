#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
//#include <stringstream>

//#include <cstring>
//#include <ctype.h>

using namespace std;

int main(void) {

    stack <float> steck;
    float result;
    int g = 0;
    int t = 0;
    string s;
    string a;
    getline(cin, a);

    for (int i = 0; i < (int)a.length(); i++)
    {
        if (((a[i] >= '0') && (a[i] <= '9')) || (a[i] == '.'))
        {
            s[t] = a[i];
            t++;
            g = 0;
        }
        else
        {
            if (g == 0)
            {
                double temp = ::atof(s.c_str());
                steck.push(temp);
                s.clear();
                t = 0;
                g++;
            }
            if ((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/'))
            {
                result = steck.top();
                steck.pop();
                switch (a[i])
                {
                case '+':
                    result += steck.top();
                    break;
                case '-':
                    result = steck.top() - result;      // вероятное место ошибки из-за логики вычитания
                    break;                              // исправить на result -= steck.top();
                case '*':
                    result *= steck.top();
                    break;
                case '/':
                    result /= steck.top();
                    break;
                }
                steck.pop();
                steck.push(result);
            }
        }
    }
    cout << "result = " << steck.top() << "\n";
    return 0;
}
























