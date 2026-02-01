/*
*  Author: Filip Gračner
 * Project: TODO list application in C++
 * Date: 2026-01-31
 * Description: Function implementations for TODO list
 */

#include "todo.h"
#include <iostream>

using namespace std;

void showTasks(Task* head) {
    Task* p = head;
    cout << "---------------TASKS---------------" << endl;
    while (p != nullptr) {
        cout << p->id << " | " << p->name << " | " << p->description << " | " << p->priority << " | " << p->done <<
                endl;
        p = p->next;
    }
}

Task* findId(Task* head, int id) {
    if (head == nullptr) {
        return nullptr;
    }

    Task* p = head;
    while (p != nullptr) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

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

void addToBeginning(Task*& head, Task* new_task) {
    if (head == nullptr) {
        head = new_task;
        head->next = nullptr;
        return;
    }

    new_task->next = head;
}

void addToEnd(Task*& head, Task* new_task) {
    if (head == nullptr) {
        head = new_task;
        head->next = nullptr;
        return;
    }

    if (head->next == nullptr) {
        head->next = new_task;
        new_task->next = nullptr;
        return;
    }

    Task* p = head;

    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new_task;
    new_task->next = nullptr;
}

bool markDone(Task*& head, int id) {
    Task* p = findId(head, id);
    if (p == nullptr) {
        cout << "No task with such ID." << endl;
        return false;
    }
    if (p->done == true) {
        cout << "The task has already been completed" << endl;
        return true;
    }

    p->done = true;
    return true;
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