#include "function.h"


void menu()
{
    cout << "Please enter to select: " << endl;
    cout << "1: Search for a word" << endl;
    cout << "2: Add word to favorite list" << endl;
    cout << "3: View history of search word" << endl;
    cout << "4: Add new word and definition" << endl;
    cout << "5: Edit definition" << endl;
    cout << "6: Remove a word" << endl;
    cout << "7: Reset dictionary" << endl;
    cout << "8: View randomw word and definition" << endl;
}

Trie* Trie::getNewTrie(string word, string meaning) 
{ 
	Trie* node = new Trie; 
    node->keyWord = word;
    node->definition = meaning;
	node->isEndOfName = false;  
    return node;
} 


void Dictionary::addNewWord(const string& str, string meaning) 
{ 
	if (root == NULL) 
		root = root->getNewTrie(str,meaning); 

	Trie* temp = root; 

	for (int i = 0; i < str.length(); i++) { 
		char x = str[i]; 

		if (temp->map.find(x) == temp->map.end()) 
			temp->map[x] = temp->map[x]->getNewTrie(str, meaning); 

		temp = temp->map[x]; 
	} 

	temp->isEndOfName = true; 
    temp->keyWord = str;
	temp->definition = meaning; 
} 


 
string Dictionary::searchKeyword(const string& st) 
{ 

	if (root == NULL) 
		return "Not found"; 

	Trie* temp = root; 

	for (int i = 0; i < st.length(); i++) { 
		temp = temp->map[st[i]]; 
		if (temp == NULL) 
			return "Not found"; 
	    } 

	
 
	if (temp->isEndOfName) 
		return temp->definition; 
	return "Not found"; 
} 

void Dictionary::editDefinition(const string& st, string newMeaning) 
{ 

	if (root == NULL) 
		return; 

	Trie* temp = root; 



	for (int i = 0; i < st.length(); i++) { 
		temp = temp->map[st[i]]; 
		if (temp == NULL) 
			return; 
	    } 

	
 
	if (temp->isEndOfName) 
		temp->definition = newMeaning; 
	return; 
} 

void Dictionary::addToFavoriteList(const string& st) 
{ 
    fstream my_file;
	my_file.open("FavoriteList.txt", ios::out);
	if (!my_file) {
		cout << "File not created!";
	}
	else {
        if (root == NULL) 
		cout << "Cannot add to favorite list";
        return;

	    Trie* temp = root; 

	    for (int i = 0; i < st.length(); i++) { 
		    temp = temp->map[st[i]]; 
		    if (temp == NULL)
                cout << "Cannot add to favorite list";
                return;
	    
        }	
 
	    if (temp->isEndOfName) 
		    my_file << st << " " << temp->definition; 
	    return; 
		my_file.close();
	}
} 

void Dictionary::addToHistory(const string& st)
{
	fstream my_file;
	my_file.open("HistoryList.txt", ios::out);
	if (!my_file) {
		cout << "File not created!";
	}
	else {
        my_file << st << endl;
		my_file.close();
	}
}

void Dictionary::viewHistoryOfSearchWord()
{
	string line;
  	ifstream myfile ("HistoryList.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
      		cout << line << '\n';
    	}
    	myfile.close();
  	}

  	else cout << "Unable to open file";
}