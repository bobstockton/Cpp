/*
 * (c)R.Stockton.
 */

/* 
 * File:   TTextBox.cpp
 * Author: robert
 * 
 * Created on 12 February 2020, 08:42
 */

#include "TTextBox.h"

TTextBox::TTextBox() {
    mHeight = mWidth = mLeft = mTop = mMaxLength = 10;
    mVisible = true;
}

TTextBox::TTextBox(const TTextBox& orig) {
}

TTextBox::~TTextBox() {
}

TTextBox::TTextBox( TFormDefinitionSection *section, TObject  *parent ) 
{
    string  functionName;
    
    mHeight = mWidth = mLeft = mTop = mMaxLength = 10;
    mVisible = true;
  
    section->getString( "name" ,    mName );
    section->getInt(    "top",      mTop);
    section->getInt(    "left",     mLeft);
    section->getInt(    "width",    mWidth );
    section->getInt(    "height",   mHeight );
    section->getInt(    "maxlen",   mMaxLength );
    section->getBool(   "visible",  mVisible );

    mParent = parent;
    mGtkEntry  = new Gtk::Entry();
  
}
void    TTextBox::Initialise()
{
    setSize( mHeight, mWidth );
    setPosition( mLeft, mTop );
    setMaxLength( mMaxLength );
}


Gtk::Widget   *TTextBox::getGtkWidget()
{
    return mGtkEntry;
}


void    TTextBox::setMaxLength( int length )
{
    mGtkEntry->set_max_length( length );
}


void    TTextBox::setPosition( int X, int Y )
{
    Gtk::Fixed  *container;
    
    container = dynamic_cast<Gtk::Fixed *>(mParent->getGtkWidget()); 
    container->move( *mGtkEntry, X, Y );
}

void    TTextBox::setSize( int height, int width )
{
    mWidth = width;
    mHeight = height;
    mGtkEntry->set_size_request( width, height );
}


string  TTextBox::getText()
{
    return mGtkEntry->get_text();
}

void    TTextBox::setText( string text )
{
    mGtkEntry->set_text( text.c_str());
}
