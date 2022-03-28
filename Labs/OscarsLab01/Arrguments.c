#ifndef ARGUMENTS
#define ARGUMENTS
#include <stdio.h>

int count_digits(char *argv)
{
    printf("%-17s", argv);
    char a = argv[0];
    int counter = 0;
    int i = 1;
    while (a != '\0')
    {
        a = argv[i];
        i++;
        counter++;
    }
    printf("%2d\n", counter);
    return counter;
}

int main(int argc, char **argv)
{
    int sum = 0;
    for (int i = 0; i < argc; ++i)
    {
        sum = sum + count_digits(argv[i]);
    }

    double average_length = (double)sum / (double)argc;
    char *a = "Total length";
    char *b = "Average length";
    printf("%-s %6d\n", a, sum);
    printf("%-s %4.2f\n", b, average_length);

    return sum;
}

#endif

/*
sixteencharacter 16
sixteencharacter    16
sixteencharacter  16
sixteencharacter 16*/