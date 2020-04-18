#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#define BYTES_IN_MEGABYTE_NUMBER 1048576

void printLastError();
void performErrorAndPrintInfo();
void printSystemInfo();

int main(int argc, char* argv[])
{

	if (argc == 1) {
		printf("No arguements\n");
		
		return 1;
	}

	if (!strcmp(argv[1], "-e")) {
		performErrorAndPrintInfo();
	}
	else if (!strcmp(argv[1], "-s")) {
		printSystemInfo();
	}
	else {
		printf("Incorrect arguements\n");
		
	}

	return 0;
}

void performErrorAndPrintInfo() {
	HANDLE handle = CreateFile(TEXT("Some\\error_path.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_NEW, 0, 0);
	if (handle == INVALID_HANDLE_VALUE) {
		printLastError();
	}
	CloseHandle(handle);
}

void printLastError() {
	LPVOID lpMsg;
	DWORD dwError;
	dwError = GetLastError();
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsg, 0, NULL);
	wprintf(L"Error Code:  %lu\n", dwError);
	wprintf(L" Message: %s", lpMsg);
	LocalFree(lpMsg);
}

void printSystemInfo() {
	SYSTEM_INFO siSysInf;
	MEMORYSTATUS lpMemStat;

	GetSystemInfo(&siSysInf);
	printf("\n*** System information ***\n\n");
	printf("Page Size: %u\n", siSysInf.dwPageSize);
	printf("Minimum Application Address: %u\n", siSysInf.lpMinimumApplicationAddress);
	printf("Maximum Application Address: %u\n", siSysInf.lpMaximumApplicationAddress);
	printf("A mask representing the set of processors configured into the system: %u\n", siSysInf.dwActiveProcessorMask);
	printf("The number of logical processors in the current group: %u\n", siSysInf.dwNumberOfProcessors);
	printf("Allocation Granularity: %u\n", siSysInf.dwAllocationGranularity);
	printf("Processor architecture code: %u\n", siSysInf.wProcessorArchitecture);
	printf("Processor level: %u\n", siSysInf.wProcessorLevel);
	printf("Processor revision: %u\n\n\n", siSysInf.wProcessorRevision);

	GlobalMemoryStatus(&lpMemStat);
	printf("*** Memory information ***\n\n");
	printf("MemoryStatus data structure size: %ld b\n", lpMemStat.dwLength);
	printf("Physical memory that is in use %ld%%.\n", lpMemStat.dwMemoryLoad);
	printf("Physical memory: %u MB\n", lpMemStat.dwTotalPhys / BYTES_IN_MEGABYTE_NUMBER);
	printf("Free physical memory: %u MB\n", lpMemStat.dwAvailPhys / BYTES_IN_MEGABYTE_NUMBER);
	printf("Committed memory limit: %u MB\n", lpMemStat.dwTotalPageFile / BYTES_IN_MEGABYTE_NUMBER);
	printf("Maximum amount of memory the current process can commit: %u MB\n", lpMemStat.dwAvailPageFile / BYTES_IN_MEGABYTE_NUMBER);
	printf("Virtual memory: %u MB\n", lpMemStat.dwTotalVirtual / BYTES_IN_MEGABYTE_NUMBER);
	printf("Free virtual memory: %u MB\n", lpMemStat.dwAvailVirtual / BYTES_IN_MEGABYTE_NUMBER);
}



