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
  
}

TTextBox::TTextBox(const TTextBox& orig) {
}

TTextBox::~TTextBox() {
}

TTextBox::TTextBox( TFormDefinitionSection *section, TObject  *parent ) 
{
    string  functionName;
  
    section->getString( "name" ,    mName );
    section->getInt(    "top",      mTop);
    section->getInt(    "left",     mLeft);
    section->getInt(    "width",    mWidth );
    section->getInt(    "height",   mHeight );
    section->getInt(    "maxlen",   mMaxLength );
    section->getString( "tooltip",  mTooltip );
    section->getBool(   "visible",  mVisible );

    mParent = parent;
    mWidget  = new Gtk::Entry();
  
}
void    TTextBox::Initialise()
{
    setSize( mHeight, mWidth );
    setPosition( mLeft, mTop );
    setMaxLength( mMaxLength );
    setTooltipText( mTooltip );
}



void    TTextBox::setMaxLength( int length )
{
    Gtk::Entry *entry = (Gtk::Entry *)mWidget;
    entry->set_max_length( length );
}

string  TTextBox::getText()
{
    Gtk::Entry *entry = (Gtk::Entry *)mWidget;
    return entry->get_text();
}

void    TTextBox::setText( string text )
{
    Gtk::Entry *entry = (Gtk::Entry *)mWidget;
    entry->set_text( text.c_str());
}

void    TTextBox::setText( char *text )
{
    Gtk::Entry *entry = (Gtk::Entry *)mWidget;
    entry->set_text( text );
}


