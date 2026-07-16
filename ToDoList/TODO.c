#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

char t[MAX][LEN];
int s[MAX];
int n = 0;

void add();
void show();
void done();
void del();

int main()
{
    int ch;

    while (1)
    {
        printf("\n=========================\n");
        printf("      TO DO LIST\n");
        printf("=========================\n");
        printf("1. Add Task\n");
        printf("2. Show Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        getchar();

        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            show();
            break;

        case 3:
            done();
            break;

        case 4:
            del();
            break;

        case 5:
            printf("\nThank You!\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}

void add()
{
    if (n == MAX)
    {
        printf("List Full!\n");
        return;
    }

    printf("Enter Task : ");
    fgets(t[n], LEN, stdin);
    t[n][strcspn(t[n], "\n")] = '\0';

    s[n] = 0;
    n++;

    printf("Task Added.\n");
}

void show()
{
    int i;

    if (n == 0)
    {
        printf("No Tasks.\n");
        return;
    }

    printf("\n------ TASK LIST ------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. [%c] %s\n", i + 1, s[i] ? 'X' : ' ', t[i]);
    }
}

void done()
{
    int x;

    if (n == 0)
    {
        printf("No Tasks.\n");
        return;
    }

    show();

    printf("Task Number : ");
    scanf("%d", &x);

    if (x < 1 || x > n)
    {
        printf("Invalid Number!\n");
        return;
    }

    s[x - 1] = 1;

    printf("Task Completed.\n");
}

void del()
{
    int x, i;

    if (n == 0)
    {
        printf("No Tasks.\n");
        return;
    }

    show();

    printf("Task Number : ");
    scanf("%d", &x);

    if (x < 1 || x > n)
    {
        printf("Invalid Number!\n");
        return;
    }

    for (i = x - 1; i < n - 1; i++)
    {
        strcpy(t[i], t[i + 1]);
        s[i] = s[i + 1];
    }

    n--;

    printf("Task Deleted.\n");
}