#include <iostream>
#include "todo.h"

using namespace std;





int main() {
    Task* head = nullptr;
    Task* new_task = nullptr;

    while (true) {
        showMenu();
        int choice = 0;
        int add = 0;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Goodbye" << endl;
                exit(1);
                break;
            case 1:
                //showTasks(head);
                break;
            case 2:
                new_task = createTask();
                cout << "Add to the beginning (0) or the end (1)? ";
                cin >> add;
                break;

            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }

}

/*
 * int steviloOpravljenih(Opravilo* head);
 * int steviloNeopravljenih(Opravilo* head);
 * bool shraniVDatoteko(Opravilo* head, const string& imeDatoteke);
 * id|naslov|opis|prioriteta|opravljeno
 * bool naloziIzDatoteke(Opravilo*& head, const string& imeDatoteke);
 * void pocistiSeznam(Opravilo*& head);
 * void izpisiMeni();
 */