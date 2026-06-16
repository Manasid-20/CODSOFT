#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

// Add Task
void addTask() {
    Task newTask;

    cin.ignore();

    cout << "\nEnter task name: ";
    getline(cin, newTask.name);

    newTask.completed = false;

    tasks.push_back(newTask);

    cout << "Task added successfully!\n";
}

// View Tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n===== TO-DO LIST =====\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].name
             << " ["
             << (tasks[i].completed ? "Completed" : "Pending")
             << "]\n";
    }
}

// Mark Task as Completed
void markCompleted() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[taskNumber - 1].completed = true;

    cout << "Task marked as completed!\n";
}

// Remove Task
void removeTask() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);

    cout << "Task deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n==========================";
        cout << "\n   TO-DO LIST MANAGER";
        cout << "\n==========================";
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Task as Completed";
        cout << "\n4. Delete Task";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                markCompleted();
                break;

            case 4:
                removeTask();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
