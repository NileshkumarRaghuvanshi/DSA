#include <semaphore.h>


int create_sem(sem_t sem, int start_val);
int lock_shared_mem(sem_t sem);
int unlock_shared_mem(sem_t sem);
int destroy_sem(sem_t sem);

