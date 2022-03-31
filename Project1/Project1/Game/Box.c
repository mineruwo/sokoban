#include "stdafx.h"
#include "Box.h"

bool BoxMovement(char s_map[][MAP_SIZE], SPos pos)
{
	if (s_map[pos.posX][pos.posY] == MAPTYPE_WALL || s_map[pos.posX][pos.posY] == MAPTYPE_BOX)
	{
		return false;
	}
	else if (s_map[pos.posX][pos.posY] == MAPTYPE_GOAL)
	{
		s_map[pos.posX][pos.posY] = MAPTYPE_BOX_ON_GOAL;
	}
	else if(s_map[pos.posX][pos.posY] == MAPTYPE_PATH)
	{
		s_map[pos.posX][pos.posY] = MAPTYPE_BOX;
	}

	return true;
}