#include <iostream>
using namespace std;

void menu();
string userInput(); 
bool isPalindrome(string s);

int main(){
    int choice;
    do{
        menu();
        string input1 = userInput();
        choice = stoi(input1);
        while(choice < 1 || choice > 2){ //keep requesting user input until it's a valid integer
            cout << "Invalid option! Try again: ";
            input1 = userInput();
            choice = stoi(input1);
        }
        if(choice == 1){
            cout << "Enter a word to check if it's a palindrome: ";
            string input2 = userInput();
            bool palindrome = isPalindrome(input2);
            if(palindrome){
                cout << input2 << " is a palindrome! :)" << endl << endl;
            } else{
            cout << input2 << " is not a palindrome... :( " << endl << endl;
            }
        } else{
            cout << "Goodbye! :)" <<    endl;
        }
    }while(choice != 2); //as long as the user doesn't choose to exit the program keep repeating!
    return 0;
}

void menu(){ //presents to the user after each word, phrase, or sequence is checked. showing them their options to check another word or exit
    cout << "--- PALINDROME CHECKER! ---" << endl;
    cout << "Palindrome Defintion: a word, phrase, or sequence that reads the same backward as forward" <<  endl;
    cout << "----------------------------" << endl;
    cout << "1. Check to see if a word is a palindrome" << endl;
    cout << "2. Exit " << endl;
    cout << "Enter your choice: ";
}

string userInput(){ //gets user input, used for getting user's choice from the menu and inputting their desired string
    string input;
    getline(cin, input);
    return input; //returns user input as they initially entered it into the terminal
}

bool isPalindrome(string s){
    string finalStr;
    for(int i = 0; i < s.length(); i++){ 
        if(s[i] != ' '){ //removes all leading, trailing, and seperation spaces. done in this function to avoid the phrase being tampered w/ when displayed to the terminal 
            if(s[i] >= 'A' && s[i] <= 'Z'){ //converts capital letters to lowercase, so the palindrome check is not case sensitive
                finalStr += s[i] + 32; 
            }
            else{
                finalStr += s[i]; //if character is already lowercase, just add it into the new string
            }
        }
    }
    int n = finalStr.length(); //calculate the length of the user's string
    for(int i = 0; i < n/2; i++){ //iterates through only half of the string (we only need to check half for palindromes)
        if(finalStr[i] != finalStr[n - i - 1]){ //checks first element of the string with the last element
            return false; //if characters are not the same, it's not a palindrome! 
        }
    }
    return true; //yay! characters are the same throughout, string is a palindrome
}