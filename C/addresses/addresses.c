#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("\n");

    printf("%i\n", n);   //prints <n>
    printf("%i\n", *p);  //prints <int> at *p location (equal to previous)

    printf("%p\n", p);   //prints <p> which a pointer to location of n
    printf("%p\n", &n);  //prints <location of n> (equal to previous)

    printf("\n");

    char *s = "Hi!";
    char *t = "Hello!";

    printf("%s\n", s);      //prints <string s>
    printf("%p\n", s);      //prints <location of string s>
    printf("%c\n", *s);     //prints <character> that is located at the string s location
    printf("%i\n", *s);     //prints <ASCII of the character> that is located at the string s location
    printf("\n");

    printf("%p\n", &s[0]);  //prints <location of 0th character> of string s
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("\n");

    printf("%c\n", s[0]);   //prints <0th character> of string s
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);
    printf("\n");

    printf("%c\n", *s);      //prints <first character> of string s
    printf("%c\n", *(s+1));  //prints <first+1 character> of string s
    printf("%c\n", *(s+2));
    printf("%c\n", *(s+3));
    printf("\n");

    printf("%s\n", s);    //prints <string s>
    printf("%s\n", s+1);  //prints <string s> starting from <s+1> position
    printf("%s\n", s+2);
    printf("%s\n", s+3);
    printf("\n");

    printf("%s - %p\n", s, s);    //prints <string s> - <location of string s>
    printf("\n");

    printf("%c - %i - %p\n", *s, *s, &s[0]);          //prints <first char> - <ASCII of first char> - <location of first char> of string s
    printf("%c - %i - %p\n", *(s+1), *(s+1), &s[1]);
    printf("%c - %i - %p\n", *(s+2), *(s+2), &s[2]);
    printf("%c - %i - %p\n", *(s+3), *(s+3), &s[3]);  //%c here will print null /0 character which doesn't take space
    printf("\n");

    printf("%i\n", s == t);             //compares if addresses of strings s and t are equal
    printf("%i\n", strcmp(s, t) == 0);  //compares if strings s and t are equal
    printf("%i\n", *s == *t);           //compares if first chars of strings s and t are equal
    printf("%i\n", *(s+1) == *(t+1));   //compares if second two chars of strings s and t are equal
    printf("\n");
}