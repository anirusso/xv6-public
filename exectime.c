#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
       printf(1, "usage: exectime command argument-list\n");
       exit();
    }

    int start = uptime(); // start time in ticks
    printf(1, "Uptime: %d\n", start);

    // execute the given command
    int pid = fork();
    if (pid == 0) {
        exec(argv[1], &argv[1]);
        exit();
    }
    wait();

    int end = uptime(); // end time in ticks
    printf(1, "Uptime: %d\n", end);

    exit();
}
