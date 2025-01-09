#include <iostream>
using namespace std;

int menu();
string userInput(); 
bool isPalindrome(string s);

int main(){
    int choice;
    do{
        choice = menu();
        if(choice == 1){
            string input = userInput();
            bool palindrome = isPalindrome(input);
            if(palindrome){
                cout << input << " is a palindrome! :)" << endl << endl;
            } else{
            cout << input << " is not a palindrome... :( " << endl << endl;
            }
        } else{
            cout << "Goodbye! :)" <<    endl;
        }
    }while(choice != 2); //as long as the user doesn't choose to exit the program keep repeating!
    return 0;
}

int menu(){ //presents to the user after each word, phrase, or sequence is checked. giving them the option to check another word or exit
    string input;
    int choice;
    cout << "--- PALINDROME CHECKER! ---" <<    endl;
    cout << "Palindrome Defintion: a word, phrase, or sequence that reads the same backward as forward" <<  endl;
    cout << "----------------------------" <<   endl;
    cout << "1. Check to see if a word is a palindrome" <<  endl;
    cout << "2. Exit " <<   endl;
    cout << "Enter your choice: ";
    getline(cin, input);
    choice = stoi(input);
    while(choice != 1 && choice != 2){
        cout << "Invalid option! Try again: ";
        getline(cin, input);
        choice = stoi(input);
    }
    return choice;
}

string userInput(){ //gets user input, will eventually pass this string into isPalindrome 
    string input, finalString;
    cout << "Enter a word to check if it's a palindrome: ";
    getline(cin, input);
    for(int i = 0; i < input.length(); i++){ //removes and leading and trailing spaces
        if(input[i] != ' '){
            finalString += input[i];
        }
    }
    return finalString;
}

bool isPalindrome(string s){
    int n = s.length(); //calculate the length of the user's string
    for(int i = 0; i <= n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32; //converts the uppercase to lowercase so the program is not case sensitive
        }
    }
    for(int i = 0; i < n/2; i++){ //iterates through only half of the string (we only need to check half for palindromes)
        if(s[i] != s[n - i - 1]){ //checks first element of the string with the last element
            return false; //if characters are not the same, it's not a palindrome! 
        }
    }
    return true; //yay! characters are the same throughout, string is a palindrome
}