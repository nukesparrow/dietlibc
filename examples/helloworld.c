#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    static char msg[] = "Hello, World!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    return EXIT_SUCCESS;
}
