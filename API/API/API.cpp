// API.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include <ctime>
using namespace std;
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
int main()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;
    // convert now to tm struct for UTC
    tm* gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is:" << dt << endl;
    SYSTEMTIME time;
    LPSYSTEMTIME a;
    //time = GetSystemTime(a);
    DisableCtrButton(1, 1, 1);
    return 0;
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, L"Test", L"TOag", MB_OK);
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
