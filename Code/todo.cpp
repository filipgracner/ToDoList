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
    head = new_task;
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
        return false;
    }
    if (p->done == true) {
        cout << "The task has already been completed" << endl;
        return true;
    }

    p->done = true;
    return true;
}

bool removeTask(Task*& head, int id) {
    if (findId(head, id) == nullptr) {
        return false;
    }

    if (head->next == nullptr) {
        if (head->id == id) {
            delete head;
            head = nullptr;
            return true;
        }
    }

    Task* p = head;
    p = p->next;
    Task* q = head;

    if (q->id == id) {
        delete q;
        q = nullptr;
        head = p;
        return true;
    }

    while (p != nullptr) {
        if (p->id == id) {
            if (p->next == nullptr) {
                q->next = nullptr;
            } else {
                q->next = p->next;
            }
            delete p;
            p = nullptr;
            return true;
        }
        p = p->next;
        q = q->next;
    }
}

/*void bubbleSort(Task*& head) {
    Task* p = head;
    Task* q = head;
    Task* temp = head;

    while (p->next != nullptr) {
        while (q->next->next != nullptr) {
            if (p->priority > q->priority) {
                temp = p;
            }
        }
    }
}*/

void showMenu() {
    cout << "---------------TO DO LIST---------------" << endl;
    cout << "1 - Show tasks" << endl;
    cout << "2 - Add task" << endl;
    cout << "3 - Remove task" << endl;
    cout << "4 - Mark task done" << endl;
    cout << "5 - Sort ..." << endl;
    cout << "6 - Statistics" << endl;
    cout << "7 - Save to file" << endl;
    cout << "8 - Load from file" << endl;
    cout << "9 - Clear the list of tasks" << endl;
    cout << "0 - Quit" << endl << endl;
}