#include "lab.h"
void showMenuScreen()
{
    stockInfo1->show();
    stockInfo2->show();
    stockInfo3->show();
    stockInfo4->show();
    stockInfo5->show();
    stockInfo6->show();
    sellB->show();
    buyB->show();
    
    //Here, the updated history string will be put into menu's history display
    historyBuffer->text(hist.c_str());
    history->buffer(historyBuffer);
    history->show();
}
