#include<stdio.h>
#include "get_next_line.h"
// #include "get_next_line.h"
// int main()
// {
//     char buf[100];
//     char r[100];
//     int fd = open("txt.txt", O_RDONLY);
//    int i =  read (fd, buf,100);
//    int j = 0;
//    while (j < 10)
//    {printf("%d -->%c\n" ,j,buf[j]);j++;}
//     // printf("%s%d",buf,i);
#include <fcntl.h>
#include <stdlib.h>
    

int main ()
{
    char *s = NULL;

    int fd = open("txt.txt", O_RDONLY);
    s = get_next_line(fd);
    while( s!= NULL)
    {
    printf("%s",s);
    free(s);
    s = get_next_line(fd);

    }

    // s = get_next_line(fd);
    // printf("%s",s);

    }

// int main ()
// {
//     char *s;
//     char *p;

//     s = malloc (10);
//     for (int i = 0; i < 9; i++)
//     {
//         s[i] = 'o';
//     }
//     s[9] = '\0';
//     p = s;
//     s = NULL;
//     printf("%s ==> %s\n", p, s);
//     free(p); 
//     free(s);
// }