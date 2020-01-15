// 定义i*j的子矩阵k*l，其中0<k<i，0<l<j，求最大子矩阵的和
// 动态规划法
// 思路：
// 先行后列地处理二维数组
// 需要用到三重循环
// 第一重循环、第二重循环的作用：遍历二维数组的行，第一重循环对应着子矩阵的首行，第二重循环对应着子矩阵的尾行
// 第三重循环：遍历二维数组的列。
// 在第三种循环中将“中间矩阵”压缩为一维矩阵（即数组），并使用MaxSumSubArray函数求出该数组连加值最大的子数组

#include <iostream>
using namespace std;
int MaxSumSubArray(int array[], int len)
{
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
    return maxSum;
}
int main()
{
    int matrix[3][5] = {{-1, 2, -1, 3, -4}, {2, 3, 4, -5, 1}, {1, -1, 5, -3, -2}};
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] += matrix[i - 1][j];
        }
    }

    int maximum = matrix[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            int array[5]; // array数组的每一位 保存的是 从第i行到第j行所对应的矩阵的列元素之和
            for (int k = 0; k < 5; k++)
            {
                if (i == 0)
                {
                    array[k] = matrix[i][k];
                }
                else
                {
                    array[k] = matrix[j][k] - matrix[i - 1][k];
                }
            }

            int maximal = MaxSumSubArray(array, sizeof(array) / sizeof(array[0]));

            if (maximal > maximum)
            {
                maximum = maximal;
            }
        }
    }
    cout << maximum << endl;
    return 0;
}
