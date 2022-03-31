#pragma once

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'P',
	MAPTYPE_BOX = 'a',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOXONGOAL = '@',
	MAPTYPE_PATH = ' '
}EMapType; 

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
}EStageLevel;

/// <summary>
/// ���������� �ε��Ѵ�.
/// </summary>
void LoadStage(EStageLevel level);



/// <summary>
/// ���� ��ȯ�Ѵ�.
/// </summary>
const char** GetMap();