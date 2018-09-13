#ifndef LABH
#define LABH

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "HeapMing.h"
#include "Order.h"
#include "Log.h"
#include "StockExchange.h"
using namespace std;

//This is so that we can convert integers to string in the transaction log
template<typename T> 
string to_string(const T& x) 
{
    std::ostringstream os;
    os << x;
    return os.str();
}

const int WIDTH = 600;
const int HEIGHT = 600;
const string NAMES[]= {"GOOG", "INTL", "AAPL"};
extern bool wantToBuy;

void buyPressed_cb(Fl_Widget*);
void sellPressed_cb(Fl_Widget*);
void placeOrderPressed_cb(Fl_Widget*);

void createAllWidgets();
void hideMenuScreen();
void showMenuScreen();
void showInputScreen();
void hideInputScreen();
void showInputScreen();

extern Fl_Double_Window window;
extern Fl_Choice* stockNameInput;
extern Fl_Input* numberSharesInput;
extern Fl_Input* priceInput;
extern Fl_Box* stockInfo1;
extern Fl_Box* stockInfo2;
extern Fl_Box* stockInfo3;
extern Fl_Box* stockInfo4;
extern Fl_Box* stockInfo5;
extern Fl_Box* stockInfo6;
extern Fl_Button* sellB;
extern Fl_Button* buyB;
extern Fl_Button* placeOrderB;
extern Fl_Text_Buffer* historyBuffer;
extern Fl_Text_Display* history;

extern StockExchange GOOGse;
extern StockExchange INTLse;
extern StockExchange AAPLse; 
extern vector<Log> logsV;
extern string hist;

#endif
