#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
    string status;  // "pending", "in-progress", "completed"
    Task *next;
};

Task *head = NULL;
Task *currentTask = NULL;  // for round-robin

// Add a task at end (circular)
void addTask(string name, int priority) {
    Task *p = new Task;
    p->name = name;
    p->priority = priority;
    p->status = "pending";
    
    if (head == NULL) {
        p->next = p;
        head = p;
    } else {
        Task *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }
    cout << "Task added: " << name << endl;
}

// Remove a task by name
void removeTask(string name) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Task *current = head;
    Task *prev = NULL;
    
    // Find last node (for head deletion handling)
    Task *last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    do {
        if (current->name == name) {
            if (current == head) {
                if (head->next == head) {
                    // Only one node
                    delete head;
                    head = NULL;
                    currentTask = NULL;
                    cout << "Task removed: " << name << endl;
                    return;
                } else {
                    // Head deletion with multiple nodes
                    head = head->next;
                    last->next = head;
                    if (currentTask == current) {
                        currentTask = head;
                    }
                    delete current;
                    cout << "Task removed: " << name << endl;
                    return;
                }
            } else {
                // Middle or last node deletion
                prev->next = current->next;
                if (currentTask == current) {
                    currentTask = current->next;
                }
                delete current;
                cout << "Task removed: " << name << endl;
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);
    
    cout << "Task not found: " << name << endl;
}

// Get next pending task (round-robin)
void getNextTask() {
    if (head == NULL) {
        cout << "No tasks available." << endl;
        return;
    }
    
    if (currentTask == NULL) {
        currentTask = head;
    } else {
        currentTask = currentTask->next;
    }
    
    // Skip completed tasks
    Task *start = currentTask;
    while (currentTask->status == "completed") {
        currentTask = currentTask->next;
        if (currentTask == start) {
            cout << "All tasks are completed!" << endl;
            return;
        }
    }
    
    cout << "Next task: " << currentTask->name 
         << " (Priority: " << currentTask->priority 
         << ", Status: " << currentTask->status << ")" << endl;
}

// Display all tasks
void displayAllTasks() {
    if (head == NULL) {
        cout << "No tasks in the list." << endl;
        return;
    }
    
    cout << "\n--- All Tasks ---" << endl;
    Task *temp = head;
    do {
        cout << "Name: " << temp->name 
             << " | Priority: " << temp->priority 
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    } while (temp != head);
    cout << "-----------------" << endl;
}

// Update task status by name
void updateTaskStatus(string name, string newStatus) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Task *temp = head;
    do {
        if (temp->name == name) {
            temp->status = newStatus;
            cout << "Task '" << name << "' status updated to: " << newStatus << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    cout << "Task not found: " << name << endl;
}

int main() {
    addTask("Design", 1);
    addTask("Coding", 2);
    addTask("Testing", 3);
    addTask("Deployment", 4);
    
    displayAllTasks();
    
    cout << "\n--- Round Robin ---" << endl;
    getNextTask();  // Design
    getNextTask();  // Coding
    
    updateTaskStatus("Coding", "completed");
    
    getNextTask();  // Testing (skips nothing yet)
    getNextTask();  // Deployment
    getNextTask();  // Design (wraps around)
    
    cout << "\n--- Remove Testing ---" << endl;
    removeTask("Testing");
    displayAllTasks();
    
    return 0;
}