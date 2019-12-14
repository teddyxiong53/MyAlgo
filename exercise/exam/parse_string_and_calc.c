#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_string(char *s)
{
    int minus = 1;
    int sum = 0;
    int cur_num = 0;
    char c = 0;
    while(s && *s) {
        c = *s;
        if(c == '-') {
            minus *= -1;
        } else if((c<='9') && (c>='0')) {
            cur_num = atoi(s);
            cur_num *= minus;
            sum += cur_num;
            minus = 1;
            //这里需要让s跳过当前数字的所有字符。
            while((*s >= '0') && (*s <= '9')) {
                s++;
            }
            continue;
        }
        s++;
    }
    return sum;
}

int main()
{
    char *s = "AB-1CD--2EF---3";
    printf("result:%d\n", parse_string(s));
}
