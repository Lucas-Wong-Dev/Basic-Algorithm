# C语言中的函数

## 数学函数

int abs(int n)

double exp(double x)——指数函数，返回e的x次方

double sqrt(double x)——计算平方根

double fmod(double x, double y)——返回x/y的余数，如果除数y为0则返回0



double ceil(double x)——向上取整

double floor(double x)——向下取整



double pow(double x, double y)——计算x的y次幂

double pow10(double p)——计算10的p次幂



int rand(void)——返回0-RAND_MAX间的随机整数（RAND_MAX等于pow(2, 15)-1）

void srand(unsigned seed)——初始化随机数发生器，seed是无符号整数，指名随机数序列的最小起点

```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t t;
    srand((unsigned)time(&t)); // 取得时间，并将其转换为随机数序列的最小起点
    for (int i = 0; i < 10; i++)
    {
        cout << rand() << " ";
    }
    return 0;
}
```



double sin(double x)——正弦函数

double cos(double x)——余弦函数

double tan(double x)——正切函数



double asin(double x)——反正弦函数

double acos(double x)——反余弦函数

double atan(double x)——反正切函数



double log(double x)——计算自然对数（参数和返回值均为双精度）

long double logl(long double x)——计算自然对数（参数和返回值均为长双精度）

double log10(double x)——计算以10为底的对数

long double log10l(long double x)——计算以10为底的对数



double hypot(double x, double y)——x和y为直角三角形两直角边的长度，返回直角三角形斜边边长，若 操作失败则返回无穷大

## 字符串函数

### 字符串操作

char *strcat(char *d, char *s)——拼接字符串，将字符串s拼接到字符串d的末尾，返回一个字符串指针，指向字符串d（此时的字符串d的末尾已经附加了字符串s）

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char d[3] = "d"; // 推荐用字符数组存放字符串
    char s[3] = "s";
    cout << strcat(d, s) << endl; // ds
    cout << d << endl; // ds
    return 0;
}
```

char *strncat(char *destin, char *source, size_t maxlen)——拼接部分字符串，返回一个字符串指针，指向字符串d（此时的字符串d的末尾已经附加了字符串s）



char *strstr(char *str1, char *str2)——在一个字符串中查找另一个字符串首次出现的位置



size_t strlen(const char *str)——返回字符串长度，字符串后的字符串终止符NULL不包括在内



char *strchr(char *str, char c)——查找指定字符c在字符串str中的位置，返回字符c在字符串str中首次出现的位置

char *strrchr(char *str, char c)——在字符串中查找指定字符最后一次出现的位置



int strcmp(char *str1, char *str2)——比较两个字符串。若str1==str2，返回值为0；若str1<str2，返回负数；若str1>str2，返回正数

int stricmp(char *str1, char *str2)——比较两个字符串，不区分大小写

int strncmp(char *str1, char *str2, size_t maxlen)——部分比较两个字符串。maxlen为要比较的最大长度

int strnicmp(char *str1, char *str2, size_t maxlen)——部分比较两个字符串，不区分大小写



char *strcpy(char *d, const char *s)——复制字符串，一般用于给字符数组赋值，返回一个字符串指针，指向字符串d（此时的字符串d已被赋值）

char *strncpy(char *d, const char *s, int maxlen)——部分复制字符串，返回一个字符串指针，指向字符串d（此时的字符串d已被赋值）



char *strset(char *str, char ch)——将字符串的全部字符都设为指定字符

char *strnset(char *str, char ch, unsigned n)——将字符串前n个字符都设为指定字符

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char d[10] = "PP";
    char s[10];
    cout << strnset(d, 'Q', 10) << endl; // QQ
    cout << d << endl; // QQ
    return 0;
    // 可见，strset函数和strnset函数只能对字符数组中已经被开辟的部分进行设定
}
```



char *strpbrk(const char *str1, const char *str2)——查找给定字符集中第一次出现的字符



char *strrev(char *str)——将字符串的顺序逆转



