/*
*  Author: Filip Gračner
 * Project: TODO list application in C++
 * Date: 2026-01-31
 * Description: Function declarations for TODO list
 */

#ifndef TODO_H
#define TODO_H

#include <string>

struct Task {
    int id;
    std::string name;
    std::string description;
    int priority;
    bool done;
    Task* next;
};

Task* createTask();
void addToBeginning(Task*& head, Task* new_task);
void addToEnd(Task*& head, Task* new_task);
void showTasks(Task* head);
Task* findId(Task* head, int id);
bool markDone(Task*& head, int id);
bool removeTask(Task*& head, int id);
void bubbleSort(Task*& head);
void sortByPriority(Task*& head);
void sortById(Task*& head);
void sortByName(Task*& head);
void sortByDescription(Task*& head);
int numberOfDone(Task* head);
int numberOfNotDone(Task* head);
void saveToFile(Task* head, std::string file_name);
void loadFromFile(Task*& head, std::string file_name);
void clearList(Task*& head);
void showMenu();

#endif //TODO_H