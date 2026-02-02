#include <iostream>
#include "todo.h"

using namespace std;

int main() {
    Task* head = nullptr;
    Task* new_task = new Task;

    new_task->id = 1;
    new_task->name = "Cleaning";
    new_task->description = "Whatever";
    new_task->done = false;
    new_task->priority = 5;
    new_task->next = nullptr;

    head = new_task;

    while (true) {
        showMenu();
        int choice = 0;
        int add = -1;
        int id = 0;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Goodbye" << endl;
                exit(1);
                break;
            case 1:
                showTasks(head);
                break;
            case 2:
                new_task = createTask();
                while (add < 0 || add > 1) {
                    cout << "Add to the beginning (0) or the end (1)? ";
                    cin >> add;
                }
                if (add == 0) {
                    addToBeginning(head, new_task);
                    cout << "Added a new task to the beginning." << endl;
                } else {
                    addToEnd(head, new_task);
                    cout << "Added a new task to the end." << endl;
                }
                break;
            case 3:
                cout << "Insert the ID of the task you want to remove: ";
                cin >> id;
                if (removeTask(head, id)) {
                    cout << "The task was successfully removed!" << endl;
                } else {
                    cout << "No task with such ID." << endl;
                }
                break;
            case 4:
                cout << "Insert the ID of a task you want to mark done: ";
                cin >> id;
                if (markDone(head, id)) {
                    cout << "Successfully marked done!" << endl;
                } else {
                    cout << "No task with such ID." << endl;
                }
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