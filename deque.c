#include "deque.h"
#include <assert.h>

static int s_deque[DEQUE_SIZE];
static int s_rear;
static int s_front;

void init_deque()
{
	s_rear = 0;
	s_front = 0;
}

int is_empty_deque()
{
	return (s_rear == s_front);
}

int is_full_deque()
{
	return (s_rear + 1 % DEQUE_SIZE == s_front);
}

void add_rear(int data)
{
	if (is_full_queue() == TRUE)
	{
		return;
	}

	s_rear = (s_rear + 1) % DEQUE_SIZE;

	s_deque[s_rear] = data;
}

void add_front(int data)
{
	if (is_full_queue() == TRUE)
	{
		return;
	}

	s_deque[s_front] = data;
	s_front = (s_front - 1 + DEQUE_SIZE) % DEQUE_SIZE;
}

int delete_rear()
{
	int prev = s_rear;
	if (is_empty_deque() == TRUE)
	{
		assert(0);
	}
	s_rear = (s_rear - 1 + DEQUE_SIZE) % DEQUE_SIZE;
	return s_deque[prev];
}

int delete_front()
{
	if (is_empty_deque() == TRUE)
	{
		assert(0);
	}
	s_front = (s_front + 1) % DEQUE_SIZE;
	return s_deque[s_front];
}

int get_rear()
{
	if (is_empty_deque() == TRUE)
	{
		assert(0);

		return s_deque[s_rear];
	}
}

int get_front()
{
	if (is_empty_deque() == TRUE)
	{
		assert(0);
	}
	return s_deque[(s_front + 1) % DEQUE_SIZE];
}
