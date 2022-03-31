#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Timer.h"

bool Initialize()
{
	if (false == InitalizeRenderer())
	{
		return false;
	}

	InitializeTimer();

	return true;
}

void ProcessInput()
{
	UpdateInput();
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
		UpdateTimer();
		//입력 처리
		ProcessInput();
		//업데이트
		Update();
		//렌더링
		Render();
	}
}