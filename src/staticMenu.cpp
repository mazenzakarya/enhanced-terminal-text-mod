#include <iostream>

#include "staticMenue.h"

using namespace std;

// class staticEmpMenu {
//  public:
//   int numberOfEmployee;
//   char** nameOfEmployee;
//    staticEmpMenu(){
//
//    }
void staticEmpMenu::staticMenu() {
  cout << "Welcome to static Add New Employee Page\n";
  cout << "================================\n";
  cout << "Please enter number of employee you want to insert:\n";
  int empNumber;
  cin >> empNumber;
  cin.ignore();  // Ignore the newline character left in the buffer

  numberOfEmployee = empNumber;

  nameOfEmployee = new char*[numberOfEmployee];

  for (int i = 0; i < numberOfEmployee; i++) {
    nameOfEmployee[i] = new char[50];
  }

  cout << "================================\n";
  cout << "Please enter names of employees then press enter for save each "
          "name:\n";
  for (int i = 0; i < numberOfEmployee; i++) {
    cout << "Enter employee " << i + 1 << " name: ";
    cin.getline(nameOfEmployee[i], 50);
  }
  // why [0] not i??
  //  cout << nameOfEmployee[0] << " added successfully!\n";

  for (int i = 0; i < numberOfEmployee; i++) {
    cout << nameOfEmployee[i] << endl;
  }
}
