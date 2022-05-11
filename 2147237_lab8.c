// pattern matching
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

void bruteforcesearch(char[], char[]);

int main(int argc, char *argv[])
{
    char *text = (char *)malloc(MAXSIZE * (sizeof(char)));
    char *pattern = (char *)malloc(MAXSIZE * (sizeof(char)));
    printf("\nEnter main string : ");
    fgets(text, MAXSIZE, stdin);
    printf("\nEnter search string : ");
    fgets(pattern, MAXSIZE, stdin);
    bruteforcesearch(text, pattern);

    return 0;
}

void bruteforcesearch(char main_str[], char pattern[])
{
    int comparisons = 0, shifts = 0, count = 0, i, j, k, l, flag;
    int m_size = strlen(main_str);
    int p_size = strlen(pattern);

    if (m_size < p_size)
    {
        printf("\nMain String cannot be shorter than the pattern string!!");
        return;
    }
    printf("\nStarting Brute Force Search ...\n");
    for (i = 0; i < m_size - p_size + 1; i += 1)
    {
        flag = 1;
        printf("\n%s", main_str);
        for (l = i; l > 0; l -= 1)
            printf(" ");
        printf("%s", pattern);
        for (j = i, k = 0; j < i + p_size - 1; j += 1, k += 1)
        {
            comparisons += 1;
            if (main_str[j] != pattern[k])
            {
                flag = 0;
                break;
            }
        }
        shifts += 1;
        if (flag)
        {
            printf("Pattern FOUND : start_position[%d] ... end_position[%d]\n", i, (i + p_size - 2));
            count++;
        }
    }

    printf("\nBrute Force  search took %d comparisons and %d shifts.\n", comparisons, shifts);
    printf("\nThe Pattern String was FOUND %d times in the Main String.\n", count);
}
