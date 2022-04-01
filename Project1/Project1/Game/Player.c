#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "../Framework/input.h"

bool PlayerMovemet(char s_map[][MAP_SIZE], SPos pos, char movedir, char *s_prevObject,int32_t* s_boxOnGoalCount)
{
	if (s_map[pos.posX][pos.posY] == MAPTYPE_WALL)
	{
		return false;
	}
	else if (s_map[pos.posX][pos.posY] == MAPTYPE_BOX)
	{
		SPos tagetPos;
		tagetPos.posX = pos.posX;
		tagetPos.posY = pos.posY;

		switch (movedir)
		{
		case KEYCODE_W:
			tagetPos.posX--;
			break;
		case KEYCODE_S:
			tagetPos.posX++;
			break;
		case KEYCODE_A:
			tagetPos.posY--;
			break;
		case KEYCODE_D:
			tagetPos.posY++;
			break;
		}
		if (BoxMovement(s_map, tagetPos, movedir,&s_boxOnGoalCount) == false)
		{
			return false;
		}
		else
		{
			s_map[pos.posX][pos.posY] = MAPTYPE_PLAYER;
		}
		*s_prevObject = MAPTYPE_PATH;
	}
	else if (s_map[pos.posX][pos.posY] == MAPTYPE_BOX_ON_GOAL)
	{
		SPos tagetPos;
		tagetPos.posX = pos.posX;
		tagetPos.posY = pos.posY;

		switch (movedir)
		{
		case KEYCODE_W:
			tagetPos.posX--;
			break;
		case KEYCODE_S:
			tagetPos.posX++;
			break;
		case KEYCODE_A:
			tagetPos.posY--;
			break;
		case KEYCODE_D:
			tagetPos.posY++;
			break;
		}
		if (BoxOnGoalMovement(s_map, tagetPos, movedir, &*s_boxOnGoalCount) == false)
		{
			return false;
		}
		else
		{
			s_map[pos.posX][pos.posY] = MAPTYPE_PLAYER;
		}
		*s_prevObject = MAPTYPE_GOAL;
	}
	else if (s_map[pos.posX][pos.posY] == MAPTYPE_GOAL)
	{
		*s_prevObject = MAPTYPE_GOAL;
	}
	else
	{
		*s_prevObject = MAPTYPE_PATH;
	}

	return true;
}