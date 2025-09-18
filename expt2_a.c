#include <stdio.h>
#include <string.h>

int main() {
    char input[50], stuffed[100];
    char insertChar;
    int pos, i = 0, j = 0, len;

    // Input data
    printf("Enter input string (without spaces): ");
    scanf("%49s", input);

    len = strlen(input);

    // Get position to insert new character
    do {
        printf("Enter position to insert character (1 to %d): ", len + 1);
        scanf("%d", &pos);
        if (pos < 1 || pos > len + 1)
            printf("Invalid position. Try again.\n");
    } while (pos < 1 || pos > len + 1);

    // Get character to insert
    printf("Enter the character to insert at position %d: ", pos);
    while ((getchar()) != '\n'); // Clear buffer
    insertChar = getchar();

    // Start frame with DLESTX
    strcpy(stuffed, "DLESTX");
    j = strlen(stuffed);

    for (i = 0; i < len; i++) {
        // If current position is where we want to insert
        if (i == pos - 1) {
            // Insert DLE + insertChar + DLE
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
            stuffed[j++] = insertChar;
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
        }

        // Copy original input character
        stuffed[j++] = input[i];
    }

    // If insert at end
    if (pos == len + 1) {
        stuffed[j++] = 'D';
        stuffed[j++] = 'L';
        stuffed[j++] = 'E';
        stuffed[j++] = insertChar;
        stuffed[j++] = 'D';
        stuffed[j++] = 'L';
        stuffed[j++] = 'E';
    }

    // End frame with DLEETX
    stuffed[j++] = 'D';
    stuffed[j++] = 'L';
    stuffed[j++] = 'E';
    stuffed[j++] = 'E';
    stuffed[j++] = 'T';
    stuffed[j++] = 'X';

    // Null terminate the final string
    stuffed[j] = '\0';

    // Output stuffed frame
    printf("\nFrame after stuffing:\n%s\n", stuffed);

    return 0;
}

