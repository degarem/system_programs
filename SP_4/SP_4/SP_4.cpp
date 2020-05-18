#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

#define MAX_PATH_SYMBOL_COUNT 260
#define MAX_COMMANMD_SYMBOL_COUNT 10

void perfrom_command(wstring command, wstring parameter);
bool is_file_exists(wstring path);

int wmain(int argc, wchar_t *argv[])
{
	printf("\n* Archivator *\n\n");

	wstring command, parameter;
	WCHAR input[MAX_PATH_SYMBOL_COUNT + MAX_COMMANMD_SYMBOL_COUNT + 2];

	do {
		wcin.getline(input, sizeof input);
		wstring input_wstr = input;

		int end_command_index = input_wstr.find(L" ");
		command = input_wstr.substr(0, end_command_index);
		parameter = input_wstr.substr(end_command_index + 1);

		perfrom_command(command, parameter);
	} while (command.compare(L"exit") != 0);

    return 0;
}

void perfrom_command(wstring command, wstring parameter) {
	wprintf(L"\n");

	if (command.compare(L"zip") == 0) {
		zip_file()
	}
	else if (command.compare(L"unzip") == 0) {
		
	}
	else {
		wprintf(L"Incorrect command. Use:\nzip <path> for zipping\nunzip<path> for unzipping\n");
	}
}
