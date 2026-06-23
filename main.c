#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
typedef struct Task {
    char title[100];
    char category[50];
    char priority[20];
    char reminder[50];
    struct Task* next;
} Task;

// Function to create a new task
Task* createTask(char title[], char category[], char priority[], char reminder[]) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->title, title);
    strcpy(newTask->category, category);
    strcpy(newTask->priority, priority);
    strcpy(newTask->reminder, reminder);
    newTask->next = NULL;
    return newTask;
}

// Function to add a task to the list
void addTask(Task** head, char title[], char category[], char priority[], char reminder[]) {
    Task* newTask = createTask(title, category, priority, reminder);
    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
    printf("Task \"%s\" added successfully!\n", title);
}

// Function to view tasks
void viewTasks(Task* head) {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    Task* temp = head;
    while (temp != NULL) {
        printf("Task: %s | Category: %s | Priority: %s | Reminder: %s\n", temp->title, temp->category, temp->priority, temp->reminder);
        temp = temp->next;
    }
}

// Function to delete a task
void deleteTask(Task** head, char category[]) {
    if (*head == NULL) {
        printf("Task list is empty.\n");
        return;
    }
    Task* temp = *head;
    Task* prev = NULL;
    if (strcmp(temp->category, category) == 0) {
        *head = temp->next;
        free(temp);
        printf("Task \"%s\" deleted successfully!\n", category);
        return;
    }
    while (temp != NULL && strcmp(temp->category, category) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Task \"%s\" deleted successfully!\n", category);
}

// Function to search for a task
void searchTask(Task* head, char title[]) {
    Task* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Task Found: %s | Category: %s | Priority: %s | Reminder: %s\n", temp->title, temp->category, temp->priority, temp->reminder);
            return;
        }
        temp = temp->next;
    }
    printf("Task not found.\n");
}

int main() {
    Task* taskList = NULL;
    
    addTask(&taskList, "Buy groceries", "Personal", "High", "5 PM");
    addTask(&taskList, "Complete project", "Work", "Urgent", "Tomorrow");
    
    printf("\nTask List:\n");
    viewTasks(taskList);
    
    printf("\nDeleting a task...\n");
    deleteTask(&taskList, "Personal");
    
    printf("\n Searching the task...\n");
    searchTask(taskList,"Buy groceries");
    
    printf("\nUpdated Task List:\n");
    viewTasks(taskList);
    
    return 0;
}
