#include "function.h"
 
int main() 
{  
    int menuSelect;
    string inputWord, inputMeaning, command;
    Dictionary test1;

    test1.addNewWord("Alice", "80"); 
	test1.addNewWord("Pooja", "85"); 
	test1.addNewWord("Ramesh", "83"); 
	test1.addNewWord("Mark", "88"); 

do  {
        menu();
        cout << endl;
        fflush(stdin);

        cin >> menuSelect;
        switch (menuSelect)
        {
        case 1:  
            cout << "Input a word: ";
            cin >> inputWord;
            cout << test1.searchKeyword(inputWord) << endl;
            test1.addToHistory(inputWord);
            break;

        case 2:
             cout << "Enter word to add to favorite list: " << endl;
             cin >> inputWord;
             test1.addToFavoriteList(inputWord);
             break;

        case 3:
            cout << "History of search word: " << endl;
            test1.viewHistoryOfSearchWord();
            break;

        case 4:
            cout << "Enter a new word: ";
            cin >> inputWord;
            cout << "Enter word meaning: ";
            cin >> inputMeaning;
            test1.addNewWord(inputWord,inputMeaning);
            break;
    
        case 5:
            cout << "Enter word to edit definition: ";
            cin >> inputWord;
            cout << "Enter new meaning: ";
            cin >> inputMeaning;
            test1.editDefinition(inputWord, inputMeaning);
            break;

        case 6:
            cout << "Not ready" << endl;
            break;

        case 7:
            cout << "Not ready" << endl;
            break;

        case 8:
            cout << "Not ready" << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
        
    fflush(stdin);
        cout << "\nWould you like to continue or exit? (Continue/Exit) ";
        cin >> command;
    }
    while(command == "continue" || command == "Continue" || command == "CONTINUE");

    cout << "Thanks for using our Dictionary.\n";
  
	return 0; 
} 