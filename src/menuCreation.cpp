#include "menuCreation.h"

#include <cstdlib>
#include <iostream>

#include "ArrowInput.h"
#include "TerminalTextLocationLib.h"
#include "TextColorTerminalLib.h"
#include "arrayDublication.h"
#include "staticMenue.h"
using namespace std;

char menu[5][21] = {"new", "get employee", "add new static emp",
                    "get static employees", "Exit"};
// void defaultMenu(int selectedIndex)
//{
//     for (int i = 0; i < 3; i++)
//     {
//         moveTo(6 + i, 20);
//
//         if (i == selectedIndex)
//             selectColor(RED);
//         else
//             selectColor(WHITE);
//
//         cout << menu[i];
//     }
// }

void defaultMenu(int selectedIndex) {
  for (int i = 0; i < 5; i++) {
    moveTo(6 + i, 20);

    // Clear current terminal line
    cout << "\033[2K";

    moveTo(6 + i, 20);

    if (i == selectedIndex)
      selectColor(RED);
    else
      selectColor(WHITE);

    cout << menu[i];
  }
  moveTo(10, 10);
  cout << selectedIndex;
  selectColor(WHITE);
  cout.flush();
}

void cursurMovementAndColor(staticEmpMenu* staticMenu) {
  int employeeSize = 0;
  int employeeCapacity = 2;

  char** employeeName = new char* [employeeCapacity] {};
  std::printf(
      "Press the arrow keys to test the program (press 'q' to quit):\n");

  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';
  //    char byte11 = getch_linux();
  // cout << "ASCII: " << (int)byte11 << endl;
  int selectedIndex = 0;
  // Infinite loop that runs until the user chooses to quit

  do {
    defaultMenu(selectedIndex);
    // Read a key from the user
    byte1 = getch_linux();
    // std::cout<<"Byte 1 :: "<<byte1<<std::endl;
    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {
      // Skip the second character '['
      byte2 = getch_linux();
      // std::cout<<"Byte 2 :: "<<byte2<<std::endl;
      byte3 = getch_linux();
      // The third character determines the arrow direction
      // std::cout<<"Byte 3 :: "<<byte3<<std::endl;
      switch (byte3) {
        case 'A':
          //                    std::printf("↑ Up Arrow\n");
          if (selectedIndex > 0) {
            selectedIndex--;
          };

          break;

        case 'B':
          //                    std::printf("↓ Down Arrow\n");

          if (selectedIndex < 4) {
            selectedIndex++;
          };
          break;

          //                case 'C':
          //                    std::printf("→ Right Arrow\n");
          //                    break;
          //
          //                case 'D':
          //                    std::printf("← Left Arrow\n");
          //                    break;
          //                case 'H':
          //                    std::printf("← Home Button \n");
          //                    break;
          //                case 'F':
          //                    std::printf("End Button\n");
          //                    break;
      }
    }

    else if (byte1 == '\n' || byte1 == '\r') {
      moveTo(15, 20);

      selectColor(GREEN);

      openPage(selectedIndex, employeeName, employeeSize, employeeCapacity,
               staticMenu);
      clearTerminal();
      //        return;
    }
  } while (byte1 != 'q' && byte1 != 'Q');
}

void openPage(int selectedIndex, char**& employeeName, int& employeeSize,
              int& employeeCapacity, staticEmpMenu* staticMenu) {
  char choice[10];
  //   staticEmpMenu staticMenuObj;

  do {
    clearTerminal();

    switch (selectedIndex) {
      case 0: {
        cout << "Welcome to Add New Employee Page\n";
        cout << "================================\n";
        cout << "Please enter new employee name:\n";

        char ch[30];
        cin.getline(ch, 30);

        addElementToDynamicArray(employeeName, employeeSize, employeeCapacity,
                                 ch);

        cout << ch << " added successfully!\n";
        break;
      }

      case 1:
        cout << "Welcome to View Employees Page\n";
        cout << "================================\n";

        for (int i = 0; i < employeeSize; i++) {
          cout << i + 1 << ". " << employeeName[i] << '\n';
        }
        break;

      case 2:
        staticMenu->staticMenu();
        break;

      case 3:
        cout << "Welcome to View Static Employees Page\n";
        cout << "================================\n";

        for (int i = 0; i < staticMenu->numberOfEmployee; i++) {
          cout << i + 1 << ". " << staticMenu->nameOfEmployee[i] << '\n';
        }
        break;

      case 4:
        cout << "Exit page\n";
        std::cout << "Exiting from foo\n";
        std::exit(0);
    }

    cout << "\n\nPress B to go back to menu: ";
    cin.getline(choice, 10);

  } while (choice[0] != 'B' && choice[0] != 'b');
}
