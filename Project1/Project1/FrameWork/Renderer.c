#include "stdafx.h"
#include "Renderer.h"
#include "Game/Stage.h"
#include "Timer.h"



#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE];
static HANDLE s_consleHandle;

void clear()
{
	memset(s_map, ' ', sizeof(s_map));

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

bool InitalizeRenderer()
{
	s_consleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consleHandle)
	{
		return false;
	}

	
	return true;
}

void RenderMap()
{
	const static COORD initailPos = {0,0};
	const static CONSOLE_CURSOR_INFO info = { 100, false };
	
	SetConsoleCursorPosition(s_consleHandle, initailPos);
	SetConsoleCursorInfo(s_consleHandle, &info);

	const char** stage = GetMap();
	memcpy(s_map, stage, sizeof(s_map));


	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]);
	}

	clear();

}
}

void SetMessage(const char* message)
{
	strcpy_s(s_map[0],MAP_SIZE, message);
}
