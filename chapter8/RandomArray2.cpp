// 给定一个整型数组，将数组随机打乱顺序
// 借用插入排序法思想
#include <iostream>
using namespace std;
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(array) / sizeof(array[0]);
    int index1, index2;
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len; i++)
    {
        int r = rand() % (len - i) + i;
        swap(array[r], array[i]);
    }

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}