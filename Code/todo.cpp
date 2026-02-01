/*
*  Author: Filip Gračner
 * Project: TODO list application in C++
 * Date: 2026-01-31
 * Description: Function implementations for TODO list
 */

#include "todo.h"
#include <iostream>

using namespace std;

Task* createTask() {
    Task* task = new Task;
    cout << "Insert an ID: ";
    cin >> task->id;
    cin.ignore();
    cout << "Insert a name of the task: ";
    getline(cin, task->name);
    cout << "Insert task description: ";
    getline(cin, task->description);
    cout << "Insert task priority: ";
    cin >> task->priority;
    task->done = false;
    task->next = nullptr;
    return task;
}

void showMenu() {
    cout << "---------------TO DO LIST---------------" << endl;
    cout << "1 - Show tasks" << endl;
    cout << "2 - Add task" << endl;
    cout << "3 - Remove task" << endl;
    cout << "4 - Mark task done" << endl;
    cout << "5 - Sort ..." << endl;
    cout << "6 - Sort ..." << endl;
    cout << "7 - Statistics" << endl;
    cout << "8 - Save to file" << endl;
    cout << "9 - Load from file" << endl;
    cout << "10 - Clear the list of tasks" << endl;
    cout << "0 - Quit" << endl << endl;
}