#include <stdio.h>

int main()
{
    int x = 0, y = 0, *px, *py;
    int arr[10] = { 0 };

    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", arr[0]);
    printf("%d\n", &x);
    printf("%d\n", &y);

    px = &x;
    py = &y;

    printf("%d\n", px);
    printf("%d\n", py);
    printf("%d\n", &px);
    printf("%d\n", &py);

    for (int i = 0; i < 10; i++)
    {
        i != 9? printf("%d, ", *(arr + i)) : printf("%d", *(arr + i));
    }
    printf("\n%d\n", arr);
    printf("%d\n", &arr[0]);
    return 0;
}
