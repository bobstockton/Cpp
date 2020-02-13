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

Form1::~Form1() 
{
}

void    Form1::Initialise()
{
    TForm::Initialise();
    cmdCancel = dynamic_cast<TButton *>(getComponent("cmdCancel"));
    cmdCancel->getGtkButton()->signal_clicked().connect(sigc::mem_fun(this, &Form1::cmdCancel_OnClick));
    
    cmdTestButton = dynamic_cast<TButton *>(getComponent("cmdTestButton"));
    cmdTestButton->getGtkButton()->signal_clicked().connect(sigc::mem_fun(this, &Form1::cmdTestButton_OnClick));
    
    txtBox = dynamic_cast<TTextBox *>(getComponent("txtBox"));
    
}

void    Form1::cmdCancel_OnClick()
{
    string  boxText;
    
    boxText = txtBox->getText();
    Close();
}

void    Form1::cmdTestButton_OnClick()
{
    bool    visible;
    
    visible = cmdCancel->getVisible();
    cmdCancel->setVisible( !visible );
}





