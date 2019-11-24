#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void openNotepad() {
	while (1) { //非0死循环，0不循环
		ShellExecuteA(0, "open", "notepad", 0, 0, 1);
		Sleep(3000);
	}
}

int main() {
	openNotepad();
	
	return 0;
}