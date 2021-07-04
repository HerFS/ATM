#include "diary.h"

diary_data_t g_diary_data[COUNT];
int g_count = 0;

int load_diary()
{
	FILE* diary_file = fopen("diary.txt", "a+");
	
	char buffer[BUFFER_SIZE];

	if (diary_file == NULL)
	{
		return FALSE;
	}

	while (fgets(buffer, BUFFER_SIZE, diary_file) != NULL)
	{
		fgets(buffer, BUFFER_SIZE, diary_file);
		sscanf(buffer, "날짜:%04d년%02d월%02d일 날씨:%s 제목:%s 내용:%s", &g_diary_data[g_count].date.year, &g_diary_data[g_count].date.month, &g_diary_data[g_count].date.day, g_diary_data[g_count].weather, g_diary_data[g_count].title, g_diary_data[g_count].contents);
		
		xor_calculate(&g_diary_data[g_count].date.year, &g_diary_data[g_count].date.month, &g_diary_data[g_count].date.day, g_diary_data[g_count].weather, g_diary_data[g_count].title, g_diary_data[g_count].contents);

		g_count++;

	}

	fclose(diary_file);

	return TRUE; 
}

void write_diary()
{
	FILE* diary_file = fopen("diary.txt", "a");

	if (diary_file == NULL && load_diary() == FALSE)
	{	
		assert(0);
	}

	while (1)
	{
		printf("날짜 입력 (yyyy mm dd)\n-> ");
		scanf("%d %d %d", &g_diary_data[g_count].date.year, &g_diary_data[g_count].date.month, &g_diary_data[g_count].date.day);
		if (g_diary_data[g_count].date.year < 10000 && g_diary_data[g_count].date.month < 13 && g_diary_data[g_count].date.day < 32)
		{
			break;
		}
	}

	unsigned int choice_weather;
		
	while (1)
	{
		printf("날씨 입력 (1. SUNNY, 2. CLOUD, 3. RAINING, 4. SNOWING)\n-> ");
		scanf("%d", &choice_weather);

		switch (choice_weather)
		{
		case WEATHER_SUNNY:
			strcpy(g_diary_data[g_count].weather, "Sunny");
			break;
		case WEATHER_CLOUD:
			strcpy(g_diary_data[g_count].weather, "Cloud");
			break;
		case WEATHER_RAINING:
			strcpy(g_diary_data[g_count].weather, "Raining");
			break;
		case WEATHER_SNOWING:
			strcpy(g_diary_data[g_count].weather, "Snowing");
			break;
		default:
			break;
		}

		if (choice_weather < 5)
		{
			break;
		}
	}

	while (1)
	{
		printf("제목 입력 : ");
		scanf("%s", g_diary_data[g_count].title);
		if (strlen(g_diary_data[g_count].title) < TITLE_LENGTH)
		{
			break;
		}
	}

	while (1)
	{
		printf("내용\n");
		scanf("%s", g_diary_data[g_count].contents);
		if (strlen(g_diary_data[g_count].contents) < CONTENTS_LENGTH)
		{
			break;
		}
	}
	
	xor_calculate(&g_diary_data[g_count].date.year, &g_diary_data[g_count].date.month, &g_diary_data[g_count].date.day, g_diary_data[g_count].weather, g_diary_data[g_count].title, g_diary_data[g_count].contents);

	fprintf(diary_file, "날짜:%04d년%02d월%02d일 날씨:%s 제목:%s 내용:%s\n", g_diary_data[g_count].date.year, g_diary_data[g_count].date.month, g_diary_data[g_count].date.day, g_diary_data[g_count].weather, g_diary_data[g_count].title, g_diary_data[g_count].contents);

	fclose(diary_file);

	printf("저장 완료");
}

