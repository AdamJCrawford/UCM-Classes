#include <stdio.h>
int main()
{
    int   new_value, remainder;
    int   num_even = 0, num_odd = 0, num_numbers = 2;
    float avg_even = 0, avg_odd = 0;

    printf("Please enter the 1st integer: ");
    scanf("%d", &new_value);
    while (new_value != 0)
    {
        int sum = 0;
        int num = new_value;
        while (new_value != 0)
        {
            remainder = new_value % 10;
            sum      += remainder;
            new_value = new_value / 10;
        }
        if (sum % 2 == 0)
        {
            avg_even += num;
            num_even++;
        }
        else
        {
            avg_odd += num;
            num_odd++;
        }
        // I know there is a much better way to do this but I don't know how to
        if ((num_numbers % 10 > 3) || (num_numbers % 10 == 0))
        {
            printf("Please enter the %dth integer: ", num_numbers);
        }
        else
        {
            int r  = num_numbers % 10;        //ones place
            int rr = (num_numbers / 10) % 10; //tens places
            if (rr == 1)
            {
                printf("Please enter the %dth integer: ", num_numbers);
            }
            else
            {
                if (r == 1)
                {
                    printf("Please enter the %dst integer: ", num_numbers);
                }
                else if (r == 2)
                {
                    printf("Please enter the %dnd integer: ", num_numbers);
                }
                else
                {
                    printf("Please enter the %drd integer: ", num_numbers);
                }
            }
        }
        num_numbers++;
        scanf("%d", &new_value);
    }
    printf("\n");
    if (!num_even && !num_odd)
    {
        printf("There is no average to compute\n");
    }
    num_even? printf("Average of inputs whose digits sup up to an even number: %0.2f\n", avg_even / num_even):printf("");
    num_odd? printf("Average of inputs whose digits sum up to an odd number: %0.2f\n", avg_odd / num_odd):printf("");

    return 0;
}
