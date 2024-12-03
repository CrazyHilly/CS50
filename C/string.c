#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Julia";

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n", s[i]);
    }
    printf("%s\n", s);
}