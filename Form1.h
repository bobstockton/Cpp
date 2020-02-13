/*
 * (c)R.Stockton.
 */

/* 
 * File:   Form1.h
 * Author: robert
 *
 * Created on 31 January 2020, 13:30
 */

#ifndef FORM1_H
#define FORM1_H

#include <TForm.h>
#include <TButton.h>

class Form1 : public TForm {
public:
    Form1();
    Form1(const Form1& orig);
    virtual ~Form1();
    
    void    addComponents( ) ;
    void    Initialise() override;
    
    
    TButton     *cmdCancel;
    TButton     *cmdTestButton;
    TTextBox    *txtBox;
private:
    

    
protected:
    void cmdCancel_OnClick();
    void cmdTestButton_OnClick();

};

#endif /* FORM1_H */

