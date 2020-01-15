// 找出连加值最大的子数组
// 动态规划法
// 思路：
// 假设我们已经求得了一部分累加和，sum[i]表示以i结尾的前面最大的子数组的和
// sum[i]等于max(sum[i-1]+array[i], array[i])
// 也就是说，
// 当sum[i-1]>0时，sum[i] = sum[i-1]+array[i]
// 当sum[i-1]<=0时，sum[i] = array[i]
#include <iostream>
using namespace std;
int main()
{
    int array[10] = {3, -6, 1, 2, 3, -1, 2, -5, 1, 2};
    int len = sizeof(array) / sizeof(array[0]);
    int maxSum = array[0];
    int lastSum = array[0];
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        if (lastSum > 0) // 累加
        {
            lastSum += array[i];
        }
        else // 将i置为新的起点，并重置lastSum为array[i]
        {
            start = i;
            lastSum = array[i];
        }
        if (lastSum > maxSum) // 找到了新的最大和
        {
            maxSum = lastSum;
            end = i;
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

// 这个数组的最大子数组是1、2、3、-1、2