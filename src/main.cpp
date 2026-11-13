#include <iostream>

#include "ArrowInput.h"
#include "TerminalTextLocationLib.h"
#include "TextColorTerminalLib.h"
#include "menuCreation.h"
#include "staticMenue.h"

// void defaultMenu (){
// char menu[3][3]={"new","get employee","Exit"};
//
// for(int i = 0; i > 3; i++){
//
//     moveTo(6+i,20);
//     std::cout << menu[i] << std::endl;
//
//     }
//
// }

int main() {
  initialize();
  staticEmpMenu staticMenu;

  // defaultMenu();
  cursurMovementAndColor(&staticMenu);
  return 0;
}
