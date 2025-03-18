# SIMPLE-INI-FILE-READER
Код можно будет интегрировать в другие программы
```ini
[Section 1]
param1=1
param2="Token"
```
```C++
int value = GetPrivateProfileInt(L"Buttons", L"button", buttonId, folderPath); // 1 Перегрузка ищет секцию, 2 параметр, 3 считывает парметр, 4 путь к файлу


GetPrivateProfileString(L"BotToken", L"botToken", L"DefaultUser", bufferForRead, sizeof(bufferForRead), folderPath); // 1 Перегрузка ищет секцию, 2 параметр, 3 если не удалось найти данные, то остаеться DefaultUser 4 считывает парметр, 6 путь к файлу
```
