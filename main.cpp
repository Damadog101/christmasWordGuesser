#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void dummifyString(string& s) {
    for (int i = 0; i < s.length(); i++) {
        s.at(i) = tolower(s.at(i));
    }
}

void chooseWord(string& word, string& codeWord) {
    ifstream ifs;
    int randInt;
    
    ifs.open("words.txt");
        randInt = rand() % 100;
        for (int i = 0; i < randInt; i++) {
            word = "";
            ifs >> word;
            //cout << word << endl;
        }
        //cout << "word after done" << word << endl;
    ifs.close();
    dummifyString(word);
    codeWord = "";
    for (int j = 0; j < word.length(); j++) {
        codeWord += "*";
    }
    //cout << word << " " << codeWord << endl;
}

int main()  {
    bool continuePlaying = true;
    bool hasWonGame = false;
    string goalWord = "";
    srand(time(0));
    string hiddenWord = "";
    string currentGuess = "";
    string playAgain = "";

    while (continuePlaying) {
        chooseWord(goalWord, hiddenWord);
        hasWonGame = false;

        //cout << goalWord << " " << hiddenWord << endl;
        while (!hasWonGame) {
            cout << "Guess the Christmas Themed Word: " << hiddenWord << endl;
            cin >> currentGuess;
            dummifyString(currentGuess);
            if (currentGuess == goalWord) {
                hasWonGame = true;
                cout << "You Win! The Word Was " << goalWord << endl;
                cout << "Would You Like To Play Again? (Type 1 For Yes, Type 0 For No)" << endl;
                cin >> playAgain;
                if (playAgain == "0") {
                    continuePlaying = false;
                } else if (playAgain == "1") {
                    continuePlaying = true;
                } else {
                    cout << "Invalid Input. Ending Game." << endl;
                    continuePlaying = false;
                }
            } else {
                if ((goalWord.length() == currentGuess.length())) {
                    for (int i = 0; i < goalWord.length(); i++) {
                       if (currentGuess.at(i) == goalWord.at(i)) {
                          hiddenWord.at(i) = goalWord.at(i);
                      }

                    }
                } else {
                    cout << "Your Guess Is Not The Same Length As The Answer!" << endl;
                }
            }
        }

    }



    return 0;
}