#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE (1024)
#define WEATHER_LENGTH (10)
#define TITLE_LENGTH (21)
#define CONTENTS_LENGTH (100)
#define COUNT (100)
#define TRUE (1)
#define FALSE (0)

typedef enum weather
{
	WEATHER_SUNNY = 1,
	WEATHER_CLOUD,
	WEATHER_RAINING,
	WEATHER_SNOWING
}weather_t;

typedef struct date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
} date_t;

typedef struct diary_data
{
	date_t date;
	char weather[WEATHER_LENGTH];
	char title[TITLE_LENGTH];
	char contents[CONTENTS_LENGTH];
}diary_data_t;

int load_diary();
void write_diary();
void delete_diary();
void update_diary();

int input_key();

