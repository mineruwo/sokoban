#include "stdafx.h"
#include "Stage.h"
#include "../Framework/input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\n')
	{
		return false;
	}

	s_map[i][j] = mapType;

	switch (mapType)
	{
	case MAPTYPE_PLAYER :
		s_playerX = i;
		s_playerY = j;
		break;
	case MAPTYPE_GOAL:
		s_goalCount++;

		break;
	case MAPTYPE_BOX_ON_GOAL:
		s_boxOnGoalCount++;
		break;
	}


}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}

		if (feof(fp))
		{
			break;
		}
	}
	
	fclose(fp);
}

void UpdateStage()
{
	if(GetButton(KEYCODE_W))
	{
		s_playerY--;
	}
	else if (GetButton(KEYCODE_D))
	{
		s_playerX++;
	}
	else if (GetButton(KEYCODE_S))
	{
		s_playerY++;
	}
	else if (GetButton(KEYCODE_A))
	{
		s_playerX--;
	}

	if (s_goalCount == s_boxOnGoalCount)
	{
		return 0;
	}
}

const char** GetMap()
{
	return s_map;
}