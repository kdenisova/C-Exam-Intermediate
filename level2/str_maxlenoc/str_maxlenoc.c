#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return (len);
}

int main(int argc, char *argv[])
{
    int i;
    int j;
    int row;
    int col;
    int len1;
    int len2;
    int res;
    char *str;
    
    res = 0;
    if (argc > 2)
    {
        len1 = ft_strlen(argv[1]);
        len2 = ft_strlen(argv[2]);
        int arr[len1][len2];
        i = 0;
        while (i < len1)
        {
            j = 0;
            while (j < len2)
            {
                if (argv[1][i] == argv[2][j])
                {
                    if (i == 0 || j == 0)
                        arr[i][j] = 1;
                    else
                        arr[i][j] = arr[i - 1][j - 1] + 1;
                    if (res < arr[i][j])
                    {
                        res = arr[i][j];
                        row = i;
                        col = j;
                    }
                }
                else
                    arr[i][j] = 0;
                j++;
            }
            i++;
        }
        printf("row = %d, col = %d, res = %d\n", row, col, res);
        str = (char *)malloc(sizeof(char) * res + 1);
        str[res] = '\0';
        res--;
        while (arr[row][col] != 0)
        {
            str[res] = argv[1][row];
            res--;
            row--;
            col--;
        }
        printf("%s\n", str);
    }
    //write(1, "\n", 1);
    return 0;
}
