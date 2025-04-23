#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>
#include <io.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>

void main() {
    int fd;
    char buffer[100];
    int bytesRead;

    clrscr();

    // Simulate open using Turbo C _open()
    fd = open("sample.txt", O_RDONLY);
    if (fd < 0) {
        printf("Error opening file\n");
        getch();
        return;
    }

    // Simulate read
    bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';  // null-terminate the string
    printf("File Content:\n%s\n", buffer);

    // Simulate close
    close(fd);

    // Display process-related information using Turbo C-compatible functions
    printf("\nSimulated Process/User Information:\n");
    printf("Process ID (simulated): %u\n", getpid()); // Note: Turbo C doesn't support actual process IDs
    printf("Current Directory: %s\n", getcwd(NULL, 80));

    getch();
}
