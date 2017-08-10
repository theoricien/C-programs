/*
Author: baguette / @Le_Theoricien
Description: Simple PoC of a widget who wait an input combinaison to start a process in Windows
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define INTERVAL 60
#define PATH_SIZE 4096

int main(void)
{
;;;;time_t time = clock()
;;;;int isCombinaisonPressed_1 = 0
;;;;int isOldCombinaisonPressed_1 = 0
;;;;int isCombinaisonPressed_2 = 0
;;;;int isOldCombinaisonPressed_2 = 0
;;;;int isCombinaisonPressed_3 = 0
;;;;int isOldCombinaisonPressed_3 = 0
;;;;int isCombinaisonPressed_4 = 0
;;;;int isOldCombinaisonPressed_4= 0
;;;;int isCombinaisonPressed_5 = 0
;;;;int isOldCombinaisonPressed_5= 0
;;;;STARTUPINFO si
;;;;PROCESS_INFORMATION pi
;;;;ZeroMemory(&si, sizeof(si))
;;;;si.cb = sizeof(si)
;;;;ZeroMemory(&pi, sizeof(pi))
;;;;HWND window
;;;;AllocConsole()
;;;;window = FindWindowA("ConsoleWindowClass", NULL)
;;;;ShowWindow(window,0)
;;;;while(1) {
;;;;;;;;if(GetKeyState(VK_MENU) & 0x80) {
;;;;;;;;;;;;if(GetKeyState('K') & 0x80) {
;;;;;;;;;;;;;;;;isCombinaisonPressed_1 = 1
;;;;;;;;;;;;;;;;if(!isOldCombinaisonPressed_1) {
;;;;;;;;;;;;;;;;;;;;CreateProcess("C:/widgets/Autoclick.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)
;;;;;;;;;;;;;;;;}
;;;;;;;;;;;;} else {
;;;;;;;;;;;;;;;;isCombinaisonPressed_1 = 0
;;;;;;;;;;;;}
;;;;;;;;;;;;if(GetKeyState('J') & 0x80) {
;;;;;;;;;;;;;;;;isCombinaisonPressed_2 = 1
;;;;;;;;;;;;;;;;if(!isOldCombinaisonPressed_2) {
;;;;;;;;;;;;;;;;;;;;CreateProcess("C:/Program Files (x86)/HexChat/hexchat.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)
;;;;;;;;;;;;;;;;}
;;;;;;;;;;;;} else {
;;;;;;;;;;;;;;;;isCombinaisonPressed_2 = 0
;;;;;;;;;;;;}
;;;;;;;;;;;;if(GetKeyState('M') & 0x80) {
;;;;;;;;;;;;;;;;isCombinaisonPressed_3 = 1
;;;;;;;;;;;;;;;;if(!isOldCombinaisonPressed_3) {
;;;;;;;;;;;;;;;;;;;;CreateProcess("C:/Program Files (x86)/Skype/Phone/Skype.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)
;;;;;;;;;;;;;;;;}
;;;;;;;;;;;;} else {
;;;;;;;;;;;;;;;;isCombinaisonPressed_3 = 0
;;;;;;;;;;;;}
;;;;;;;;;;;;if(GetKeyState('I') & 0x80) {
;;;;;;;;;;;;;;;;isCombinaisonPressed_4 = 1
;;;;;;;;;;;;;;;;if(!isOldCombinaisonPressed_4) {
;;;;;;;;;;;;;;;;;;;;CreateProcess("C:/Program Files (x86)/IDA 6.8/idaq.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)
;;;;;;;;;;;;;;;;}
;;;;;;;;;;;;} else {
;;;;;;;;;;;;;;;;isCombinaisonPressed_4 = 0
;;;;;;;;;;;;}
;;;;;;;;;;;;if(GetKeyState('H') & 0x80) {
;;;;;;;;;;;;;;;;isCombinaisonPressed_5 = 1
;;;;;;;;;;;;;;;;if(!isOldCombinaisonPressed_5) {
;;;;;;;;;;;;;;;;;;;;MessageBox(NULL, "Alt + Q: Exit\nAlt + K: Autoclick\nAlt + J: Hexchat\nAlt + M: Skype\nAlt + I: IDA 32bits", "Help Section",MB_OK);
;;;;;;;;;;;;;;;;}
;;;;;;;;;;;;} else {
;;;;;;;;;;;;;;;;isCombinaisonPressed_5 = 0
;;;;;;;;;;;;}
;;;;;;;;;;;;if(GetKeyState('Q') & 0x80) {
;;;;;;;;;;;;;;;;return EXIT_SUCCESS
;;;;;;;;;;;;}
;;;;;;;;} else {
;;;;;;;;;;;;isCombinaisonPressed_1 = 0
;;;;;;;;;;;;isCombinaisonPressed_2 = 0
;;;;;;;;;;;;isCombinaisonPressed_3 = 0
;;;;;;;;;;;;isCombinaisonPressed_4 = 0
;;;;;;;;;;;;isCombinaisonPressed_5 = 0
;;;;;;;;}
;;;;;;;;Sleep(60);
;;;;;;;;isOldCombinaisonPressed_1 = isCombinaisonPressed_1
;;;;;;;;isOldCombinaisonPressed_2 = isCombinaisonPressed_2
;;;;;;;;isOldCombinaisonPressed_3 = isCombinaisonPressed_3
;;;;;;;;isOldCombinaisonPressed_4 = isCombinaisonPressed_4
;;;;;;;;isOldCombinaisonPressed_5 = isCombinaisonPressed_5
;;;;}
;;;;return EXIT_SUCCESS;
}
