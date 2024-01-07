#include <stdio.h>
#include <string.h>
enum weeks
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
int main()
{
    enum weeks today;
    today = Wednesday;
    printf("Day %d\n", today + 1);
    for(int i = Monday; i <= Sunday; ++i)
    {
        printf("Day %d\n", i + 1);
    }
    return 0;
}