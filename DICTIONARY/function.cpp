#include "function.h"



void menu()
{
    cout << "-----WELCOME TO OUR DICTIONARY-----" << endl;
    cout << "1: Search for a word" << endl;
    cout << "2: Add word to favorite list" << endl;
    cout << "3: View favorite list" << endl;
    cout << "4: View history of search word" << endl;
    cout << "5: Add new word and definition" << endl;
    cout << "6: Edit definition" << endl;
    cout << "7: Remove a word" << endl;
    cout << "8: Reset dictionary" << endl;
    cout << "9: View randomw word and definition" << endl;
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
        root = root->getNewTrie(str, meaning);

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
    ofstream foutput;
    ifstream finput;
    finput.open("FavoriteList.txt");
    foutput.open("FavoriteList.txt", ios::app);

    if (finput.is_open())
        foutput << st << "   " << searchKeyword(st) << "\n";

    finput.close();
    foutput.close();
}

void Dictionary::addToHistory(const string& st)
{
    ofstream foutput;
    ifstream finput;
    finput.open("HistoryList.txt");
    foutput.open("HistoryList.txt", ios::app);

    if (finput.is_open())
        foutput << st << "\n";

    finput.close();
    foutput.close();
}

void Dictionary::viewFavoriteList()
{
    string line;
    ifstream myfile("FavoriteList.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

void Dictionary::viewHistoryOfSearchWord()
{
    string line;
    ifstream myfile("HistoryList.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}