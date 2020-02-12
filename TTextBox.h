/*
 * (c)R.Stockton.
 */

/* 
 * File:   TTextBox.h
 * Author: robert
 *
 * Created on 12 February 2020, 08:42
 */

#ifndef TTEXTBOX_H
#define TTEXTBOX_H

#include <TVisibleObject.h>

class TTextBox: public TVisibleObject {
public:
    TTextBox();
    TTextBox(const TTextBox& orig);
    TTextBox( TFormDefinitionSection *section, TObject  *parent ) ;
    virtual ~TTextBox();
    virtual void rtti_function(){};
    
    void        Initialise();
    
    Gtk::Widget *getGtkWidget( ) override;
    
    void        setMaxLength( int length );
    void        setPosition( int X, int Y );
    void        setSize( int Hight, int Width );
    void        setText( string Text );
    string      getText();
    
private:
    Gtk::Entry    *mGtkEntry;
    int             mMaxLength;

};

#endif /* TTEXTBOX_H */

