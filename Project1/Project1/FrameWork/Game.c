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
	//game loop�� ��ü�� Frame
	while (true)
	{
		//�Է� ó��
		ProcessInput();
		//������Ʈ
		Update();
		//������
		Render();
	}
}