#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "../Framework/input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;
static EStageLevel s_currentLevel = 0;
static char s_prevObject = MAPTYPE_PATH;

bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\n'|| mapType == '\0')
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
		s_goalCount++;
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
	if (level == STAGE_MAX)
	{
		system("cls");
		puts("게임 올 클리어");
		exit(1);
	}
	assert(STAGE_01 <= level && level < STAGE_MAX);
	s_currentLevel = level;

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
	s_map[s_playerX][s_playerY] = s_prevObject;
	SPos tagetPos = { s_playerX, s_playerY };
	char movedir = 0;

	if (GetButtonDown(KEYCODE_W))
	{
		tagetPos.posX--;
		movedir = KEYCODE_W;
	}
	else if (GetButtonDown(KEYCODE_S))
	{
		tagetPos.posX++;
		movedir = KEYCODE_S;
	}
	else if (GetButtonDown(KEYCODE_A))
	{
		tagetPos.posY--;
		movedir = KEYCODE_A;
	}
	else if (GetButtonDown(KEYCODE_D))
	{
		tagetPos.posY++;
		movedir = KEYCODE_D;
	}

	if (PlayerMovemet(s_map, tagetPos, movedir,&s_prevObject,&s_boxOnGoalCount))
	{

		s_playerX = tagetPos.posX;
		s_playerY = tagetPos.posY;

		s_map[s_playerX][s_playerY] = MAPTYPE_PLAYER;
	}
	
	
	if (s_goalCount == s_boxOnGoalCount)
	{
		
		LoadStage(++s_currentLevel);

	}//게임이 클리어 됬는지 확인하는 조건문
}

const char** GetMap()
{
	return s_map;
}