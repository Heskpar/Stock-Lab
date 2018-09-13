#include "lab.h"

StockExchange GOOGse(5);
StockExchange INTLse(5);
StockExchange AAPLse(5);
vector<Log> logsV; //Log vector is also global so I 
                    //can reference it in Place order pressed
string hist = "Transaction Log\n";

Fl_Double_Window window(WIDTH, HEIGHT);
bool wantToBuy = true;

int main()
{
    // Logo provided by Mingun Inc.
	std::cout <<
	"/ ************************************* \\\n"
	"* CS124 - STOCK EXCHANGE       MADE BY. *\n"
	"* Dean Huang  : Gevorg Keshishian       *\n"
	"* Mingyun Kim : Muhammed Hassan Mahmood *\n"
	"\\ ************************************* /\n"
	<< std::endl;
    //Open cool stuff
    createAllWidgets();
    showMenuScreen();
    window.label("Stock Market");
    window.show();
    
    GOOGse.populate("GOOG");//Populate the 3 companies
    INTLse.populate("INTL");
    AAPLse.populate("AAPL");
    
    Fl::run();
}
