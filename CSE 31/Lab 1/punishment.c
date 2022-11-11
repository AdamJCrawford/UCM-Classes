#include <stdio.h>
int main()
{
    int pair_of_nums_not_enterd = 1, first_value = 1;
    int num_times, typo_line;

    while (pair_of_nums_not_enterd)
    {
        if (first_value)
        {
            printf("Enter the number of times to repeat the punishment phrase: ");
            scanf("%d", &num_times);
            if (num_times < 1)
            {
                printf("You entered an invalid value for the number of repetitions!\n");
                continue;
            }
        }

        first_value = 0;
        printf("\nEnter the repetition line where you want to introduce the typo: ");
        scanf("%d", &typo_line);
        if ((typo_line > num_times) || (typo_line < 1))
        {
            printf("You entered an invalid value for the type placement!");
            continue;
        }
        pair_of_nums_not_enterd = 0;
    }
    printf("\n");
    for (int i = 0; i < num_times; i++)
    {
        i == typo_line - 1? printf("Programming in c is phun!\n") : printf("Programming in C is fun!\n");
    }

    return 0;
}
