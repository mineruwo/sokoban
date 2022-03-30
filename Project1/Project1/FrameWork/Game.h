#pragma once

#include <stdint.h>
#include <stdbool.h>

///<summary>
///게임과 관련된 데이터 초기화 한다.
///</summary>
/// <return> 정상적으로 초기화 되면Ture, 아니면 flase </return>

bool Initialize();

///<summary>
///게임을 동작 시킨다.
///</summary>
/// <return> 정상적으로 종료된다면 0 </return>
int32_t Run();
