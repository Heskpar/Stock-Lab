#include "lab.h"

Fl_Box* stockInfo1;
Fl_Box* stockInfo2;
Fl_Box* stockInfo3;
Fl_Box* stockInfo4;
Fl_Box* stockInfo5;
Fl_Box* stockInfo6;
Fl_Button* buyB;
Fl_Button* sellB;
Fl_Button* placeOrderB;
Fl_Text_Buffer* historyBuffer;
Fl_Text_Display* history;
Fl_Choice* stockNameInput;
Fl_Input* numberSharesInput;
Fl_Input* priceInput;

void createAllWidgets()
{
    Order peek;
    window.label("Stock Market");
    window.show();

    stockInfo1 = new Fl_Box(0, 0, WIDTH/3, HEIGHT/8);
    stockInfo1->label("GOOG");
    stockInfo1->hide();
    stockInfo1->box(FL_BORDER_BOX);
    window.add(stockInfo1);
    
    stockInfo2 = new Fl_Box(WIDTH/3, 0, WIDTH/3, HEIGHT/8);
    stockInfo2->label("INTL");
    stockInfo2->box(FL_BORDER_BOX);
    stockInfo2->hide();
    window.add(stockInfo2);
    
    stockInfo3 = new Fl_Box(2*WIDTH/3, 0, WIDTH/3, HEIGHT/8);
    stockInfo3->label("AAPL");
    stockInfo3->box(FL_BORDER_BOX);
    stockInfo3->hide();
    window.add(stockInfo3);
    
    
    stockInfo4 = new Fl_Box(0, HEIGHT/8, WIDTH/3, HEIGHT/8);
    stockInfo4->label("Known for Search Engine");
    stockInfo4->box(FL_BORDER_BOX);
    stockInfo4->hide();
    window.add(stockInfo4);
    
    stockInfo5 = new Fl_Box(WIDTH/3, HEIGHT/8, WIDTH/3, HEIGHT/8);
    stockInfo5->label("Known for Computer Chips");
    stockInfo5->box(FL_BORDER_BOX);
    stockInfo5->hide();
    window.add(stockInfo5);
    
    stockInfo6 = new Fl_Box(2*WIDTH/3, HEIGHT/8, WIDTH/3, HEIGHT/8);
    stockInfo6->label("Known for the iPhone");
    stockInfo6->box(FL_BORDER_BOX);
    stockInfo6->hide();
    window.add(stockInfo6);

    buyB = new Fl_Button(9*WIDTH/40, 5*HEIGHT/16, WIDTH/5, HEIGHT/8);
    buyB->label("BUY");
    buyB->labelsize(24);
    buyB->callback(buyPressed_cb);
    buyB->hide();
    window.add(buyB);
    sellB = new Fl_Button(23*WIDTH/40, 5*HEIGHT/16, WIDTH/5, HEIGHT/8);
    sellB->label("SELL");
    sellB->labelsize(24);
    sellB->callback(sellPressed_cb);
    sellB->hide();
    window.add(sellB);

    historyBuffer = new Fl_Text_Buffer();
    history = new Fl_Text_Display(0, HEIGHT/2, WIDTH, HEIGHT/2);
    history->buffer(historyBuffer);
    history->hide();
    window.add(history);

    
    stockNameInput = new Fl_Choice(WIDTH/4, HEIGHT/8, WIDTH/2, HEIGHT/20, "Stock name");
    for(int i = 0; i < 3;i++) {stockNameInput->add(NAMES[i].c_str());}
    stockNameInput->hide();
    window.add(stockNameInput);
    numberSharesInput = new Fl_Input(WIDTH/4, 2*HEIGHT/8, WIDTH/2, HEIGHT/20, "Num Shares");
    numberSharesInput->hide();
    window.add(numberSharesInput);
    priceInput = new Fl_Input(WIDTH/4, 3*HEIGHT/8, WIDTH/2, HEIGHT/20, "Price");
    priceInput->hide();
    window.add(priceInput);
    
    placeOrderB = new Fl_Button(WIDTH/4, HEIGHT/2, WIDTH/4, HEIGHT/10);
    placeOrderB->label("Place Order");
    placeOrderB->callback(placeOrderPressed_cb);
    placeOrderB->hide();
    window.add(placeOrderB);

}
