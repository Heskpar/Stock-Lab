#include "lab.h"
void sellPressed_cb(Fl_Widget*)
{
    showInputScreen();
    hideMenuScreen();
    wantToBuy = false;//Want to buy is false when user is a seller
}
