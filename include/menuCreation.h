#ifndef MENUCREATION_H_INCLUDED
#define MENUCREATION_H_INCLUDED
#include "staticMenue.h"
void defaultMenu();
void cursurMovementAndColor(staticEmpMenu* staticMenu);
void openPage(int selectedIndex, char**& employeeNames, int& employeeSize,
              int& employeeCapacity, staticEmpMenu* staticMenu);
#endif  // MENUCREATION_H_INCLUDED
