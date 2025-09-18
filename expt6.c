#include <stdio.h>

int main() {
    int windowSize, totalFrames, i;
    int frames[50];

    // Prompt the user for the sliding window size
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    // Prompt the user for the number of frames to transmit
    printf("Enter number of frames to transmit: ");
    scanf("%d", &totalFrames);

    if(windowSize <= 0 || totalFrames <= 0) {
        printf("Window size and number of frames must be positive.\n");
        return 1;
    }

    // Prompt the user to enter all the frames
    printf("Enter %d frames: ", totalFrames);
    for(i = 0; i < totalFrames; i++) {
        scanf("%d", &frames[i]);
    }

    // Display the transmission process
    printf("\nSliding Window Protocol Simulation (No Frame Loss/Corruption)\n");
    printf("Sender sends %d frames at a time and waits for acknowledgement.\n\n", windowSize);

    for(i = 0; i < totalFrames; i++) {
        printf("%d ", frames[i]);

        // If a full window has been sent, simulate acknowledgment
        if((i + 1) % windowSize == 0) {
            printf("\nAcknowledgement received for above frames\n\n");
        }
    }

    // If remaining frames are less than window size
    if(totalFrames % windowSize != 0) {
        printf("\nAcknowledgement received for above frames\n");
    }

    return 0;
}
