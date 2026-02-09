#include <iostream>
#include "todo.h"

using namespace std;

int main(int argc, char* argv[]) {
    Task* head = nullptr;

    if (argc > 1) {
        cout << "Loading TODO list from file ..." << endl;
        string path = argv[1];
        loadFromFile(head, path);
    }

    while (true) {
        showMenu();
        int choice = 0;
        int add = -1;
        int id = 0;
        Task* new_task = nullptr;
        string file_name = "";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Goodbye" << endl;
                return 0;
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
            case 5:
                cout << "Sort by ID (0) / name (1) / description (2) / priority (3): ";
                cin >> id;
                bubbleSort(head, id);
                break;
            case 6:
                cout << "Number of all tasks: " << numberOfAll(head) << endl;
                cout << "Number of completed tasks: " << numberOfDone(head) << endl;
                cout << "Percentage of done: " << 100*(static_cast<float>(numberOfDone(head))/static_cast<float>(numberOfAll(head))) << endl;
                break;
            case 7:
                cout << "Saving to file: " << endl;
                cin >> file_name;
                saveToFile(head, file_name);
                break;
            case 8:
                cout << "Clearing the list of tasks ..." << endl;
                clearList(head);
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
}