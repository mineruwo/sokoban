#include "stdafx.h"
#include "Renderer.h"


#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE] = {
	"***********",
	"* Sokoban *",
	"***********"
};
static HANDLE s_consleHandle;

bool InitalizeRenderer()
{
	s_consleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consleHandle)
	{
		return false;
	}

	/*CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;

	if (false == SetConsoleCursorInfo(s_consleHandle, &info))
	{
		return false;
	}*/

	return true;
}

void RenderMap()
{
	const static COORD initailPos = {0,0};
	const static CONSOLE_CURSOR_INFO info = { 100, false };
	
	SetConsoleCursorPosition(s_consleHandle, initailPos);
	SetConsoleCursorInfo(s_consleHandle, &info);
	
	/*memcpy(s_map, s_backBuffer,sizeof(s_map));*/

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]);
	}

}