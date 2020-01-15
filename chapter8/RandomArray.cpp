// 给定一个整型数组，将数组随机打乱顺序
// 使用随机数生成函数随机选出两个元素交换位置，重复本操作n次
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
        index1 = rand() % len;
        index2 = rand() % len;
        swap(array[index1], array[index2]);
    }

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}