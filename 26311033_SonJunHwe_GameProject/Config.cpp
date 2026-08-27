#include <cstdio>
#include <glc2d.h>
#include "Config.h"

// link the 2d game library
#if defined(_DEBUG)
#if defined(_M_X64) // 64-bit 아키텍처
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86) // 32-bit 아키텍처
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

#define TEST_TEXTURE "Texture/tst.png"

int nTx;
int Render()
{
    VEC2 pos(400, 200);

    g2_Draw2D(nTx, NULL, &pos);

    return 0;
}

void RenderWindow()
{
    // SDK 초기화
    g2_InitSdk();

    printf("Starting ...\n\n");

    // 윈도우 생성
    g2_CreateWin(100, 100, 1024, 600, "My First Game Window");

    // 실행
    g2_Run();

    // 윈도우 해제
    g2_DestroyWin();
}

void RenderImage()
{
    g2_InitSdk();

    // 배경색 설정
    g2_SetClearColor(0xFF336699);

    // 화면 출력 함수 등록
    g2_SetRender(Render);

    g2_CreateWin(100, 100, 800, 600, "Texture");

    // 텍스처 로드
    nTx = g2_TextureLoad(TEST_TEXTURE);

    g2_Run();

    // 텍스처 해제
    g2_TextureRelease(nTx);

    g2_DestroyWin();

    return;
}