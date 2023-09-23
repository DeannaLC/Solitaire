#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <thread>
#include <array>
#include <chrono>
#include <algorithm>
using namespace std;

class Card{
    string suit;
    string name;
    int val;
    bool shown = false;

    public:
    Card(string x, string y, int z){
        suit = x;
        name = y;
        val = z;
    }

    public:
    Card(){
        name = "ERROR";
    }

    public:
    void setName(string n){
        name = n;
    }

    public:
    string getSuit(){
         return suit;
    }

    public:
    string getName(){
        return name;
    }

    public:
    int getVal(){
        return val;
    }

    public:
    bool getShown(){
        return shown;
    }

    public:
    void setShown(bool x){
        shown = x;
    }

    public:
    string toString(){
        //cout << "reached \n";
        if (val == 9){
           // cout << name + suit.substr(0, 1);
            return name + suit.substr(0, 1);
        }
        //name.substr(0, 1) + suit.substr(0, 1);
        return name.substr(0, 1) + suit.substr(0, 1);
    }

    public:
    bool oppositeSuits(Card check){
        return (((check.suit == "Hearts") || (check.suit == "Diamonds")) && ((suit == "Clubs") || (suit == "Spades"))) || (((check.suit == "Clubs") || (check.suit == "Spades")) && ((suit == "Diamonds") || (suit == "Hearts")));
    }

    //true if card in parameter(check) is one higher
    public:
    bool oneHigher(Card check){
        return (check.val - 1) == val;
    }
};

class Deck{
    vector<Card> deck;
    vector<string> cardNames{"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    public:
    Deck(){
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("Hearts", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("Diamonds", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("Spades", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("Hearts", cardNames[i], i));
        }
    }

    public:
    Deck(int z){
    }

    public:
    Deck copyDeck(){
        Deck dupe = Deck(1);
        for (int i = 0; i < deck.size(); i = i + 1){
            dupe.deck.push_back(deck[i]);
        }
        return dupe;
    }

    public:
    Card randomCard(){
        int randIdx = rand() % deck.size();
        Card ret = deck[randIdx];
        deck.erase(deck.begin() + randIdx);
        return ret;
    }

    public:
    vector<Card> getDeck(){
        return deck;
    }

    public:
    void shuffleDeck(){
        srand(time(0));
        int randIdx1 = 0;
        int randIdx2 = 0;
        Card save1 = Card("", "", 0);
        Card save2 = Card("", "", 0);
        for (int i = 0; i < deck.size(); i = i + 1){
            randIdx1 = rand() % deck.size();
            //cout << randIdx1 << "\n";
            randIdx2 = rand() % deck.size();
            //cout << randIdx2 << "\n";
            save1 = deck[randIdx1];
            save2 = deck[randIdx2];
            deck[randIdx1] = save2;
            deck[randIdx2] = save1;
        }
    }

    public:
    string toString(){
        string ret = "";
        for (int i = 0; i < deck.size(); i = i + 1){
            if (i == (deck.size() - 1)){
                ret = ret + deck[i].toString();
            }
            else
                ret = ret + deck[i].toString() + ", ";
        }
        return ret;
    }
};

class Solitaire{
    Deck deck = Deck();
    Deck masterCopy = deck.copyDeck();
    vector<Card> bin1;
    vector<Card> bin2;
    vector<Card> bin3;
    vector<Card> bin4;
    vector<Card> bin5;
    vector<Card> bin6;
    vector<Card> bin7;
    vector<Card> ace1;
    vector<Card> ace2;
    vector<Card> ace3;
    vector<Card> ace4;
    vector<vector<Card>> allBins;

    public:
    Solitaire(){
        srand(time(0));
        bin1.push_back(deck.randomCard());

        bin2.push_back(deck.randomCard());
        bin2.push_back(deck.randomCard());

        bin3.push_back(deck.randomCard());
        bin3.push_back(deck.randomCard());
        bin3.push_back(deck.randomCard());

        bin4.push_back(deck.randomCard());
        bin4.push_back(deck.randomCard());
        bin4.push_back(deck.randomCard());
        bin4.push_back(deck.randomCard());

        bin5.push_back(deck.randomCard());
        bin5.push_back(deck.randomCard());
        bin5.push_back(deck.randomCard());
        bin5.push_back(deck.randomCard());
        bin5.push_back(deck.randomCard());

        bin6.push_back(deck.randomCard());
        bin6.push_back(deck.randomCard());
        bin6.push_back(deck.randomCard());
        bin6.push_back(deck.randomCard());
        bin6.push_back(deck.randomCard());
        bin6.push_back(deck.randomCard());

        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());
        bin7.push_back(deck.randomCard());

        allBins = vector<vector<Card>>{bin1, bin2, bin3, bin4, bin5, bin6, bin7};
        deck.shuffleDeck();
    }

    public:
    void declareShown(){
        Card change;
        vector<Card> row;
        for (int i = 0; i < 7; i = i + 1){
            row = allBins[i];
            row[row.size() - 1].setShown(true);
            allBins[i] = row;
        }
    }

    public:
    void clearAllShown(){
        Card cur = Card();
        for (int i = 0; i < masterCopy.getDeck().size(); i = i + 1){
            cur = masterCopy.getDeck()[i];
            cur.setShown(false);
        }
    }

    public:
    int largestBinSize(){
        int curMax = 0;
        int curVal = 0;
        for (int i = 0; i < 7; i = i + 1){
            curVal = allBins[i].size();
            if (allBins[i].size() > curMax)
                curMax = curVal;
        }
        return curMax;
    }

    public:
    vector<vector<Card>> getAllBins(){
        return allBins;
    }

    public:
    bool cardMatch(Card onBoard, Card inDeck){
        return onBoard.oppositeSuits(inDeck) && onBoard.oneHigher(inDeck);
    }

    string vectorToString(vector<Card> h){
        string ret = "";
        Card curCard = Card();
        for (int i = 0; i < h.size(); i = i + 1){
            curCard = h[i];
            ret = ret + curCard.toString();
        }
        return ret;
    }

    public:
    Deck getDeck(){
        return deck;
    }

    public:
    string toString(){
        declareShown();
        string square = "";
        string grid = "";
        vector<Card> curBin;
        Card curCard;
        for (int i = 0; i < largestBinSize(); i = i + 1){
                for (int k = 0; k < 7; k = k + 1){ 
                    curBin = allBins[k];
                    //cout << vectorToString(curBin) + "\n";
                    if (curBin.size() > i){
                        curCard = curBin[i];
                        if (curCard.getShown() == true){
                            square = " " + curCard.toString();
                            if (square.length() == 4)
                                square = square + " ";
                            else
                                square = square + "  ";
                        }
                        else
                            square = "  x  ";
                    }
                    else{
                        square = "     ";
                    }
                    grid = grid + square;
                }
            grid = grid + "\n";
        }
        return grid;
    }
};

int main(){
    Deck d = Deck();
    Solitaire s = Solitaire();
    cout << s.toString();
    cout << s.getDeck().getDeck().size();
}