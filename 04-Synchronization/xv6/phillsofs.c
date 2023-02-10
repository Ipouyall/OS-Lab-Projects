#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define MAX_SEM 5
#define ROUND 2

void philosopher(int id, int left, int right) {
    for(int i = 0; i < ROUND; i++) {
        if(id % 2 == 0) {
            sem_acquire(left);
            sem_acquire(right);
        }
        else {
            sem_acquire(right);
            sem_acquire(left);
        }
        sleep(30 * id);
        printf(1, "philosopher %d begins eating with forks %d , %d\n", id, left + 1, right + 1);
        sleep(400);
        sem_release(left);
        sem_release(right);
        printf(1, "philosopher %d done\n", id);
    }
}

void init_game() {
    for(int i = 0; i < MAX_SEM; i++)
        sem_init(i, 1);
}

void start_game() {
    for(int i = 0; i < MAX_SEM; i++) {
        int pid = fork();
        
        if(pid == 0) {
            philosopher(i + 1, i, (i + 1) % MAX_SEM);
            exit();
        }
    }
    
    while (wait());
    exit();
}

int main(int argc, char *argv[])
{
    init_game();
    start_game();
}
