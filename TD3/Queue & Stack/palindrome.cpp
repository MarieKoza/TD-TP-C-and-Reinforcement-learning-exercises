#include <iostream> 
//#include <queue> 
#include <stack> 
#include <cctype>
using namespace std ;

bool isPalindrome(const string& input) { // Votre code
    bool isTrue = false;
    stack<char> stk;
    string reverse;

    for (int i=0; i< input.length(); i++){
        stk.push(input.at(i));
    }
    while (!stk.empty()){
        reverse.push_back(stk.top());
        stk.pop();
    }
    
    if (reverse == input){
        isTrue = true;
    }

    return isTrue;
}

int main() {
cout << boolalpha ;
cout << "Is 'racecar ' a palindrome? " << isPalindrome("racecar") << endl;
cout << "Is ' hello ' a palindrome? " << isPalindrome("hello") << endl;
return 0 ; }