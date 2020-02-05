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
    gtkButton = new Gtk::Button(caption.c_str(), true);
    gtkButton->set_size_request( width, height );
  
}

TButton::TButton(const TButton& orig) {
}

TButton::~TButton() {
}

