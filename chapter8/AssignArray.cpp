// 数组赋值
// 注意根据题意，循环中是可以使用一个用于循环计数的局部变量的
// 
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[sizeof(a) / sizeof(a[0])] = {0};
    b[0] = 1;
    for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
    {
        b[0] *= a[i - 1];
        b[i] = b[0];
    }
    b[0] = 1;
    for (int i = sizeof(a) / sizeof(a[0]) - 2; i > 0;i --)
    {
        b[0] *= a[i + 1];
        b[i] *= b[0]; // 注意这里是*=，而不是=
    }
    b[0] *= a[1];
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}