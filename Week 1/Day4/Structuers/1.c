// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
struct emp{
    char name[10];
    int age;
    int id;
}e1;
void main() {
    // Write C code her
    strcpy(e1.name,"Sathwik");
    e1.age=21;
    e1.id=2225;
    printf("%s%d%d: ",e1.name,e1.age,e1.id);
}



