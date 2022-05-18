#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <assert.h>
#include <stdlib.h>

// Semaphores
sem_t se;
sem_t de;

// Functions
void *producer(void *);
void produce(int);
void *consumer(void *);
void consume(int);
int checkbu(char);

// Variables
int *barr;
int ppos = 0;
int cpos = 0;
int apos = 0;
int pr, co, n, bu;

int main() {
    // Input of Four Inputs.
    scanf("%d %d %d %d", &pr, &co, &n, &bu);

    // Allocate the Memory to create Buffet array.
    barr = malloc(sizeof(int) * bu);
    pthread_t prod[pr];
    pthread_t cons[co];

    // Initializes the Semaphore.
    sem_init(&se, 0, 1);
    sem_init(&de, 0, 1);
    sem_post(&de);

    // Creates a thread for both producer and consumer.
    for (int i = 0; i < pr; i++)
        pthread_create(&prod[i], NULL, producer, &i);
    for (int i = 0; i < co; i++)
	    pthread_create(&cons[i], NULL, consumer, &i);  

    // Joins the thread and executes the function.  
    for (int i = 0; i < pr; i++)
        pthread_join(prod[i], NULL);
    for (int i = 0; i < co; i++)
        pthread_join(cons[i], NULL);

    return 0;
}

void *producer(void *id) {
    // Get the Producer ID for debugging.
    int *idd = id;
    while (0 == 0) {
        // Sleep for 1 second.
        sleep(1);
        // Whatever try to produce when buffet is not full.
        produce(*idd);
        // Waits the semaphore 'se' for consumer.
        sem_wait(&se);
        // Add the number to variable to check then post the semaphore 'de'.
        apos = apos + 1;
        // Check if the variable is above than one, posts the semaphore 'de'.
        if (apos == 1) {
            sem_post(&de);
        }
        // Posts the semaphore to the consumer.
        sem_post(&se);
    }
}

void *consumer(void *id) {
    // Get the Consumer ID for debugging.
    int *idd = id;
    // Avoid faults through the program is running by creating the variable.
    int m;
    // Waits for producer on semaphore 'de'.
    sem_wait(&de);
    while (0 == 0) {
        // Sleep for 1 second.
        sleep(1);
        // Wait for the producer which can produce before consuming.
        sem_wait(&se);
        // Subtract the variable 'apos' for waiting on another producer.
        apos = apos - 1;
        // Avoid faults by assigning the variable 'm'.
        m = apos;
        // Post the semaphore 'se' to producer.
        sem_post(&se);
        // Consume the integers by removing from the buffet array by setting
        // the value to zero.
        consume(*idd);
        // Check if M is at zero and if true, waits for producer.
        if (m == 0) {
            sem_wait(&de);
        }
    }
}

void produce(int pid) {
    // Assert to not leave the buffet array out of bounds.
    assert (ppos >= 0);
    // Check whatever the buffet is full.
    int res = checkbu('f');
    // If it's full, the producer will not produce.
    if (res == 1) {
        printf("Warning: Buffet is full.\n");
    } else {
        if (barr[ppos] == 0) {
            // Using formula to sum the number to save to buffet array
            // at a specified position (variable 'ppos').
            int ra = (2 * ppos) + 1;
            barr[ppos] = ra;
            ppos = ppos + 1;
            if (ppos >= bu) ppos = 0;
            printf("Produtor %d produzindo %d na posicao %d\n", pid, ra, ppos);
        }
    }
}

void consume(int cid) {
    // Assert to not leave the buffet array out of bounds.
    assert (cpos >= 0);
    // Check whatever the buffet is empty.
    int res = checkbu('e');
    // If it's empty, the consumer will not consume.
    if (res == 1) {
        printf("Warning: Buffet is empty.\n");
    } else {
        if (barr[cpos] != 0) {
            // Pick the number at a specified position (variable 'cpos')
            // and consume the number.
            int cint = barr[cpos];
            barr[cpos] = 0;
            cpos = cpos + 1;
            if (cpos >= bu) cpos = 0;
            printf("Consumidor %d consumindo %d na posicao %d\n", cid, cint, cpos);
        }
    }
}

int checkbu(char typ) {
    // Checks whatever the buffet is full or empty.
    // Returns 1 if it's full or empty.
    // Returns 0 if it's not full or empty.
    int res = 1;
    if (typ == 'f') {
        for (int i = 0; i < bu; i++) {
            if (barr[i] == 0) {
                res = 0;
                break;
            }
        }
    } else if (typ == 'e') {
        for (int i = 0; i < bu; i++) {
            if (barr[i] != 0) {
                res = 0;
                break;
            }
        }
    }
    return res;
}
