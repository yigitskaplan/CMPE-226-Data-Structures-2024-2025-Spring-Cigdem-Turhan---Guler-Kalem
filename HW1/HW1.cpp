//Yiğit Şevki Kaplan - 23244710009


#include <iostream>
#include <fstream>
#include "LL.h"
#include <string>

using namespace std;

class Food 
{
public:
    string category, name, price;
    bool avail;

    Food(){}
    
    friend ostream& operator<<(ostream& os, const Food& obj) 
    {
        os<<"- "<<obj.name<<" ($"<< obj.price<<") "<<"["<<(obj.avail ? "Available" : "Not Available")<<"]"<<endl;
        return os;
    }
    
    bool operator==(Food &food) 
    {
        return name == food.name;
    }
};

void addFoodItem(LL<Food> categories[], Food f) 
{
    if (f.category == "Appetizers ") 
    {
        categories[0].insertLast(f);
    }
    else if (f.category == "Main Course ") 
    {
        categories[1].insertLast(f);
    }
    else if (f.category == "Desserts ") 
    {
        categories[2].insertLast(f);
    }
}

void displayMenu(LL<Food> categories[]) 
{
    string catNames[3] = {"Appetizers", "Main Course", "Desserts"};
    for (int i = 0; i < 3; i++) 
    {
        cout << "Category: " << catNames[i] << endl;
        cout << categories[i];
        cout << endl;
    }
}

void readMenu(const string &filename, LL<Food> categories[]) 
{
    ifstream inp(filename);
    if (!inp) 
    {
        cerr<<"Failed to open "<<filename<<" file!"<<endl;
        return;
    }
    
    string line;
    while (getline(inp, line)) 
    {
        Food f;
        string temp = "";
        int stage = 0; // 0 = category, 1 = name, 2 = price, 3 = availability
        
        for (int i = 0; i < line.length(); i++) 
        {
            char c = line[i];
            
            if (stage == 0) // Reading category
            { 
                if (c == '"') 
                {
                    f.category = temp;
                    temp = "";
                    stage++;
                }
                else 
                {
                    temp += c;
                }
            }
            else if (stage == 1) // Reading name (inside quotes)
            { 
                if (c == '"') 
                {
                    f.name = temp;
                    temp = "";
                    stage++;
                }
                else 
                {
                    temp += c;
                }
            }
            else if (stage == 2) // Reading price
            {
                if (c != ' ')
                    temp += c;
                
                if ((c == ' ' || i == line.length() - 1) && !temp.empty()) 
                {
                    f.price = temp;
                    temp = "";
                    stage++;
                }
            }
            else if (stage == 3) // Reading availability
            { 
                if (c == '0')
                    f.avail = false;
                else if (c == '1')
                    f.avail = true;
                break;
            }
        }
        
        addFoodItem(categories, f);
    }

    inp.close();
}

int main()
{
    LL<Food> categories[3];
    
    readMenu("menu.txt", categories);
    
    displayMenu(categories);
    
    return 0;
}