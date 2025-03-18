#include "settingsReader.h"

using namespace std;


wchar_t* findFolder()
{
	//Поиск исходного файла
	char* buffer = new char[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, buffer); //Получаем текущую директорию и записываем ее
	CharToOemA(buffer, buffer);

	string re = buffer;
	string pathToSettings = re + "\\" + "settings.ini"; //Добавляем название файла к пути

	//Преобразуем std::string в std::wstring
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring widePath = converter.from_bytes(pathToSettings);

	// Выделяем память для результата
	wchar_t* result = new wchar_t[widePath.size() + 1];
	wcscpy_s(result, widePath.size() + 1, widePath.c_str());

	delete[] buffer;
	return result;
}

int readIniInt(wchar_t* folderPath) {
	wchar_t bufferForRead[256];
	int buttonId = 0;
	int value = GetPrivateProfileInt(L"Buttons", L"button", buttonId, folderPath);
	return value;
}

std::string readIniString(LPCWSTR folderPath) {
	//Чтение занчений из файла
	wchar_t bufferForRead[256];
	GetPrivateProfileString(L"BotToken", L"botToken", L"DefaultUser", bufferForRead, sizeof(bufferForRead), folderPath);
	// Преобразование wchar_t* в std::string
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string narrowStr = converter.to_bytes(bufferForRead);

	return narrowStr;
}


int main()
{
	wchar_t* folderPath = findFolder();
	int bb = readIniInt(folderPath);
	string token = readIniString(folderPath);


	std::wcout << folderPath << std::endl;
	cout << bb << "    " << token << endl;
	int b;
	cin >> b;
	return 0;
}



