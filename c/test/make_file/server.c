#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hPipe;
    char buffer[1024];
    DWORD bytesRead;

    // Create a named pipe
    hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MessagePipe", // Pipe name
        PIPE_ACCESS_INBOUND,        // Read-only access
        PIPE_TYPE_BYTE | PIPE_WAIT, // Byte-oriented, blocking mode
        1,                          // Max instances
        1024,                       // Output buffer size
        1024,                       // Input buffer size
        0,                          // Default timeout
        NULL);                      // Default security

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Failed to create pipe. Error: %ld\n", GetLastError());
        return 1;
    }

    printf("Waiting for client connection...\n");

    // Wait for a client to connect
    if (ConnectNamedPipe(hPipe, NULL) == 0) {
        printf("Failed to connect to pipe. Error: %ld\n", GetLastError());
        CloseHandle(hPipe);
        return 1;
    }

    printf("Client connected. Waiting for messages...\n");

    while (1) {
        // Read messages from the pipe
        if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
            buffer[bytesRead] = '\0'; // Null-terminate the string
            printf("Message received: %s\n", buffer);
        } else {
            printf("Failed to read from pipe. Error: %ld\n", GetLastError());
            break;
        }
    }

    CloseHandle(hPipe);
    return 0;
}
