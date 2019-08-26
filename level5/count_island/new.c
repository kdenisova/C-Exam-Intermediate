/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:45:12 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/26 13:45:14 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 64

void 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *line, char *buf)
{
    int len;
    int i;
    int j;
    char *str;

    len = 0;
    if (line)
        len = len + ft_strlen(line);
    len = len + ft_strlen(buf);
    str = (char *)malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    i = 0;
    j = 0;
    if (line)
    {  
        while (line[i])
        {
            str[i] = line[i];
            i++;
        }
    }
    while (buf[j])
    {
        str[i] = buf[j];
        i++;
        j++;
    }
    free(line);
    return (str);
}

int check_line(char *line, int *count, int *len)
{
    int i;
    int check;
   
    i = 0;
    check = 0;
    while (line[i])
    {
        if (line[i] == '.' || line[i] == 'X')
            check++;
        else if (line[i] == '\n')
        {
            if (!*len)
                *len = i;
            else if (*len != check)
                return (0);
            check = 0;
            *count = *count + 1;
        }
        else
            return (0);
        i++;
    }
    if (check)
        return (0);
    return (1);
}

static char c;

void    flood_fill(char *line, int y, int x, int len, int count)
{
    line[y * len + x] = c;
    if (y - 1 >= 0 && line[(y - 1) * len + x] == 'X')
        flood_fill(line, y - 1, x, len, count);
    if (y + 1 < count && line[(y + 1) * len + x] == 'X')
        flood_fill(line, y + 1, x, len, count);
    if (x + 1 < len - 1 && line[y * len + x + 1] == 'X')
        flood_fill(line, y, x + 1, len, count);
    if (x - 1 >= 0 && line[y * len + x - 1] == 'X')
        flood_fill(line, y, x - 1, len, count);
}

void    count_island(char *line, int len, int count)
{
    int x;
    int y;

    y = 0;
    c = '0';
    len++;
    while (y < count)
    {
        x = 0;
        while (x < len)
        {
            if (line[y * len + x] == 'X')
            {
                flood_fill(line, y, x, len, count);
                c++;
            } 
            x++;
        }
        y++;
    }
    ft_putstr(line);
}

int main(int argc, char *argv[])
{
    int fd;
    int ret;
    int len;
    int count;
    char *line;
    char buf[BUF_SIZE + 1];

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            write(1, "\n", 1);
            return (1);
        }
        line = NULL;
        while ((ret = read(fd, buf, BUF_SIZE)) > 0)
        {
            buf[ret] = '\0';
            line = ft_strjoin(line, buf);
        }
        count = 0;
        len = 0;
        if (!check_line(line, &count, &len))
        {
            write(1, "\n", 1);
            return (1);
        }
        count_island(line, len, count);
    }
    else
        write(1, "\n", 1);
    return 0;
}
