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
/// 입력 상태를 업데이트 한다.
/// </summary>
void UpdateInput();

/// <summary>
/// 현재 프레임에 버튼이 눌렸는지 체크한다.
/// </summary>
/// <param name="_keyCode">가상 키 코드</param>
/// <returns>눌렸다면 True, 아니면 False</returns>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// 현재 프레임에 버튼이 때졌는지 체크한다.
/// </summary>
/// <param name="_keyCode">가상 키 코드</param>
/// <returns></returns>
bool GetButtonUp(EKeyCode keyCode);


/// <summary>
/// 현재 프레임에 눌려있는지 체크한다.
/// </summary>
/// <param name="_keyCode"></param>
/// <returns></returns>
bool GetButton(EKeyCode keyCode);

