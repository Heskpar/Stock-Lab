#include "lab.h"
void placeOrderPressed_cb(Fl_Widget*)
{

    Order   peek, trash;

    int qtraded = 0, ptraded = 0, tradesucc = 1;

    string symb;

    string numberSharesstring = numberSharesInput->value();
    string priceInputstring = priceInput->value();
    
   
    int numberShares = 0; numberShares = stoi(numberSharesstring);
    int priceIn = 0; priceIn = stoi(priceInputstring);

    if(stockNameInput->value() == 0)
    { 
        symb = "GOOG";
        if(wantToBuy)
        {
            if (!GOOGse.peekSeller(peek)) return ;
            if(peek.getPrice() < (priceIn+1))
            {   if((peek.getShare() - numberShares) >= 0 )
                { 
                qtraded = numberShares;                
                peek.setShare(peek.getShare() - qtraded);            
                GOOGse.removeSeller(trash);
                GOOGse.insertSeller(peek);
                }
                else
                {
                qtraded = peek.getShare();
                GOOGse.removeSeller(trash);
                }
                ptraded = peek.getPrice();
            }
            else
            {
                tradesucc*=-1;
            }
        }
        else 
        {   if (!GOOGse.peekBuyer(peek)) return ;
            if(peek.getPrice()+1 > priceIn)
            {   if((peek.getShare() - numberShares) >=0 )
                {  qtraded = numberShares;
                   peek.setShare(peek.getShare() - qtraded);
                   GOOGse.removeBuyer(trash);
                   GOOGse.insertBuyer(peek);
                }
                else
                {  qtraded = peek.getShare();
                   GOOGse.removeBuyer(trash);
                }
                ptraded = priceIn;       
            }
            else
            {
                tradesucc*=-1;
            }
        }
    }
    else if(stockNameInput->value() == 1)
    {
        symb = "INTL";
        if(wantToBuy)
        {   if (!INTLse.peekSeller(peek)) return ;
            if(peek.getPrice() < (priceIn+1))
            {
                if((peek.getShare() - numberShares) >=0 )
                {   qtraded = numberShares;
                    peek.setShare(peek.getShare() - qtraded);
                    INTLse.removeSeller(trash);
                    INTLse.insertSeller(peek);
                }
                else
                {   qtraded = peek.getShare();
                    INTLse.removeSeller(trash);
                }
                ptraded = peek.getPrice();
            }
            else tradesucc*=-1;
        }
        else
        {
            if (!INTLse.peekBuyer(peek))
            {return ;}
            if(peek.getPrice() > (priceIn-1))
            {
                if((peek.getShare() - numberShares) >=0 )
                {   qtraded = numberShares;
                    peek.setShare(peek.getShare() - qtraded);
                    INTLse.removeBuyer(trash);
                    INTLse.insertBuyer(peek);
                }
                else
                {
                    qtraded = peek.getShare();
                    INTLse.removeBuyer(trash);
                }
            ptraded = priceIn; 
            }
            else
            { tradesucc*=-1;}
        }
    }
    else
    {
        symb = "AAPL";
        if(wantToBuy)
        {
            if (!AAPLse.peekSeller(peek))
            {return ;}
            if(peek.getPrice() < (priceIn+1))
            {
                if((peek.getShare() - numberShares) >=0 )
                {
                    qtraded = numberShares;
                    peek.setShare(peek.getShare() - qtraded);
                    AAPLse.removeSeller(trash);
                    AAPLse.insertSeller(peek);
                }
                else
                {
                    qtraded = peek.getShare();
                    AAPLse.removeSeller(trash);
                }
                ptraded = peek.getPrice();
            }
            else
            {tradesucc*=-1;}
        }
        else 
        {
            if (!AAPLse.peekBuyer(peek))
            {return ;}
            if(peek.getPrice()+1 > priceIn)
            {
                if((peek.getShare() - numberShares) >=0 )
                { 
                    qtraded = numberShares;
                    peek.setShare(peek.getShare() - qtraded);
                    AAPLse.removeBuyer(trash);
                    AAPLse.insertBuyer(peek);
                }
                else
                { 
                    qtraded = peek.getShare();
                    AAPLse.removeBuyer(trash);
                }
                ptraded = priceIn;
      
            }
            else
            { tradesucc*=-1; }
        }
    }


    if(tradesucc == 1)
    {
        if(wantToBuy)
            logsV.push_back(Log("",symb,BUY,qtraded,ptraded));
        else
            logsV.push_back(Log("",symb,SELL,qtraded,ptraded));

        hist = "Transaction Log\n";
        for(int x = (logsV.size()-1); x > -1;x--) 
        {hist = hist + to_string(logsV[x].getShare()) +" shares of " + logsV[x].getSymbol() + " stock has been sold for $"+to_string(logsV[x].getPrice())  +"\n";}
    }
    hideInputScreen();
    showMenuScreen();
}
