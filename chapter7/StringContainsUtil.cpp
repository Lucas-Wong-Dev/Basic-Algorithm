// 判断字符串包含的问题
// 有两个字符串str1和str2（strlen(str1)>strlen(str2)）
// 问str2中的所有字符是否被字符串str1包含
// 注意：不要求str2在str1中以连续且按序的形式出现
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[] = "ABCDEFG";
    char str2[] = "BDBQ";
    for (int i = 0; i < strlen(str2); i++)
    {
        bool exist = false;
        for (int j = 0; j < strlen(str1); j++)
        {
            if (str1[j] != str2[i])
            {
                continue;
            }
            else
            {
                exist = true;
                break;
            }
        }
        if (exist == false)
        {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}

// 如果要求str2在str1中以连续且按序的形式出现
// #include <iostream>
// #include <cstring>
// using namespace std;
// int main()
// {
//     char str1[] = "12345";
//     char str2[] = "234";
//     int count = 0;
//     for (int i = 0; i < strlen(str1) - strlen(str2) + 1; i++)
//     {
//         int itemp = i;
//         for (int j = 0; j < strlen(str2); j++, itemp++)
//         {
//             if (str1[itemp] == str2[j])
//             {
//                 count++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         if (count == strlen(str2))
//         {
//             cout << "true" << endl;
//             return 0;
//         }
//         else
//         {
//             count = 0;
//         }
//     }
//     cout << "false" << endl;
//     return 0;
// }