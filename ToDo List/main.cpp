#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void loadTasksFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Task task;
        if (line.size() >= 3 && (line[0] == '0' || line[0] == '1') && line[1] == '|') {
            task.completed = (line[0] == '1');
            task.description = line.substr(2);
            tasks.push_back(task);
        }
    }
    file.close();
}

void saveTasksToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << (task.completed ? "1" : "0") << "|" << task.description << endl;
    }
    file.close();
}

void displayTasks() {
    cout << "\nLista zadań:\n";
    if (tasks.empty()) {
        cout << "Brak zadań.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? 'x' : ' ') << "] "
             << tasks[i].description << "\n";
    }
}

void addTask() {
    cout << "Podaj opis zadania: ";
    string desc;
    getline(cin, desc);
    tasks.push_back({desc, false});
}

void completeTask() {
    displayTasks();
    cout << "Wpisz numer zadania do oznaczenia jako ukończone: ";
    size_t index;
    cin >> index;
    cin.ignore();
    if (index == 0 || index > tasks.size()) {
        cout << "Nieprawidłowy numer.\n";
        return;
    }
    tasks[index - 1].completed = true;
}

void deleteTask() {
    displayTasks();
    cout << "Wpisz numer zadania do usunięcia: ";
    size_t index;
    cin >> index;
    cin.ignore();
    if (index == 0 || index > tasks.size()) {
        cout << "Nieprawidłowy numer.\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
}

void showMenu() {
    cout << "\n=== To-Do List CLI ===\n";
    cout << "1. Pokaż zadania\n";
    cout << "2. Dodaj zadanie\n";
    cout << "3. Oznacz jako ukończone\n";
    cout << "4. Usuń zadanie\n";
    cout << "5. Zapisz i wyjdź\n";
    cout << "Wybierz opcję: ";
}

int main() {
    const string filename = "tasks.txt";
    loadTasksFromFile(filename);

    bool running = true;
    while (running) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                saveTasksToFile(filename);
                running = false;
                break;
            default:
                cout << "Nieprawidłowa opcja.\n";
        }
    }

    cout << "Zadania zapisane. Do zobaczenia!\n";
    return 0;
}