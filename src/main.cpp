#include <iostream>
#include <msquic.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


void print()
{
    const char *name = "/demo_shm";
    size_t SIZE = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);

    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

    char *msg = "Hello from shared memory!";
    memcpy(ptr, msg, strlen(msg) + 1);

    printf("Writer wrote: %s\n", msg);

    munmap(ptr, SIZE);
    close(fd);
}

int main() {

    print();

    int is_there = 10;
    std::cout << is_there << std::endl;
    std::cout << "hello world\n";


#include <iostream>


#if defined(__APPLE__)
        std::cout << "Compiled on macOS" << std::endl;
#elif defined(__linux__)
        std::cout << "Compiled on Linux" << std::endl;
#else
        std::cout << "Compiled on unknown system" << std::endl;
#endif



    return 0;
}
