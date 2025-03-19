#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <WinBase.h>
#include <locale>
#include <codecvt>



wchar_t* findFolder();
int readIniInt(const wchar_t* section, const wchar_t* param, wchar_t* folderPath);
std::string readIniString(const wchar_t* section, const wchar_t* param, LPCWSTR folderPath);
