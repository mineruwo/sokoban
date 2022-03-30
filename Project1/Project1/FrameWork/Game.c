#include "stdafx.h"
#include "Game.h"

bool Initalize()
{
	return true;
}

void ProcessInput()
{


}

void Update()
{


}

void Render()
{


}

int32_t Run()
{
	//game loop의 전체를 Frame
	while (true)
	{
		//입력 처리
		ProcessInput();
		//업데이트
		Update();
		//렌더링
		Render();
	}
}