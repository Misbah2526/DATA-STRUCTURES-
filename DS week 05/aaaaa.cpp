// Circular_TaskScheduler.cpp
#include <iostream> 
#include <string>
using namespace std;

struct Task {
    int id;
    string status;
    Task* next;
    Task(int i, string s) : id(i), status(s), next(NULL) {}
};

Task* head = NULL;
Task* tail = NULL;
int Count = 0;

// Move status one step forward
string nextStatus(string current) {
    if (current == "pending")     return "waiting";
    if (current == "waiting")     return "ready";
    if (current == "ready")       return "in-progress";
    if (current == "in-progress") return "completed";
    return "completed";
}

// Age all existing tasks by one step
void ageAllTasks() {
    if (head == NULL) return;
    Task* curr = head;
    do {
        curr->status = nextStatus(curr->status);
        curr = curr->next;
    } while (curr != head);
}

void addTask(int id) {
    // STEP 1: Age all existing tasks
    ageAllTasks();

    // STEP 2: If already 4 tasks, remove oldest (head)
    if (Count >= 4) {
        Task* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        cout << "  [Task " << temp->id << " removed to make space]\n";
        delete temp;
        Count--;
    }

    // STEP 3: Insert new task as "pending"
    Task* newNode = new Task(id, "pending");
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    Count++;
    cout << "  [Task " << id << " inserted with status: pending]\n";
}

void removeTask(string name) {
    // Not used here, but kept for completeness
}

void tick(Task*& current) {
    if (current == NULL) return;

    cout << "Task " << current->id << " : " << current->status;

    if (current->status == "completed") {
        cout << "  -> removing (completed)\n";
        Task* toDelete = current;

        if (head == tail) {
            head = tail = NULL;
            current = NULL;
            delete toDelete;
            Count--;
            return;
        }

        Task* prev = head;
        while (prev->next != current) prev = prev->next;

        prev->next = current->next;
        if (current == head) head = current->next;
        if (current == tail) tail = prev;

        current = current->next;
        delete toDelete;
        Count--;
        return;
    }

    current->status = nextStatus(current->status);
    cout << "  -> " << current->status << endl;
    current = current->next;
}

void displayAll() {
    if (head == NULL) { cout << "  (no tasks)\n"; return; }
    Task* curr = head;
    do {
        cout << "  Task " << curr->id << " : " << curr->status << endl;
        curr = curr->next;
    } while (curr != head);
}

int main() {
    cout << "=== TICK 1: Insert Task 1 ===\n";
    addTask(1);
    displayAll();

    cout << "\n=== TICK 2: Insert Task 2 ===\n";
    addTask(2);
    displayAll();

    cout << "\n=== TICK 3: Insert Task 3 ===\n";
    addTask(3);
    displayAll();

    cout << "\n=== TICK 4: Insert Task 4 ===\n";
    addTask(4);
    displayAll();

    cout << "\n=== TICK 5: Insert Task 5 (oldest removed) ===\n";
    addTask(5);
    displayAll();

    cout << "\n=== TICK 6: Round Robin ===\n";
    Task* current = head;
    tick(current);
    displayAll();

    cout << "\n=== TICK 7 ===\n";
    tick(current);
    displayAll();

    cout << "\n=== TICK 8 ===\n";
    tick(current);
    displayAll();

    cout << "\n=== TICK 9 ===\n";
    tick(current);
    displayAll();

    cout << "\n=== TICK 10 ===\n";
    tick(current);
    displayAll();

    cout << "\n=== FINAL STATE ===\n";
    displayAll();

    return 0;
}