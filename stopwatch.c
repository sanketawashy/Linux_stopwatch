#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long long getCurrentTimeMillis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000;
}

int main() {
    long long startTime, endTime;
    char userInput;

    printf("Press 's' to start the stopwatch.\n");
    scanf("%c", &userInput); // Wait for user input

    if (userInput != 's') {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    startTime = getCurrentTimeMillis();
    printf("Stopwatch started!\n");

    printf("Press 'e' to stop the stopwatch.\n");
    scanf(" %c", &userInput); // Wait for user input

    if (userInput != 'e') {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    endTime = getCurrentTimeMillis();
    printf("Stopwatch stopped!\n");

    long long elapsedTime = endTime - startTime;
    int seconds = elapsedTime / 1000;
    int milliseconds = elapsedTime % 1000;

    printf("Elapsed Time: %d seconds %d milliseconds\n", seconds, milliseconds);

    return 0;
}
