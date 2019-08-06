#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Must suppy filename\n"); return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open"); return 1;
    }

    struct stat sb;

    if (fstat(fd, &sb) == -1) {
        perror("fstat"); return 1;
    }

    if (!S_ISREG(sb.st_mode)) {
        printf("Not a regular file\n"); return 1;
    }

    char * p;
    if ((p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED) {
        perror("mmap"); return 1;
    }

    for(int i = 0; i < sb.st_size; i++) {
        putchar(*(p + i));
    }
    putchar('\n');

    if(munmap(p, sb.st_size) == -1) {
        perror("munmap"); return 1;
    }

    return 0;

}