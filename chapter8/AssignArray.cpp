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
        b[i] *= b[0];
    }
    b[0] *= a[1];
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}