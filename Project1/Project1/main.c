#include "stdafx.h"
#include "FrameWork/Game.h"

int main(void)
{
	if (false == Initialize())
	{
		puts("������ �ε��ϴµ� ������ ������ϴ�.\n");

		return 1;
	}

	return Run();
}