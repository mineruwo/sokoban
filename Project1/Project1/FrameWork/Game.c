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
	//game loop�� ��ü�� Frame
	while (true)
	{
		UpdateTimer();
		//�Է� ó��
		ProcessInput();
		//������Ʈ
		Update();
		//������
		Render();
	}
}