/*
 * (c)R.Stockton.
 */

/* 
 * File:   TVisibleObject.cpp
 * Author: robert
 * 
 * Created on 04 February 2020, 09:01
 */

#include "TVisibleObject.h"

TVisibleObject::TVisibleObject() {
}

TVisibleObject::TVisibleObject(const TVisibleObject& orig) {
}

TVisibleObject::~TVisibleObject() {
}

Gtk::Widget *TVisibleObject::getWidget()
{
    return mWidget;
}

bool TVisibleObject::getVisible()
{
    return mVisible;
   
}

void TVisibleObject::setVisible( bool visible )
{
    mVisible = visible;
    if( mVisible )
    {
        mWidget->show();
    }
    else
    {
        mWidget->hide();
    }
    
}


