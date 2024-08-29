#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("pl.txt", O_RDWR);

	write(fd, "test", 4);

	write(fd, " append", 7);

	return 0;
}
