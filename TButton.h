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

#include <TVisibleObject.h>
#include <gtkmm/button.h>

class TButton : public TVisibleObject {
public:
    TButton(Gtk::Window *window, int left, int top, int width , int height, string caption);
    TButton(const TButton& orig);
    virtual ~TButton();
private:
    Gtk::Button *gtkButton;
    

};

#endif /* TBUTTON_H */

