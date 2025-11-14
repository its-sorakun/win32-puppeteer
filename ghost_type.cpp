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

    // find the child edit control inside notepad
    // user32 routes messages to specific child window handles, not the parent frame
    HWND hEdit = FindWindowExA(hNotepad, NULL, "Edit", NULL);
    if (!hEdit) {
        cout << "could not find edit control" << endl;
        return 1;
    }

    // inject a single character directly into the message queue
    // WM_CHAR bypasses the physical keyboard state and input focus entirely
    SendMessageA(hEdit, WM_CHAR, 'x', 0);
    
    return 0;
}
