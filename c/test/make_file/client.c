#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hPipe;
    char buffer[1024];
    DWORD bytesWritten;

    // Connect to the named pipe
    hPipe = CreateFile(
        "\\\\.\\pipe\\MessagePipe", // Pipe name
        GENERIC_WRITE,              // Write-only access
        0,                          // No sharing
        NULL,                       // Default security
        OPEN_EXISTING,              // Open existing pipe
        0,                          // Default attributes
        NULL);                      // No template file

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Failed to connect to pipe. Error: %ld\n", GetLastError());
        return 1;
    }

    printf("Connected to server. Type messages to send:\n");

    while (1) {
        // Get input from the user
        fgets(buffer, sizeof(buffer), stdin);

        // Remove trailing newline character
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Write the message to the pipe
        if (!WriteFile(hPipe, buffer, strlen(buffer), &bytesWritten, NULL)) {
            printf("Failed to write to pipe. Error: %ld\n", GetLastError());
            break;
        }

        printf("Message sent: %s\n", buffer);
    }

    CloseHandle(hPipe);
    return 0;
}
