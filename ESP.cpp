#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>  
#include <array> 

#define _USE_MATH_DEFINES
#include "math.h"
#include "ESP.h"
#include "SDK.h"
#include "HelperFunctions.h"
#include "MinHook/MinHook.h"
#if _WIN64 
#pragma comment(lib, "MinHook/libMinHook.x64.lib")
#endif

uintptr_t player_arr[] = {0xB8, 0x0};
Player* localPlayer;

uintptr_t GetActors(uintptr_t gameAssembly) {

	uintptr_t local_player;
	uintptr_t base = *(uintptr_t*)(gameAssembly + 0x01CA26E8);
	int array_size = std::end(player_arr) - std::begin(player_arr);

	local_player = base;
	for (int i = 0; i < array_size; i++) {
		local_player = *(uintptr_t*)(local_player + player_arr[i]);
	}
	  
	localPlayer = reinterpret_cast<Player*>(local_player);
	localPlayer->refs->movement->jumpForce = 100;
	localPlayer->stats->AmmoConsumption->baseValue = 0;
	localPlayer->stats->FireRate->baseValue = 0;
	
	return localPlayer->enteredFarms->tier;
}


