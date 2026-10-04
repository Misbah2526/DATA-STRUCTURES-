#include <iostream>
#include <string>
using namespace std;

// Item node (bottom level)
struct Item {
    string name;
    int quantity;
    Item *next;
};

// Section node (middle level)
struct Section {
    string sectionName;
    Section *next;
    Item *itemsHead;
};

// Store node (top level)
struct Store {
    string storeName;
    Store *next;
    Section *sectionsHead;
};

Store *storesHead = NULL;

Store* findStore(string name) {
    Store *p = storesHead;
    while (p != NULL) {
        if (p->storeName == name) return p;
        p = p->next;
    }
    return NULL;
}

Section* findSection(Store *store, string name) {
    if (store == NULL) return NULL;
    Section *p = store->sectionsHead;
    while (p != NULL) {
        if (p->sectionName == name) return p;
        p = p->next;
    }
    return NULL;
}

// Add a new store
void addStore(string name) {
    Store *p = new Store;
    p->storeName = name;
    p->next = NULL;
    p->sectionsHead = NULL;
    
    if (storesHead == NULL) storesHead = p;
    else {
        Store *temp = storesHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
    cout << "Store added: " << name << endl;
}

// Add a new section in a store
void addSection(string storeName, string sectionName) {
    Store *store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }
    
    if (findSection(store, sectionName) != NULL) {
        cout << "Section already exists\n";
        return;
    }
    
    Section *p = new Section;
    p->sectionName = sectionName;
    p->next = NULL;
    p->itemsHead = NULL;
    
    if (store->sectionsHead == NULL) store->sectionsHead = p;
    else {
        Section *temp = store->sectionsHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
    cout << "Section added: " << sectionName << " in " << storeName << endl;
}

// Store an item in a particular section of a particular store
void addItem(string storeName, string sectionName, string itemName, int qty) {
    Store *store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }
    
    Section *section = findSection(store, sectionName);
    if (section == NULL) { cout << "Section not found\n"; return; }
    
    Item *p = new Item;
    p->name = itemName;
    p->quantity = qty;
    p->next = NULL;
    
    if (section->itemsHead == NULL) section->itemsHead = p;
    else {
        Item *temp = section->itemsHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
    cout << "Item added: " << itemName << " (" << qty << ") in " 
         << storeName << " -> " << sectionName << endl;
}

// Remove an item from a particular section of a particular store
void removeItem(string storeName, string sectionName, string itemName) {
    Store *store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }
    
    Section *section = findSection(store, sectionName);
    if (section == NULL) { cout << "Section not found\n"; return; }
    
    Item *current = section->itemsHead;
    Item *prev = NULL;
    
    while (current != NULL) {
        if (current->name == itemName) {
            if (prev == NULL) section->itemsHead = current->next;
            else prev->next = current->next;
            delete current;
            cout << "Item removed: " << itemName << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Item not found: " << itemName << endl;
}

// Display list of all items of a particular section of a store
void displaySectionItems(string storeName, string sectionName) {
    Store *store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }
    
    Section *section = findSection(store, sectionName);
    if (section == NULL) { cout << "Section not found\n"; return; }
    
    cout << "Items in " << storeName << " -> " << sectionName << ": ";
    Item *p = section->itemsHead;
    while (p != NULL) {
        cout << p->name << "(" << p->quantity << ") ";
        p = p->next;
    }
    cout << endl;
}

// Display list of items for a given store
void displayStoreItems(string storeName) {
    Store *store = findStore(storeName);
    if (store == NULL) { cout << "Store not found\n"; return; }
    
    cout << "Store: " << storeName << endl;
    Section *s = store->sectionsHead;
    while (s != NULL) {
        cout << "  Section " << s->sectionName << ": ";
        Item *p = s->itemsHead;
        while (p != NULL) {
            cout << p->name << "(" << p->quantity << ") ";
            p = p->next;
        }
        cout << endl;
        s = s->next;
    }
}

int main() {
    addStore("Walmart");
    addStore("Target");
    
    addSection("Walmart", "Toys");
    addSection("Walmart", "Grocery");
    addSection("Target", "Fruits");
    
    addItem("Walmart", "Toys", "Lego", 50);
    addItem("Walmart", "Toys", "Doll", 30);
    addItem("Walmart", "Grocery", "Milk", 100);
    addItem("Target", "Fruits", "Apple", 200);
    
    displaySectionItems("Walmart", "Toys");
    displayStoreItems("Walmart");
    
    removeItem("Walmart", "Toys", "Doll");
    displaySectionItems("Walmart", "Toys");
    
    return 0;
}