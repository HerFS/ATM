#include <stdio.h>

#define UP (72)
#define DOWN (80)
#define SUBMIT (0)

typedef enum choice
{
	CHOICE_WRITE,
	CHOICE_DELETE,
	CHOICE_UPDATE,
	CHOICE_EXIT
};

int menu();
int input_key();
int move_arrow();
void draw_menu();
