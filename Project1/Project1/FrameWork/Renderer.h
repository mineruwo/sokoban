#pragma once
#include <stdbool.h>

/// <summary>
/// 랜더러를 초기화 한다.
/// </summary>
/// <returns>초기화 성공이면 Ture, 아니면 False</returns>
bool InitalizeRenderer();

/// <summary>
/// 맵을 그린다.
/// </summary>
/// <returns></returns>
void RenderMap();