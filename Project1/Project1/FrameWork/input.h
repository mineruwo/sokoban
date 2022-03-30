#pragma once

#include <stdint.h>

typedef enum keyCode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd'
}EKeyCode;


/// <summary>
/// �Է� ���¸� ������Ʈ �Ѵ�.
/// </summary>
void UpdateInput();

/// <summary>
/// ���� �����ӿ� ��ư�� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name="_keyCode">���� Ű �ڵ�</param>
/// <returns>���ȴٸ� True, �ƴϸ� False</returns>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="_keyCode">���� Ű �ڵ�</param>
/// <returns></returns>
bool GetButtonUp(EKeyCode keyCode);


/// <summary>
/// ���� �����ӿ� �����ִ��� üũ�Ѵ�.
/// </summary>
/// <param name="_keyCode"></param>
/// <returns></returns>
bool GetButton(EKeyCode keyCode);

