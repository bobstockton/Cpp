/*
 * (c)R.Stockton.
 */

/* 
 * File:   Form1.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 13:30
 */

#include "Form1.h"

Form1::Form1() {
}

Form1::Form1(const Form1& orig) {
}

Form1::~Form1() {
}

void    Form1::addComponents( )
{
    // Components here must match dfm
    cmdButton1 = new TButton( mWindow, 10,10,20,10, "Cancel" );
    
}


