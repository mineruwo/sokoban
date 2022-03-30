#include "stdafx.h"
#include "FrameWork/Game.h"

int main(void)
{
	if (false == Initialize())
	{
		puts("게임을 로딩하는데 문제가 생겼습니다.\n");

		return 1;
	}

	return Run();
}