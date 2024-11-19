#include <iostream>
#include <vector>
#include <string>

class TodoList {
private:
    std::vector<std::string> tasks;  

public:
    
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

       void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "Your to-do list is empty!" << std::endl;
            return;
        }
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }

   
    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number!" << std::endl;
            return;
        }
        std::cout << "Removing task: " << tasks[index - 1] << std::endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string task;

    do {
        std::cout << "\nTo-Do List Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Display Tasks" << std::endl;
        std::cout << "3. Remove Task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
            case 1:
                std::cout << "Enter the task: ";
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.displayTasks();
                break;
            case 3:
                int taskNumber;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
