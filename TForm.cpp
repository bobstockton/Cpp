/*
 * (c)R.Stockton.
 */

/* 
 * File:   TForm.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 12:46
 */

#include "TForm.h"

TForm::TForm() {
   // mClass = "TForm";
}

TForm::TForm(const TForm& orig) {
}

TForm::~TForm() {
}

Gtk::Window *TForm::getWindow()
{
    return mWindow;
}

void    TForm::SetSize( int Width, int Height )
{
    mWidth = Width;
    mHeight = Height;
    
    mWindow->set_default_size( Width, Height );
    
}

void    TForm::setWindow( Gtk::Window *window)
{
    mWindow = window;
}

