#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <WinBase.h>
#include <locale>
#include <codecvt>



wchar_t* findFolder();
int readIniInt(wchar_t* folderPath);
std::string readIniString(LPCWSTR folderPath);