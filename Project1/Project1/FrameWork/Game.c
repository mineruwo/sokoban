#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Timer.h"
#include "Game/Stage.h"

bool Initialize()
{
	if (false == InitalizeRenderer())
	{
		return false;
	}
	return true;
	
	IntitalizeTimer();

	LoadStage(STAGE_01);
}

void ProcessInput()
{


}

void Update()
{


}

void Render()
{
	RenderMap();

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