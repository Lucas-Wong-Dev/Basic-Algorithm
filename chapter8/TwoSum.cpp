// 从数组中找出其和为指定值的两个数
// 双指针法
// 使用双指针法前应当先对数组进行排序
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int array[6] = {1, 3, 7, 5, 15, 9};
    int sum = 10;
    int len = sizeof(array) / sizeof(array[0]);
    int i = 0, j = len - 1;
    sort(array, array + len);
    while (i < j)
    {
        int sumTemp = array[i] + array[j];
        if (sumTemp == sum)
        {
            cout << array[i] << " " << array[j] << endl;
            break;
        }
        else if (sumTemp > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}