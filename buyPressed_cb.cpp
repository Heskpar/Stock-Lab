#ifndef BUYZ
#define BUYZ
#include "lab.h"
void buyPressed_cb(Fl_Widget*)
{
    showInputScreen();
    hideMenuScreen();
    wantToBuy = true;//Press buy, want to buy becomes true
}
#endif
