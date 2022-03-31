#include "stdafx.h"
#include "Stage.h"

static char s_map[MAP_SIZE][MAP_SIZE];

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };

	sprintf_s(path, sizeof(path), "Stage/Stage%02d", (int32_t)level);

	FILE* fp = NULL;

	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);
			if (ch == '\n')
			{
				break;
			}
			s_map[i][j] = ch;
	}
	}

	fclose(fp);
}

const char** GetMap()
{
	return s_map;
}