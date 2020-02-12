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
    mGtkButton  = new Gtk::Button(caption.c_str(), true);
    
  
}

TButton::TButton(const TButton& orig) {
}

TButton::TButton( TFormDefinitionSection *section, TObject  *parent ) 
{
    string  functionName;
  
    section->getString( "name" ,    mName );
    section->getInt(    "top",      mTop);
    section->getInt(    "left",     mLeft);
    section->getInt(    "width",    mWidth );
    section->getInt(    "height",   mHeight );
    section->getBool(   "visible",  mVisible );
    section->getString( "caption",  mCaption );
    mParent = parent;
    mGtkButton  = new Gtk::Button(mCaption.c_str(), true);
    mGtkButton->set_size_request( mWidth, mHeight );
    
    // Attach Event Listeners
//    if( section->getString( "onclick", functionName ))
//    {
//        gtkButton->signal_clicked().connect(std::mem_fun(this, &TButton::OnClick));
//    }
}

TButton::~TButton() {
}

void    TButton::Initialise()
{
    setPosition( mLeft, mTop );
    setSize( mHeight, mWidth );
}

Gtk::Button *TButton::getGtkButton()
{
    return mGtkButton;
}


void    TButton::setCaption( string caption )
{
    mCaption = caption;
    mGtkButton->set_label( mCaption.c_str());

}

void    TButton::setPosition( int X, int Y )
{
    Gtk::Fixed  *container;
    
    container = dynamic_cast<Gtk::Fixed *>(mParent->getGtkWidget()); 
    container->move( *mGtkButton, X, Y);
}

void TButton::setSize( int width, int height )
{
    mGtkButton->set_size_request(width, height);
}


