#include "stdafx.h"
#include "Stage.h"

typedef struct tagStage
{
	char Map[];
};

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

}