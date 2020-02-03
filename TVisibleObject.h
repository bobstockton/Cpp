/*
 * (c)R.Stockton.
 */

/* 
 * File:   TVisibleObject.h
 * Author: robert
 *
 * Created on 03 February 2020, 17:12
 */

#ifndef TVISIBLEOBJECT_H
#define TVISIBLEOBJECT_H

#include <string>
#include <TObject.h>
#include <TPosition.h>
#include <TSize.h>
#include <TFont.h>

class TVisibleObject : public TObject
{
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

