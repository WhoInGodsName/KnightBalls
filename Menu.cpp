#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include "ESP.h"
#include "Menu.h"

#include "MinHook/MinHook.h"
#if _WIN64 
#pragma comment(lib, "MinHook/libMinHook.x64.lib")
#else
#pragma comment(lib, "MinHook/libMinHook.x86.lib")
#endif

//something

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

static bool fireRateToggle = false;
static bool spaceJumpToggle = false;
static bool horseSpeedToggle = false;

void MyMenu() {
	ImGui::Begin("Knights Balls");

	if (ImGui::Checkbox("Toggle firerate", &fireRateToggle)) {
		ToggleFireRate();
	}
	if (ImGui::Checkbox("Toggle Space Jump", &spaceJumpToggle)) {
		SpaceJump();
	}
	if (ImGui::Checkbox("Toggle Horse Speed", &horseSpeedToggle)) {
		HorseSpeed();
	}

	ImGui::End();
}
