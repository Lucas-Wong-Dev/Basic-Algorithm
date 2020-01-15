// 数组正负值排序
// 暂时将0算为正数
// 借鉴简单插入排序法
// 如果我们不需要保证相对有序，则可以不用依次前移，而是直接与未排好序的部分的第一个元素进行交换
#include <iostream>
using namespace std;
int main()
{
    int array[] = {1, -2, -4, 5, 9, -3, -8, 6};
    int len = sizeof(array) / sizeof(array[0]);
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len; i++)
    {

        if (array[i] < 0) // 如果遇到了负的数组元素，则将该元素依次前移到分界指针指向的元素之前
        {
            for (int j = i; j > index; j--)
            {
                swap(array[j], array[j - 1]);
            }
            index++; // 分界指针后移
        }
    }

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}