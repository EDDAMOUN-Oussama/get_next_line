#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif
# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);

#endif