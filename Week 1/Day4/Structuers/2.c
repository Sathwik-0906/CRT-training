
#include <stdio.h>
#include<string.h>
struct bottle{
    char Name[10];
    int cost;
    char Type[20];
};
void main() {
    struct bottle b1;
    struct bottle *ptr;
    ptr=&b1;
    printf("Enter Bottle Name: ");
    scanf("%s",ptr->Name);
    printf("Enter Cost: ");
    scanf("%d",&ptr->cost);
    printf("Cooling or NO cooling: ");
    scanf("%s",ptr->Type);
    printf("%s,%d,%s",ptr->Name,ptr->cost,ptr->Type);
}