#include<stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main()
{
    char buf[100];
    char r[100];
    int fd = open("txt.txt", O_RDONLY);
   int i =  read (fd, buf,100);
   int j = 0;
   while (j < 10)
   {printf("%d -->%c\n" ,j,buf[j]);j++;}
    // printf("%s%d",buf,i);
    
}