#include <windows.h>

int main() {
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(STARTUPINFO);

    if (CreateProcess(
            NULL,               // Application name (NULL means the command line will be used)
            "child_program.exe", // Command line
            NULL,               // Process attributes
            NULL,               // Thread attributes
            FALSE,              // Inherit handles
            0,                  // Creation flags
            NULL,               // Environment
            NULL,               // Current directory
            &si,                // Startup info
            &pi                 // Process information
        )) {
        printf("Child process created successfully\n");
        WaitForSingleObject(pi.hProcess, INFINITE);  // Wait for the child process to finish
    } else {
        printf("Failed to create child process\n");
    }

    return 0;
}
