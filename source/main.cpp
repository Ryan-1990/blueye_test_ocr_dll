/*
* Blueye Copyright 2020 (c). All rights reserved.
*
* test OCR DLL
*
* @author  Nan Li
* @since   July 2020
*/

#include <iostream>
#include <windows.h>

using namespace std;

typedef  void (*lpShowDlg)(void);

int main()
{
	HINSTANCE hDll;
	hDll = LoadLibrary("digit_ocr.dll");
	if (NULL == hDll)
	{
		cout << "load dll error!" << endl;
	}
	lpShowDlg pShowDlg = (lpShowDlg)GetProcAddress(hDll, "showDlg");
	if (NULL == pShowDlg)
	{
		cout << "no function!" << endl;
	}
	else
	{
		pShowDlg();
	}
	FreeLibrary(hDll);
	return 0;
}