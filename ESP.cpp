#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define _USE_MATH_DEFINES
#include "math.h"
#include "ESP.h"
#include "SDK.h"
#include "HelperFunctions.h"
#include "MinHook/MinHook.h"
#if _WIN64 
#pragma comment(lib, "MinHook/libMinHook.x64.lib")
#endif

uintptr_t GetActors(uintptr_t gameAssembly) {
	uintptr_t base = *(uintptr_t*)(gameAssembly + 0x01CA26E8);
	//uintptr_t p  
	//auto localPlayer = reinterpret_cast<PlayerData*>(gameAssembly);
	return base;
}


