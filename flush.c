#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "w"); // Open file for writing

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(file, "Hello, ");
    fflush(file); // Flush the buffer to write "Hello, " to the file immediately

    fprintf(file, "world!\n");
    fclose(file); // Close the file

    return 0;
}

