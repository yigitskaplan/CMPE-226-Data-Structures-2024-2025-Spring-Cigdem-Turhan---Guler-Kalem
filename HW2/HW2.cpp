// Yiğit Şevki Kaplan - 23244710009


#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{
    int choice;
    Stack<string> stack;
    string sentence;

    
    do{
        cout << endl << "--- Text Editor Simulation ---" << endl;
        cout << "1. Write new sentence" << endl;
        cout << "2. Undo last sentence" << endl;
        cout << "3. Show last sentence" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice == 1){
            cout << "Enter a sentence: ";
            getline(cin, sentence);
            stack.push(sentence);
            cout << "Sentence added." << endl;
        } else if (choice == 2){
            if (!stack.isEmpty()){
                cout << "Last sentence removed: " << "\"" << stack.pop() << "\"" << endl;
            } else {
                cout << "No sentences to undo." << endl;
            }
        } else if (choice == 3){
            if (!stack.isEmpty()){
                cout << "Last sentence: " << "\"" << stack.stop() << "\"" << endl;
            } else {
                cout << "No sentences available." << endl;
            }
        } else if (choice == 4){
            cout << "Exiting the program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }while (choice != 4);

    stack.destroy();

    return 0;
}