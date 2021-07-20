#ifndef QUEUE_H
#define QUEUE_H

#define TRUE (1)
#define FALSE (0)

#define QUEUE_SIZE (4)

void init_queue(void);
int is_empty_queue(void);
int is_full_queue(void);
int enqueue(int data);
int dequeue(void);
int peek(void);

void queue_test(void);
void test_linear_queue(void);
void test_circle_queue(void);

#endif // QUEUE_H
