/*
 * (c)R.Stockton.
 */

/* 
 * File:   TButton.h
 * Author: robert
 *
 * Created on 05 February 2020, 09:14
 */

#ifndef TBUTTON_H
#define TBUTTON_H

using namespace std;

#include <TObject.h>
#include <TVisibleObject.h>
#include <TFormDefinitionSection.h>
#include <gtkmm/button.h>

class TButton : public TVisibleObject {
public:
    TButton(Gtk::Window *window, int left, int top, int width , int height, string caption);
    TButton(const TButton& orig);
    TButton( TFormDefinitionSection *section, TObject  *parent ) ;
    virtual         ~TButton();
    
    void            Initialise(); 
    void            OnClick();
    
    void            setCaption( string );
    void            setPosition(int X, int Y );
    void            setSize( int Width, int Height );
    virtual void    rtti_function(){};
    
    
    Gtk::Button *getGtkButton();
       
   
private:
    Gtk::Button *mGtkButton;
    
    string  mCaption;
};

#endif /* TBUTTON_H */