char *strtok(char *str1, char *str2)——在str1中查找单词，在str2中定义单词分隔符，返回指向相应单词的指针

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "43,a wer,s";
    char *temp = strtok(str, ", ");
    while (temp != NULL)
    {
        cout << temp << endl;
        temp = strtok(NULL, ", ");// 以逗号和空格作为分隔符
    }
    return 0;
}
```



char *strupr(char *s)——将字符串转换为大写的形式，返回一个字符串指针，指向字符串s（此时的字符串s中的每一个字符都已被转换为大写）

char *strlwr(char *s)——将字符串转换为小写的形式，返回一个字符串指针，指向字符串s（此时的字符串s中的每一个字符都已被转换为小写）



int tolower(int c)——将字符转换为小写字符

int toupper(int c)——将字符转换为大写字符

int toascii(int c)——将字符转为ASCII码值

### 数据类型转换

int atoi(const char \*str)——将字符串类型数据转换为整型数据

long atol(const char \*str)——将字符串类型数据转换为长整型数据

double atof(const char *str)——将字符串类型数据转换为浮点型数据

### 数据类型判断

int isalnum(int c)

int isalpha(int c)

int isdigit(int c)

int isxdigit(int c)——判断c是否为十六进制数字。若参数c为'A'-'F'、'a'-'f'或'0'-'9'，则返回一个非零值，否则返回0

int ispunct(int c)

int isspace(int c)

int isgraph(int c)——若参数c为一个可打印字符时，返回一个非零值；若为空格或不可打印字符则返回0

int isprint(int c)——若参数c为从0x20到0x7E（包括空格）的可打印字符时，返回一个非零值；否则返回0

int isascii(int c)

int islower(int c)——判断c是否为小写字母

int isupper(int c)

## 输入输出函数

int getch(void)——从键盘读入一个字符，字符不回显在屏幕上，只要用户按下按键就立刻返回

int getchar(void)——从标准输入设备读入一个字符，字符回显在屏幕上，用户按下按键后还要再按下回车才会返回

```cpp
#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    char ch;
    ch = getch();
    cout << "ch:" << ch << endl;
    ch = getchar();
    cout << "ch:" << ch << endl;
    return 0;
}
```



int putch(int ch)——将一个字符输出到当前文本窗口

int putchar(int ch)——将一个字符写到标准输出设备上

## 内存相关的函数

void *malloc(unsigned size)——分配内存。size指定要分配的字节数。如果分配成功，则返回指向分配内存的指针；如果分配失败（比如内存不够），则返回空指针

void *realloc(void *ptr, unsigned newsize)——重新分配内存。ptr指向要重设大小的块，newsize为要重分配内存的字节大小。返回指向被重设大小的块的指针；如果分配失败（比如内存不够），则返回空指针

void *memset(void *s, int c, size_t n)——用一指定字符填充内存。s指向要填充的第一个字节，c指定要填充的字符，n指定要填充的字节数

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "aaaaaa";
    cout << strlen(str) << endl; // 6
    cout << sizeof(str)/sizeof(str[0]) << endl; // 7

    memset(str, 'i', strlen(str));
    cout << str << endl; // iiiiii
    
    memset(str, 'q', sizeof(str)/sizeof(str[0])-1);
    cout << str << endl; // qqqqqq
    // 要注意：strlen函数在计算字符串长度时，不把尾零包括在内
    return 0;
}
```

void free(void *ptr)——释放已分配的块。ptr为指向要释放的内存块的指针

## 日期时间函数

double difftime(time_t time1, time_t time2)——计算两个时刻之间的时间差。time1要小于等于time2

```cpp
#include <iostream>
#include <ctime>

using namespace std;
int main()
{
    time_t first, second;
    double d;

    first = time(NULL);
    _sleep(2000);
    second = time(NULL);

    d = difftime(second, first);
    cout << d << endl; // 2
    printf("%f\n", d); // 2.000000

    return 0;
}
```

time_t mktime(struct tm *t)——将tm类型结构指针指定的日期与时间转换为time_t类型。time_t类型等效于长整型，等于从1970年1月1日零时到指定日期之间的秒数，允许的范围为从1970年1月1日零时-2038年1月19日3:17:07

```cpp
// tm结构及其结构成员定义如下
struct tm
{
    int tm_sec; // second
    int tm_min; // minute
    int tm_hour; // hour(0-23)
    int tm_mday; // 月中的日期(1-31)
    int tm_mon; // month(0-11)
    int tm_year; // year(不含世纪)
    int tm_wday; // 一星期中指定一天(0-6)
    int tm_yday; // 一年中指定一天(0-365)
    int tm_isdst; // 夏令时
};

```

```cpp
// 用tm结构体存储指定的日期，使用mktime推演出这个日期对应着星期几
#include <iostream>
#include <ctime>
using namespace std;
char dayOfWeek[][8] = {"Sun", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat", "Unknown"};
int main()
{
    struct tm t;
    t.tm_sec = 1;
    t.tm_min = 30;
    t.tm_hour = 9;
    t.tm_mday = 22;
    t.tm_mon = 11;
    t.tm_year = 98;
    t.tm_isdst = -1;
    if (mktime(&t) == -1)
    {
        cout << "failed" << endl;
        t.tm_wday = 7;
    }
    cout << dayOfWeek[t.tm_wday] << endl;
    return 0;
}
```

struct tm *localtime(const time_t *clock)——将time_t类型的日期和时间转换为tm类型

```cpp
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    time_t timer = time(NULL);
    struct tm *tmp = localtime(&timer);
    printf("The local time is %s", asctime(tmp));
    // The local time is Wed Jan 22 17:07:24 2020
    return 0;
}
```

time_t time(time_t *thetime)——获取系统时间，参数为指向time_t变量的可选指针，在这个变量中存放当前日期和时间（相当于函数返回值），如果是NULL则忽略

```cpp
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    time_t timer;
    time(&timer);
    cout << timer << endl; // 1579684618
    cout << time(NULL) << endl; //1579684618
    return 0;
}
```

char *asctime(const struct tm *tblock)——将日期和时间转换为ASCII码

clock_t clock(void)——用于获得程序运行时间。如果系统没有内部时间，返回-1

```cpp
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    clock_t start, end;
    start = clock();
    _sleep(1000);
    end = clock();
    cout << (end - start) / CLK_TCK << endl;
    return 0;
}
```

## 其他常用函数

void assert(int test)——测试一个条件，并可能使程序终止，判断为假则终止