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
    void setShown(bool x){
        shown = x;
    }

    public:
    string toString(){
        return "" + name + " of " + suit;
    }

};

class Deck{
    vector<Card> deck;
    vector<string> cardNames{"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};

    public:
    Deck(){
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("hearts", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("diamonds", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("spades", cardNames[i], i));
        }
        for (int i = 0; i < 13; i = i + 1){
            deck.push_back(Card("hearts", cardNames[i], i));
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
        srand(time(0));
        int randIdx = rand() % 52;
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
            cout << randIdx1 << "\n";
            randIdx2 = rand() % deck.size();
            cout << randIdx2 << "\n";
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

    public:
    Solitaire(){
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

        deck.shuffleDeck();
    }

    public:
    void declareShown(){
        bin1[bin1.size()].setShown(true);
        bin2[bin2.size()].setShown(true);
        bin3[bin3.size()].setShown(true);
        bin4[bin4.size()].setShown(true);
        bin5[bin5.size()].setShown(true);
        bin6[bin6.size()].setShown(true);
        bin7[bin7.size()].setShown(true);
    }

    public:
    void clearAllShown(){
        Card cur = Card("", "", 1);
        for (int i = 0; i < masterCopy.getDeck().size(); i = i + 1){
            cur = masterCopy.getDeck()[i];
            cur.setShown(false);
        }
    }

    public:
    int maxBinSize(){
        int curMax = 0;
        int curVal = 0;
        for (int i = 0; i < 7; i = i + 1){
            
        }
        return curMax;
    }

    public:
    string toString(){
        string ret = "";

        return ret;
    }
};

int main(){
    Deck d = Deck();
    /*Card x = d.randomCard();
    cout << x.getSuit() << "\n";
    cout << x.getName() << "\n";
    cout << x.getVal() << "\n";
    cout << d.getDeck().size() << "\n";

    //x = d.getDeck()[0];
    x = d.randomCard();
    cout << x.getName() << "\n";
    //d.shuffle();
    //x = d.getDeck()[0];
    x = d.randomCard();
    cout << x.getName() << "\n";
    //d.shuffle();
    //x = d.getDeck()[0];
    x = d.randomCard();
    cout << x.getName() << "\n";*/
    //random_device rd;
    //uniform_int_distribution<int> dist(1, 52);
    //int randIdx1 = rd();
    //int randIdx2 = rd();
    //cout << rd() << "\n";
    //cout << rd() << "\n";
    //system("pause");

    srand(time(0));
    int idx1 = rand() % 52;
    int idx2 = rand() % 52;
    cout << idx1 << "\n";
    cout << idx2;
    cout << d.toString() << "\n";
    d.shuffleDeck();
    cout << d.toString();
}