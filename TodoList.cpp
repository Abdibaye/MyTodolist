#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TodoList
{
    string data;
    string description;
    string due_to;
    struct TodoList *next;
};
struct TodoList *head = NULL;
queue<TodoList*> Todo_queue;

void Create_Todo()
{
    string name;
    cin.ignore();

    cout << "Add todo: ";
    getline(cin, name);

    string dis;
    cout << "Write description: " << endl;
    getline(cin, dis);

    string due;
    cout << "Enter time: ";
    getline(cin, due);

    TodoList *first_Todo = new TodoList;
    first_Todo->data = name;
    first_Todo->description = dis;
    first_Todo->due_to = due;
    first_Todo->next = NULL;

    head = first_Todo;
    Todo_queue.push(first_Todo);

    bool permission = false;
    cout << "Do you want to add another node (yes/no): ";
    string permissionInput;
    getline(cin, permissionInput);

    if (permissionInput == "yes") {
        permission = true;
    } else if (permissionInput == "no") {
        permission = false;
    } else {
        cout << "Invalid input. Assuming 'no'." << endl;
        permission = false;
    }

    while (permission)
    {
        TodoList *temp = new TodoList;

        cout << "Add Todo: ";
        getline(cin, name);

        cout << "Write description: " << endl;
        getline(cin, dis);

        cout << "Enter time: ";
        getline(cin, due);

        temp->data = name;
        temp->description = dis;
        temp->due_to = due;
        temp->next = NULL;

        first_Todo->next = temp;
        first_Todo = temp;
        Todo_queue.push(first_Todo);

        cout << "Do you want to add another node (1/0): ";
        cin >> permission;
        cin.ignore();
    }
}

void Display_todo_queue()
{
    cout << "Your today's todolist: " << endl;
    queue<TodoList*> temp_queue = Todo_queue; 
    while (!temp_queue.empty())
    {
        TodoList *todo = temp_queue.front();
        cout << todo->data << endl;
        temp_queue.pop();
    }
}

void progress()
{
    if (Todo_queue.empty())
    {
        cout << "No tasks in the todolist." << endl;
        return;
    }

    TodoList *tode = Todo_queue.front();
    string choice;

    cout << "Did you finish the first task? (yes/no): ";
    cin >> choice;
    cin.ignore();

    if (choice == "yes")
    {
        cout << "Congratulations! You have finished the task: " << tode->data << endl;
        Todo_queue.pop();
    }
    else
    {
        cout << "Well!" << endl;
        cout << "You have to finish it by: " << tode->due_to << endl;
    }
}


int main()
{
    cout << "Welcome to MyTodolist!" << endl;

    int choice = 0;
    while (choice != 4)
    {
        cout << "Please select a menu option:" << endl;
        cout << "1. Create Todolist for your day" << endl;
        cout << "2. See your todolist" << endl;
        cout << "3. Edit your progress" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice)
        {
            case 1:
                Create_Todo();
                break;
            case 2:
                Display_todo_queue();
                break;
            case 3:
                progress();
                break;
            case 4:
                cout << "Thank you for using MyTodolist. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}