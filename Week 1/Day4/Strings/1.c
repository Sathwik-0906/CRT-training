#include<stdio.h>
void main()
{
char s[12],s1[12];
printf("Enter a str");
gets(s);//read the str
printf("Enter str2");
gets (s1);
puts(s);
printf("length=%d\n", strlen(s));//
printf("reverse=%s\n", strrev(s));
printf("Upper case=%s\n",strup (s1));
printf("lower case=%s\n", strlwr (s1));


}


