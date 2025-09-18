#include <stdio.h>
#include <string.h>

void bitStuffing(char input[], char stuffed[]) {
int i = 0, j = 0, count = 0;

while (input[i] != '\0') {
stuffed[j++] = input[i];

if (input[i] == '1') {
count++;
if (count == 5) {
stuffed[j++] = '0'; // Stuff a 0 after five 1s
count = 0;
}
} else {
count = 0;
}
i++;
}
stuffed[j] = '\0';

}

void bitDeStuffing(char stuffed[], char destuffed[]) {
int i = 0, j = 0, count = 0;

while (stuffed[i] != '\0') {
destuffed[j++] = stuffed[i];

if (stuffed[i] == '1') {
count++;
if (count == 5) {
i++; // Skip the stuffed 0
count = 0;
}
} else {
count = 0;
}
i++;
}
destuffed[j] = '\0';
}

int main() {
char input[100], stuffed[150], destuffed[100];

printf("Enter the binary data: ");
scanf("%s", input);

bitStuffing(input, stuffed);
printf("After Bit Stuffing : %s\n", stuffed);

bitDeStuffing(stuffed, destuffed);
printf("After Bit De-Stuffing : %s\n", destuffed);

return 0;
}
