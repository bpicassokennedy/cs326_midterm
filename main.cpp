#include <iostream>
using namespace std;

string userInput(); 
bool isPalindrome(string s);

int main(){
    string input = userInput();
    bool palindrome = isPalindrome(input);
    if(palindrome){
        cout << input << " is a palindrome!" << endl;
    } else{
        cout << input << " is not a palindrome :( " << endl;
    }
    return 0;
}

string userInput(){ //gets user input, will eventually pass this string into isPalindrome 
    string word;
    cout << "Enter a word to check if it's a palindrome: ";
    getline(cin, word);
    return word;
}

bool isPalindrome(string s){
    int n = s.length(); //calculate the length of the user's string
    for(int i = 0; i < n/2; i++){ //iterates through only half of the string (we only need to check half for palindromes)
        if(s[i] != s[n - i - 1]){ //checks first element of the string with the last element
            return false; //if characters are not the same, it's not a palindrome! 
        }
    }
    return true; //yay! characters are the same throughout, string is a palindrome
}