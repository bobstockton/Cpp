/*
 * (c)R.Stockton.
 */

/* 
 * File:   TEvent.h
 * Author: robert
 *
 * Created on 10 February 2020, 09:38
 */

#ifndef TEVENT_H
#define TEVENT_H

#include <string>

using namespace std;

class TEvent {
public:
    TEvent();
    TEvent(const TEvent& orig);
    virtual ~TEvent();
private:
    
protected:
    string  functionName;
    void    (*fuctionPtr)();
};

#endif /* TEVENT_H */

