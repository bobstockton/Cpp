/*
 * (c)R.Stockton.
 */

/* 
 * File:   TVisibleObject.h
 * Author: robert
 *
 * Created on 04 February 2020, 09:01
 */

#ifndef TVISIBLEOBJECT_H
#define TVISIBLEOBJECT_H

#include <TPosition.h>
#include <TFont.h>
#include <TSize.h>

class TVisibleObject {
public:
    TVisibleObject();
    TVisibleObject(const TVisibleObject& orig);
    virtual ~TVisibleObject();
private:
    
        
protected: 
    TPosition   mPosition;
    TSize       mSize;
    TFont       mDefaultFont;
    bool        mVisible;
    bool        mFocus;
    int         mSequence;

};

#endif /* TVISIBLEOBJECT_H */
