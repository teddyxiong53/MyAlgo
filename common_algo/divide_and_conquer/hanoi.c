#include <stdio.h>

void move(int n, char a, char c)
{
    printf("[%d] %c to %c\n", n, a, c);
}
void hanoi(int n, char a, char b, char c)
{
    if(n == 1) {
        move(1, a,c);
    } else {
        hanoi(n-1, a, c, b);
        move(n, a, c);
        hanoi(n-1, b, a, c);
    }
}
int main()
{
    hanoi(4,'A', 'B', 'C');
    return 0;
}