void delete_diary()
{
	load_diary();
	unsigned int delete_file = 0;
	
	FILE* diary_file = fopen("diary.txt", "w");

	if (diary_file == NULL && load_diary() == FALSE)
	{
		assert(0);
	}

	for (int i = 0; i < g_count; i++)
	{
		printf("%d. 제목 : %s\n", i + 1, g_diary_data[i].title);
	}

	while (1)
	{
		scanf("%d", &delete_file);

		if (delete_file < g_count - 1)
		{
			break;
		}
	}

	g_diary_data[delete_file].date.year = g_diary_data[g_count - 1].date.year;
	g_diary_data[delete_file].date.month = g_diary_data[g_count - 1].date.month;
	g_diary_data[delete_file].date.day = g_diary_data[g_count - 1].date.day;
	strcpy(g_diary_data[delete_file].weather, g_diary_data[g_count - 1].weather);
	strcpy(g_diary_data[delete_file].title, g_diary_data[g_count - 1].title);
	strcpy(g_diary_data[delete_file].contents, g_diary_data[g_count - 1].contents);
	
	g_count--;

	for (int i = 0; i < g_count - 1; i++)
	{
		xor_calculate(&g_diary_data[i].date.year, &g_diary_data[i].date.month, &g_diary_data[i].date.day, g_diary_data[i].weather, g_diary_data[i].title, g_diary_data[i].contents);
		fprintf(diary_file, "날짜:%04d년%02d월%02d일 날씨:%s 제목:%s 내용:%s\n", g_diary_data[i].date.year, g_diary_data[i].date.month, g_diary_data[i].date.day, g_diary_data[i].weather, g_diary_data[i].title, g_diary_data[i].contents);
	}

	fclose(diary_file);
}

void update_diary()
{
	load_diary();
	FILE* diary_file = fopen("diary.txt", "w");

	if (diary_file == NULL && load_diary() == FALSE)
	{
		assert(0);
	}

	for (int i = 0; i < g_count; i++)
	{
		printf("%d. 제목 : %s\n", i + 1, g_diary_data[i].title);
	}
	
	int choice;
	while (1)
	{
		scanf("%d", &choice - 1);
		if (choice < g_count)
		{
			break;
		}
	}

	while (1)
	{
		printf("날짜 입력 (yyyy mm dd)\n-> ");
		scanf("%d %d %d", &g_diary_data[choice - 1].date.year, &g_diary_data[choice - 1].date.month, &g_diary_data[choice - 1].date.day);
		if (g_diary_data[choice - 1].date.year < 10000 && g_diary_data[choice - 1].date.month < 13 && g_diary_data[choice - 1].date.day < 32)
		{
			break;
		}
	}

	unsigned int choice_weather;

	while (1)
	{
		printf("날씨 입력 (1. SUNNY, 2. CLOUD, 3. RAINING, 4. SNOWING)\n-> ");
		scanf("%d", &choice_weather);

		switch (choice_weather)
		{
		case WEATHER_SUNNY:
			strcpy(g_diary_data[choice - 1].weather, "Sunny");
			break;
		case WEATHER_CLOUD:
			strcpy(g_diary_data[choice - 1].weather, "Cloud");
			break;
		case WEATHER_RAINING:
			strcpy(g_diary_data[choice - 1].weather, "Raining");
			break;
		case WEATHER_SNOWING:
			strcpy(g_diary_data[choice - 1].weather, "Snowing");
			break;
		default:
			break;
		}

		if (choice_weather < 5)
		{
			break;
		}
	}

	while (1)
	{
		printf("제목 입력 : ");
		scanf("%s", g_diary_data[choice - 1].title);
		if (strlen(g_diary_data[choice - 1].title) < TITLE_LENGTH)
		{
			break;
		}
	}

	while (1)
	{
		printf("내용\n");
		scanf("%s", g_diary_data[choice - 1].contents);
		if (strlen(g_diary_data[choice - 1].contents) < CONTENTS_LENGTH)
		{
			break;
		}
	}

	for (int i = 0; i < g_count - 1; i++)
	{
		xor_calculate(&g_diary_data[i].date.year, &g_diary_data[i].date.month, &g_diary_data[i].date.day, g_diary_data[i].weather, g_diary_data[i].title, g_diary_data[i].contents);
		fprintf(diary_file, "날짜:%04d년%02d월%02d일 날씨:%s 제목:%s 내용:%s\n", g_diary_data[i].date.year, g_diary_data[i].date.month, g_diary_data[i].date.day, g_diary_data[i].weather, g_diary_data[i].title, g_diary_data[i].contents);
	}

	fclose(diary_file);
}
