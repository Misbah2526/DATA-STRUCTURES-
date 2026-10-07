// Circular_TaskScheduler.cpp
#include <iostream>   // Include iostream for input/output operations
#include <string>     // Include string for using std::string
using namespace std;  // Use the standard namespace

// Structure representing a task node in the circular linked list
struct Task {
    int taskId;           // Unique identifier for the task
    string taskState;     // Current status/state of the task
    Task* link;           // Pointer to the next task in the circular list
    // Constructor to initialize a task with id and status
    Task(int i, string s) : taskId(i), taskState(s), link(NULL) {}
};

Task* startNode = NULL;   // Pointer to the first node (head) of the circular list
Task* endNode = NULL;     // Pointer to the last node (tail) of the circular list
int activeCount = 0;      // Counter to track the number of tasks currently in the list

// Function to advance a task's status to the next stage in the workflow
string advanceState(string currentState) {
    if (currentState == "pending")     return "waiting";       // pending -> waiting
    if (currentState == "waiting")     return "ready";         // waiting -> ready
    if (currentState == "ready")       return "in-progress";   // ready -> in-progress
    if (currentState == "in-progress") return "completed";     // in-progress -> completed
    return "completed";                                        // default fallback
}

// Function to age (advance status of) all existing tasks by one step
void ageAllTasks() {
    if (startNode == NULL) return;        // If list is empty, do nothing
    Task* iterator = startNode;           // Start from the head node
    do {
        iterator->taskState = advanceState(iterator->taskState); // Advance this task's state
        iterator = iterator->link;        // Move to next task
    } while (iterator != startNode);      // Stop when we loop back to head
}

// Function to add a new task to the circular list
void addTask(int newId) {
    // STEP 1: Age all existing tasks before adding a new one
    ageAllTasks();

    // STEP 2: If list already has 4 tasks, remove the oldest (head) task
    if (activeCount >= 4) {
        Task* oldest = startNode;         // Save reference to oldest task
        if (startNode == endNode) {       // Case: only one task in list
            startNode = endNode = NULL;   // Reset both pointers to NULL
        } else {                          // Case: multiple tasks
            startNode = startNode->link;  // Move head forward
            endNode->link = startNode;    // Update tail's link to new head
        }
        cout << "  [Task " << oldest->taskId << " removed to make space]\n"; // Notify removal
        delete oldest;                    // Free memory of removed task
        activeCount--;                    // Decrement active task count
    }

    // STEP 3: Insert the new task with initial status "pending"
    Task* freshTask = new Task(newId, "pending");  // Allocate new task node
    if (startNode == NULL) {              // Case: list was empty
        startNode = endNode = freshTask;  // Both head and tail point to new node
        freshTask->link = startNode;      // Point to itself (circular)
    } else {                              // Case: list has existing nodes
        endNode->link = freshTask;        // Old tail links to new node
        freshTask->link = startNode;      // New node links back to head
        endNode = freshTask;              // Update tail to new node
    }
    activeCount++;                        // Increment active task count
    cout << "  [Task " << newId << " inserted with status: pending]\n"; // Notify insertion
}

// Function to remove a task by name (placeholder - not used in this program)
void removeTask(string name) {
    // Not used here, but kept for completeness
}

// Function to process one task in round-robin fashion
void tick(Task*& currentPtr) {
    if (currentPtr == NULL) return;       // If no current task, return

    cout << "Task " << currentPtr->taskId << " : " << currentPtr->taskState; // Print current task info

    // If task is already completed, remove it from the list
    if (currentPtr->taskState == "completed") {
        cout << "  -> removing (completed)\n"; // Notify removal
        Task* toDelete = currentPtr;      // Save node to delete

        if (startNode == endNode) {       // Case: only one task remains
            startNode = endNode = NULL;   // Reset list to empty
            currentPtr = NULL;            // Reset current pointer
            delete toDelete;              // Free memory
            activeCount--;                // Decrement count
            return;                       // Exit function
        }

        Task* prevNode = startNode;       // Start from head
        while (prevNode->link != currentPtr) prevNode = prevNode->link; // Find previous node

        prevNode->link = currentPtr->link; // Bypass current node
        if (currentPtr == startNode) startNode = currentPtr->link; // Update head if needed
        if (currentPtr == endNode) endNode = prevNode;             // Update tail if needed

        currentPtr = currentPtr->link;    // Move current pointer to next task
        delete toDelete;                  // Free memory of removed task
        activeCount--;                    // Decrement count
        return;                           // Exit function
    }

    // If task not completed, advance its state and move to next task
    currentPtr->taskState = advanceState(currentPtr->taskState); // Advance state
    cout << "  -> " << currentPtr->taskState << endl;            // Print new state
    currentPtr = currentPtr->link;       // Move current pointer to next task
}

// Function to display all tasks in the circular list
void displayAll() {
    if (startNode == NULL) { cout << "  (no tasks)\n"; return; } // Handle empty list
    Task* iterator = startNode;           // Start from head
    do {
        cout << "  Task " << iterator->taskId << " : " << iterator->taskState << endl; // Print task info
        iterator = iterator->link;        // Move to next task
    } while (iterator != startNode);      // Stop when loop completes
}

// Main function - entry point of the program
int main() {
    cout << "=== TICK 1: Insert Task 1 ===\n"; // Print tick header
    addTask(1);                                // Add task with id 1
    displayAll();                              // Show all tasks

    cout << "\n=== TICK 2: Insert Task 2 ===\n"; // Print tick header
    addTask(2);                                  // Add task with id 2
    displayAll();                                // Show all tasks

    cout << "\n=== TICK 3: Insert Task 3 ===\n"; // Print tick header
    addTask(3);                                  // Add task with id 3
    displayAll();                                // Show all tasks

    cout << "\n=== TICK 4: Insert Task 4 ===\n"; // Print tick header
    addTask(4);                                  // Add task with id 4
    displayAll();                                // Show all tasks

    cout << "\n=== TICK 5: Insert Task 5 (oldest removed) ===\n"; // Print tick header
    addTask(5);                                                  // Add task 5, oldest removed
    displayAll();                                                // Show all tasks

    cout << "\n=== TICK 6: Round Robin ===\n"; // Print tick header
    Task* currentTask = startNode;             // Initialize current pointer to head
    tick(currentTask);                         // Process one task
    displayAll();                              // Show all tasks

    cout << "\n=== TICK 7 ===\n";              // Print tick header
    tick(currentTask);                         // Process next task
    displayAll();                              // Show all tasks

    cout << "\n=== TICK 8 ===\n";              // Print tick header
    tick(currentTask);                         // Process next task
    displayAll();                              // Show all tasks

    cout << "\n=== TICK 9 ===\n";              // Print tick header
    tick(currentTask);                         // Process next task
    displayAll();                              // Show all tasks

    cout << "\n=== TICK 10 ===\n";             // Print tick header
    tick(currentTask);                         // Process next task
    displayAll();                              // Show all tasks

    cout << "\n=== FINAL STATE ===\n";         // Print final header
    displayAll();                              // Show final state of all tasks

    return 0;                                  // Return success
}