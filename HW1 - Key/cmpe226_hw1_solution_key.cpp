#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

class FoodItem {
public:
    string name;
    double price;
    bool available;

    FoodItem() : name(""), price(0.0), available(false) {}  // Default constructor

    FoodItem(string n, double p, bool a) : name(n), price(p), available(a) {}

    // ostream overload
    friend ostream& operator<<(ostream& os, const FoodItem& item) {
        os << item.name << " ($" << item.price << ") "
           << (item.available ? "[Available]" : "[Not Available]");
        return os;
    }
};

// Kategori için
struct Category {
    string name;
    LinkedList<FoodItem> foodList;
};

// 3 kategorilik dizi
const int CATEGORY_COUNT = 3;
Category categories[CATEGORY_COUNT] = {
    {"Appetizers"},
    {"MainCourse"},
    {"Desserts"}
};

// Menüye yiyecek ekleme
void addFoodItem(string category, string name, double price, bool available) {
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        if (categories[i].name == category) {
            FoodItem item(name, price, available);
            categories[i].foodList.insertLast(item);
            return;
        }
    }
}

// Menü görüntüleme
void displayMenu() {
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        cout << "\nCategory: " << categories[i].name << "\n";
        cout << categories[i].foodList;  // LinkedList'in << operatoru çaðrýlacak
    }
}

// Menü dosyadan yüklenir
void loadMenuFromFile() {
    ifstream inp("menu.txt");
    if (!inp) {
        cout << "Error opening file!" << endl;
        return;
    }

    string category, name;
    double price;
    int availability;
    string line;
    while (!inp.eof())
    { inp>>category>>name>>price>>availability;
      addFoodItem(category, name, price, availability);
	}

   /* while (getline(file, line)) {
        stringstream ss(line);
        ss >> category;
        if (category == "Main") {
            string temp;
            ss >> temp;
            category += " " + temp;
        }

        getline(ss >> ws, name, '"');
        getline(ss, name, '"');

        ss >> price >> availability; */

      //  addFoodItem(category, name, price, availability);
    

    inp.close();
}

// Belleği temizle
void freeMemory() {
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        categories[i].foodList.destroyList();
    }
}

int main() {
    loadMenuFromFile();
    displayMenu();
    freeMemory();
    return 0;
}
