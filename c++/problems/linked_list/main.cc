#include <stdlib.h>

#include <iostream>

#include "linkedlist.h"

using namespace std;

int main(int argc, char *argv[]) {
  LinkedList<int> list;
  int option;
  int item;
  int index;
  bool quit = false;
  do {
    cout << "====================================" << endl;
    cout << "Select option :" << endl;
    cout << "1: Insert back" << endl;
    cout << "2: Insert front" << endl;
    cout << "3: Insert at index" << endl;
    cout << "4: Display items" << endl;
    cout << "5: Get item at index" << endl;
    cout << "6: Delete back" << endl;
    cout << "7: Delete front" << endl;
    cout << "8: Delete at index" << endl;
    cout << "9: Exit" << endl;
    cout << "Option: ";
    cin >> option;
    cout << "====================================" << endl;
    switch (option) {
      case 1:
        cout << "Enter item to insert: ";
        cin >> item;
        list.add(item);
        break;
      case 2:
        cout << "Enter item to insert: ";
        cin >> item;
        list.addFront(item);
        break;
      case 3:
        cout << "Enter item to insert: ";
        cin >> item;
        cout << "Enter index: ";
        cin >> index;
        list.add(index, item);
        break;
      case 4:
        list.displayAll();
        break;
      case 5:
        cout << "Enter index: ";
        cin >> index;
        cout << "Item at index " << index << ": " << list.get(index) << endl;
        break;
      case 6:
        list.remove();
        break;
      case 7:
        list.removeFront();
        break;
      case 8:
        cout << "Enter index: ";
        cin >> index;
        list.remove(index);
        break;
      case 9:
        quit = true;
        break;
      default:
        cout << "Invalid selection" << endl;
        break;
    }
  } while (!quit);
  return 0;
}
