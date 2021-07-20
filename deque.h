#ifndef DEQUE_H
#define DEQUE_H

#define TRUE (1)
#define FALSE (0)

#define DEQUE_SIZE (5)

void init_deque(void);
int is_empty_deque(void);
int is_full_deque(void);
void add_rear(int data);
void add_front(int data);
int delete_rear(void);
int delete_front(void);
int get_rear(void);
int get_front(void);
int peek(void);

#endif // QUEUE_H
