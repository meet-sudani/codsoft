#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;

    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task Added Successfully!\n";
                break;

            case 2:
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    cout << "\n----- Your Tasks -----\n";
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
                break;

            case 3:
                if (tasks.empty()) {
                    cout << "No tasks to delete.\n";
                } else {
                    int num;
                    cout << "Enter task number to delete: ";
                    cin >> num;

                    if (num >= 1 && num <= tasks.size()) {
                        tasks.erase(tasks.begin() + num - 1);
                        cout << "Task Deleted Successfully!\n";
                    } else {
                        cout << "Invalid task number.\n";
                    }
                }
                break;

            case 4:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}