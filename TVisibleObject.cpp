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
    mTop = mLeft = mWidth = mHeight = 10;
    mTooltip = "";
    mVisible = true;
}

TVisibleObject::TVisibleObject(const TVisibleObject& orig) {
}

TVisibleObject::~TVisibleObject() {
}

Gtk::Widget *TVisibleObject::getWidget()
{
    return mWidget;
}


void    TVisibleObject::setTooltipText( string text )
{
    if( text == "" )
    {
        mWidget->set_has_tooltip(false); 
    }
    else
    {
        mWidget->set_has_tooltip(true);
        mWidget->set_tooltip_text( text.c_str() );
    }
   
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

void    TVisibleObject::setPosition( int X, int Y )
{
    Gtk::Fixed  *container = dynamic_cast<Gtk::Fixed *>(mParent->getGtkWidget()); ;
  
    container->move( *mWidget, X, Y);
}

void TVisibleObject::setSize( int width, int height )
{
    mWidget->set_size_request(width, height);
}


