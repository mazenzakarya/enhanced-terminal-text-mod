#include <iostream>   // Standard input/output library
#include <cstdio>     // C standard I/O functions such as printf
#include <unistd.h>   // Provides Unix functions such as read
#include <termios.h>  // Used to control terminal settings
#include "ArrowInput.h"

// Alternative implementation of getch() for Linux systems
char getch_linux() {
    char buf = 0; // Variable to store the input character

    struct termios old = {0}; // Structure to save current terminal settings

    // Save the current terminal settings
    tcgetattr(0, &old);

    // Disable Canonical Moِde (do not wait for Enter key)
    old.c_lflag &= ~ICANON;

    // Disable Echo so typed characters are not displayed
    old.c_lflag &= ~ECHO;

    // Require at least one character to be read
    old.c_cc[VMIN] = 1;

    // No timeout while waiting for input
    old.c_cc[VTIME] = 0;

    // Apply the modified settings immediately
    tcsetattr(0, TCSANOW, &old);

    // Read a single character immediately from the keyboard
    read(0, &buf, 1);

    // Re-enable Canonical Mode
    old.c_lflag |= ICANON;

    // Re-enable Echo
    old.c_lflag |= ECHO;

    // Restore the terminal to its original settings
    tcsetattr(0, TCSADRAIN, &old);

    // Return the character that was read
    return buf;
}

//    char buf = 0;
//
//    struct termios oldSettings = {0};
//    struct termios newSettings = {0};
//
//    // Save original terminal settings
//    tcgetattr(STDIN_FILENO, &oldSettings);
//
//    // Copy original settings
//    newSettings = oldSettings;
//
//    // Disable Canonical Mode and Echo
//    newSettings.c_lflag &= ~(ICANON | ECHO);
//
//    newSettings.c_cc[VMIN] = 1;
//    newSettings.c_cc[VTIME] = 0;
//
//    // Apply new settings
//    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
//
//    // Read one character
//    read(STDIN_FILENO, &buf, 1);
//
//    // Restore EXACT original settings
//    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
//
//    return buf;
//}

