/*
 * (c)R.Stockton.
 */

/* 
 * File:   TButton.cpp
 * Author: robert
 * 
 * Created on 05 February 2020, 09:14
 */

using namespace std;


#include "TButton.h"

TButton::TButton(Gtk::Window *window, int left, int top, int width , int height, string caption) 
{
    mWidget  = new Gtk::Button(caption.c_str(), true);
}

TButton::TButton(const TButton& orig) {
}

TButton::TButton( TFormDefinitionSection *section, TObject  *parent ) 
{
    string  functionName;
    
    
    mVisible = true;
    mCaption = "NotSet";
  
    section->getString( "name" ,    mName );
    section->getInt(    "top",      mTop);
    section->getInt(    "left",     mLeft);
    section->getInt(    "width",    mWidth );
    section->getInt(    "height",   mHeight );
    section->getString( "tooltip",  mTooltip );
    section->getBool(   "visible",  mVisible );
    section->getString( "caption",  mCaption );
    mParent = parent;
    mWidget  = new Gtk::Button(mCaption.c_str(), true);
    mWidget->set_size_request( mWidth, mHeight );
  
}

TButton::~TButton() {
}

void    TButton::Initialise()
{
    setPosition( mLeft, mTop );
    setSize( mWidth, mHeight );
    setTooltipText( mTooltip );
}

Gtk::Button *TButton::getGtkButton()
{
    return (Gtk::Button *)mWidget;
}


void    TButton::setCaption( string caption )
{
    Gtk::Button *button = (Gtk::Button *)mWidget;
    mCaption = caption;
    button->set_label( mCaption.c_str());

}





