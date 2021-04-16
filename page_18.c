/*  Created by: Dang Dinh Long */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// hàm in mảng số nguyên có n phần tử
void print(const int *arr, int n)
{
    printf("\nMang so nguyen: ");
    // for (int i = 0, *p = arr; i < n; i++, p++)
    // {
    //     printf("%d\t", *p);
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

// hàm tính tổng mảng số nguyên n phần tử
int sum(const int *arr, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        // s += *(arr + i);
    }
    return s;
}

// hàm tính trung bình cộng của mảng các số nguyên n phần tử
double averange(const int *arr, int n)
{
    return sum(arr, n) / (double)n;
}

// hàm tính giá trị đa thức bậc n tại x
double polynorm(double *arr, int n, double x)
{
    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i] * pow(x, i);
    }
    return temp;
}

// hàm đổi xâu kí tự sang số
double toNumber(char *s)
{
    int flag1 = 1, flag2 = 1, flag3 = 0, begin, end, point = 0;
    int index = 0;
    for (char *i = s; *i != '\0'; i++, index++)
    {
        if (flag1)
        {
            if ((*i >= '0' && *i <= '9') || (*i == '.'))
            {
                flag1 = 0;
                begin = index;
                if (*i == '.')
                {
                    flag3 = 1;
                    point = index;
                }
            }
        }
        if (!flag1 && flag2)
        {
            if (flag3)
            {
                if (*i < '0' || *i > '9')
                {
                    flag2 = 0;
                    end = index;
                }
            }
            else
            {
                if (*i == '.')
                {
                    point = index;
                    flag3 = 1;
                    continue;
                }
                if (*i < '0' || *i > '9')
                {
                    flag2 = 0;
                    end = index;
                }
            }
        }
        if (!flag1 && !flag2)
        {
            break;
        }
    }
    printf("\n%d\t%d\t%d\n", begin, point, end);
    double number = 0;
    if (!flag3)
    {
        for (int i = 0; i < end - begin; i++)
        {
            number += (int)(s[begin + i] - '0') * pow(10, end - begin - i - 1);
        }
    }
    else
    {
        double positive = 0, negative = 0;
        for (int i = 0; i < point - begin; i++)
        {
            positive += (int)(s[begin + i] - '0') * pow(10, point - begin - i - 1);
        }
        for (int i = 1; i < end - point; i++)
        {
            negative += (int)(s[point + i] - '0') * pow(10, end - point - i - 1);
        }
        number = positive + negative * pow(10, -(end - point - 1));
    }
    return number;
}

// hàm chuẩn hoá họ tên tiếng Việt
char *standadize(char *s)
{
    int len = strlen(s)+1;
    char *arr = (char *)malloc(sizeof(char) * len);
    memcpy(arr, s, len);
    for (int i = 0; i < len; i++)
    {
        // if (s[i] < 'a' && s[i] > 'z' && s[i] < 'A' && s[i] > 'Z' && s[i] != ' ')
        // {
        //     arr[i] = '0';
        // }
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            arr[i] = '0';
        }
        if (s[i] >= '1' && s[i] <= '9')
        {
            arr[i] = '0';
        }
        if (s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i] == ' ')
        {
            arr[i + 1] -= 32;
        }
        if ((s[i + 1] >= 'A' && s[i + 1] <= 'Z') && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            arr[i + 1] += 32;
        }
    }
    if (arr[0] >= 'a' && arr[0] <= 'z')
    {
        arr[0] -= 32;
    }
    if (arr[0] == ' ')
    {
        arr[0] = '0';
    }
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == '0')
        {
            strcpy(arr + i, arr + i + 1);
            len -= 1;
            i--;
        }
    }
    return arr;
}
int main()
{
    // double num = toNumber("abc021.342035de34");
    printf("%s", standadize(" dA1ng  di03nh LOnG "));

    return 0;
}