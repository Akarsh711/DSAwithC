#include<stdio.h>
#include<windows.h>

int main(void){
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// allocte memeory using ZeroMemory Functioin
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// create child process
	if(!CreateProcess(NULL,// use command line
		"C:\\Windows\\system32\\mspaint.exe",
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
		))
	{
		fprintf(stderr,"Create Process Failed");
		return -1;
	}
	// parent will wait for the child to complete
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");

	// close handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}