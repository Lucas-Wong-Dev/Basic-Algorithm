// 数组正负值排序
// 暂时将0算为正数
// 借鉴快速排序法，其实就是双指针法
// 无法保证相对有序
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

    int i = 0, j = len - 1;
    while (i < j)
    {
        while (array[i] < 0 && i < j)
        {
            i++;
        }
        while (array[j] >= 0 && i < j)
        {
            j--;
        }
        if (i < j)
        {
            swap(array[i], array[j]);
        }
    }

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}