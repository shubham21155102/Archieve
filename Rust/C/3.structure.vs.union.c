#include <stdio.h>
#include <string.h>
//we can access only one member at a time in union
union student
{
    int roll;
    char name[20];
    float marks;
};
int main(){
    union student s1;
    s1.roll = 1;
    strcpy(s1.name, "John");
    s1.marks = 99.99;
    printf("Roll: %d\n", s1.roll);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);
    s1.roll = 2;
    printf("Roll: %d\n", s1.roll);
    strcpy(s1.name, "Jane");
    printf("Name: %s\n", s1.name);
    s1.marks = 100.00;
    printf("Marks: %.2f\n", s1.marks);
    return 0;
}