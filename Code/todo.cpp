/*
*  Author: Filip Gračner
 * Project: TODO list application in C++
 * Date: 2026-01-31
 * Description: Function implementations for TODO list
 */

#include "todo.h"
#include <iostream>
#include <vector>

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
    return false;
}

void clearList(Task*& head) {
    Task* p = head;
    while (p != nullptr) {
        Task* q = p;
        delete q;
        q = nullptr;
        p = p->next;
    }
    head = nullptr;
}

void swapData(Task *&p, Task *&q) {
    Task* temp = new Task;
    temp->id = q->id;
    temp->name = q->name;
    temp->description = q->description;
    temp->priority = q->priority;
    temp->done = q->done;

    q->id = p->id;
    q->name = p->name;
    q->description = p->description;
    q->priority = p->priority;
    q->done = p->done;

    p->id = temp->id;
    p->name = temp->name;
    p->description = temp->description;
    p->priority = temp->priority;
    p->done = temp->done;
    delete temp;
    temp = nullptr;
}

void bubbleSort(Task*& head, const int key) {
    Task* p = head;
    Task* q = head;

    if (key < 0 || key > 3) {
        return;
    }

    while (p->next != nullptr) {
        while (q->next != nullptr) {
            if (key == 0 && q->id > q->next->id) {
                swapData(q, q->next);
            } else if (key == 1 && (q->name) > q->next->name) {
                swapData(q, q->next);
            } else if (key == 2 && q->description > q->next->description) {
                swapData(q, q->next);
            } else if (key == 3 && q->priority < q->next->priority) {
                swapData(q, q->next);
            }

            q = q->next;
        }
        q = head;
        p = p->next;
    }
}

int numberOfDone(Task *head) {
    int num = 0;
    Task* p = head;
    while (p != nullptr) {
        if (p->done == true) {
            num++;
        }
        p = p->next;
    }
    return num;
}

int numberOfAll(Task *head) {
    int num = 0;
    Task* p = head;
    while (p != nullptr) {
        num++;
        p = p->next;
    }
    return num;
}

void saveToFile(Task *head, std::string file_name) {
    ofstream output (file_name, ios::out);

    if (!output.good()) {
        cout << "Writing in file " << file_name << " failed!" << endl;
        return;
    }

    Task* p = head;
    while (p != nullptr) {
        output << to_string(p->id) << "|"
        << p->name << "|"
        << p->description << "|"
        << to_string(p->priority) << "|"
        << to_string(p->done) << "|"
        << "\n";
        p = p->next;
    }
    output.close();
}

void loadFromFile(Task *&head, std::string file_name) {
    ifstream input(file_name, ios::in);
    if (!input.good()) {
        cout << "Reading from file " << file_name << " failed!" << endl;
        return;
    }

    clearList(head);
    vector<string> data = {};
    string line;
    int num_el = 0;
    string word;

    while (getline(input, line)) {
        word = "";
        num_el = 0;
        data.clear();

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '|') {
                data.push_back(word);
                word = "";
                num_el++;
                continue;
            }
            word += line[i];
        }

        if (!word.empty()) {
            data.push_back(word);
        }

        if (data.size() < 5) {
            cout << "Invalid line format (expected 5 fields, got " << data.size() << "), skipping..." << endl;
            continue;
        }

        Task* p = new Task;
        p->id = stoi(data[0]);
        p->name = data[1];
        p->description = data[2];
        p->priority = stoi(data[3]);
        if (data[4] == "1") {
            p->done = true;
        } else {
            p->done = false;
        }
        p->next = nullptr;
        addToEnd(head, p);
    }

    input.close();
}

void showMenu() {
    cout << "---------------TO DO LIST---------------" << endl;
    cout << "1 - Show tasks" << endl;
    cout << "2 - Add task" << endl;
    cout << "3 - Remove task" << endl;
    cout << "4 - Mark task done" << endl;
    cout << "5 - Sort ..." << endl;
    cout << "6 - Statistics" << endl;
    cout << "7 - Save to file" << endl;
    cout << "8 - Clear the list of tasks" << endl;
    cout << "0 - Quit" << endl << endl;
}