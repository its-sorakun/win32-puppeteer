# Ghost UI Automator

Most UI automation tools (like PyAutoGUI or Selenium) work by hijacking the physical mouse and keyboard state. This forces the target window to be in the foreground, taking over the machine.

This project drops down to the `User32.dll` API to interact with the Window Manager directly. By using `FindWindowEx` to locate specific child control handles, we can inject `WM_CHAR` or `WM_COMMAND` window messages directly into the application's event queue using `SendMessage`.

Because the messages are placed directly in the queue, the physical keyboard state and input focus are bypassed entirely. The target application processes the typing as if it were real, even if the window is minimized or hidden off-screen.

## Compilation
```powershell
g++ -o ghost_type.exe ghost_type.cpp
```
