#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    // get notepad handle
    HWND hNotepad = FindWindowA("Notepad", NULL);
    if (!hNotepad) {
        cout << "notepad is not running" << endl;
        return 1;
    }
    
    return 0;
}
