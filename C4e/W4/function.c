/*Love you how much
demonstrate loop with while
Sally coder
Jan 18, 2018*/

#include<stdio.h>
void print_heart(int repeat)
{
    while(repeat > 0)
    {
        printf("very\n");
        repeat--;
    }
    printf("much. \n");
}

int main(void)
{
    int repeat = 0;
    printf("How strong is your love 1-10: ?\n");
    scanf("%d", &repeat);
    printf("I love you very\n");
    print_heart(repeat);
    return 0;
}
