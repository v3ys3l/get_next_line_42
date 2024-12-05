#include"get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	int fl;
	fd = open("Deneme.txt", O_RDONLY);
	fl = open("asd.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fl));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fl));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fl));
	close(fd);
}
