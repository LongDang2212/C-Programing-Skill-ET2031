/*  Created by: Dang Dinh Long */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *FS(int);
// hàm trả về n số đầu tiên dãy Fibonaci
int *FS(int n)
{
    if (n == 0)
    {
        return NULL;
    }
    int *arr = (int *)malloc(sizeof(int) * n);
    if (n == 1)
    {
        arr[0] = 1;
        return arr;
    }
    else
    {
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; i < n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr;
    }
}

// hàm tạo mảng n phần tử từ mảng số nguyên
int *clone(const int *arr, int n)
{
    int *arr1 = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
    }
    return arr1;
}

// hàm chuyển chữ cái viết thường thành viết hoa
char *toUpper(const char *s)
{
    char *arr = (char *)malloc(sizeof(char) * strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            c -= 32;
        }
        arr[i] = c;
    }
    return arr;
}

// hàm đổi số nguyên thành xâu kí tự chứa giá trị nhị phân
char *decToBin(int n)
{
    int length = (int)log2(n) + 2;
    char *s = (char *)malloc(sizeof(char) * length);
    s[length - 1] = '\0';
    for (int i = 0; i < length - 1; i++)
    {
        if (n % 2 == 0)
        {
            s[i] = '0';
        }
        else
        {
            s[i] = '1';
        }
        n = n / 2;
    }
    return s;
}

// hàm tìm tần suất các kí tự trong xâu
int *freq(const char *s)
{
    int len = strlen(s) + 1;
    char *temp = (char *)malloc(sizeof(char) * len);
    memcpy(temp, s, len);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (temp[j] == temp[i])
            {
                strcpy(temp + i, temp + i + 1);
                i--;
                len--;
                break;
            }
        }
    }
    int *arr = (int*)malloc(sizeof(int)*strlen(temp));
    for (int i = 0; i < strlen(temp); i++)
    {
        arr[i]=0;
    }
    
    for(int i=0; i<strlen(s); i++)
    {
        for (int j = 0; j < strlen(temp); j++)
        {
            if(s[i]==temp[j])
            {
                arr[j]++;
                break;
            }
        }
    }
    printf("\n%s\n%s\n",s, temp);
    for (int i = 0; i < strlen(temp); i++)
    {
        printf("%d", arr[i]);
    }
    
    return arr;
}
int main()
{
    int *a = freq("abc 1a23 cba1a 3c 2b");
    return 0;
}