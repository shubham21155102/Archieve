#include <stdio.h>
// define a structure
struct student
{
    int roll;
    char name[20];
    float marks;
};
// total space occupied by structure is equal to the sum of the size of all members
int main()
{
    // declare a structure variable
    struct student s1;
    // input data
    printf("Enter roll: ");
    scanf("%d", &s1.roll);
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter marks: ");
    scanf("%f", &s1.marks);
    // print data
    printf("Roll: %d\n", s1.roll);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);
    struct student students[5];
    for (int i = 0; i < 5; ++i)
    {
        printf("Enter roll for student %d: ", i + 1);
        scanf("%d", &students[i].roll);
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    // using pointer
    struct student *ptr;
    ptr = &s1;
    printf("\nUsing pointer:\n");
    printf("Roll: %d\n", ptr->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);


    return 0;
}