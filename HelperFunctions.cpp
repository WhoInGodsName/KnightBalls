#include <stdio.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <tuple>
#include "HelperFunctions.h"
#define _USE_MATH_DEFINES
#include "math.h"


wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

char* convertStringToCharArray(std::string string) {
    const int length = string.length();
    char* char_array = new char[length + 1];
    strcpy_s(char_array, sizeof(char_array), string.c_str());
    return char_array;

}

wchar_t* convertStringToLPCWSTR(std::string string) {
    return convertCharArrayToLPCWSTR(convertStringToCharArray(string));
}

const int WINDOW_W = 2560;
const int WINDOW_H = 1440;

double** MakeVArr(float x, float y, float z) {
	double rad_pitch = ((double)x * M_PI / 180);
	double rad_yaw = ((double)y * M_PI / 180);
	double rad_roll = ((double)z * M_PI / 180);

	double sin_pitch = sin(rad_pitch);
	double cos_pitch = cos(rad_pitch);
	double sin_yaw = sin(rad_yaw);
	double cos_yaw = cos(rad_yaw);
	double sin_roll = sin(rad_roll);
	double cos_roll = cos(rad_roll);

	double** arr = new double* [3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new double[3];
		for (int j = 0; j < 3; j++) {
			arr[i][j] = 0.0;
		}
	}

	arr[0][0] = cos_pitch * cos_yaw;
	arr[0][1] = cos_pitch * sin_yaw;
	arr[0][2] = sin_pitch;

	arr[1][0] = sin_roll * sin_pitch * cos_yaw - cos_roll * sin_yaw;
	arr[1][1] = sin_roll * sin_pitch * sin_yaw + cos_roll * cos_yaw;
	arr[1][2] = -sin_roll * cos_pitch;

	arr[2][0] = -(cos_roll * sin_pitch * cos_yaw + sin_roll * sin_yaw);
	arr[2][1] = cos_yaw * sin_roll - cos_roll * sin_pitch * sin_yaw;
	arr[2][2] = cos_roll * cos_pitch;

	return arr;
}

double Dot(std::tuple<double, double, double> arr1, std::tuple<double, double, double> arr2) {
	return std::get<0>(arr1) * std::get<0>(arr2) + std::get<1>(arr1) * std::get<1>(arr2) + std::get<2>(arr1) * std::get<2>(arr2);
}

Vector2 ToScreen(Vector3 playerCoords, Vector3 player_camera, Vector3 actorCoords, float playerFOV) {

	auto vMatrix = MakeVArr(player_camera.x, player_camera.y, player_camera.z);

	std::tuple<double, double, double> v_axis_x = std::make_tuple(vMatrix[0][0], vMatrix[0][1], vMatrix[0][2]);
	std::tuple<double, double, double> v_axis_y = std::make_tuple(vMatrix[1][0], vMatrix[1][1], vMatrix[1][2]);
	std::tuple<double, double, double> v_axis_z = std::make_tuple(vMatrix[2][0], vMatrix[2][1], vMatrix[2][2]);

	std::tuple<double, double, double> v_delta = std::make_tuple((double)actorCoords.x - (double)playerCoords.x,
		(double)actorCoords.y - (double)playerCoords.y,
		(double)actorCoords.z - (double)playerCoords.z);

	double* v_transformed = new double[3] { Dot(v_delta, v_axis_y),
		Dot(v_delta, v_axis_z),
		Dot(v_delta, v_axis_x)};

	double screen_center_x = WINDOW_W / 2;
	double screen_center_y = WINDOW_H / 2;

	double fov = tan(playerFOV * M_PI / 360);

	double x = screen_center_x + v_transformed[0] * (screen_center_x / fov)
		/ v_transformed[2];
	double y = screen_center_y - v_transformed[1] * (screen_center_x / fov)
		/ v_transformed[2];

	if (v_transformed[2] < 1.0)
	{
		// If it is, we need to do a different calculation to get the correct screen position
		x = screen_center_x + v_transformed[0] * (screen_center_x / fov)
			/ 1.0;
		y = screen_center_y - v_transformed[1] * (screen_center_x / fov)
			/ 1.0;
		// Some issue with this calculation causes it to point up or down instead of the opposite way at certain vertical angles
	}

	if (x > WINDOW_W) x = WINDOW_W;
	if (x < 0) x = 0;
	if (y > WINDOW_H) y = WINDOW_H;
	if (y < 0) y = 0;

	auto screen_pos = new Vector2;
	screen_pos->x = x;
	screen_pos->y = y;

	return *screen_pos;
}