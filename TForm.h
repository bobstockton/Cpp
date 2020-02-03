/* 
 * File:   TForm.h
 * Author: robert
 *
 * Created on 31 January 2020, 12:25
 */

#ifndef TFORM_H
#define TFORM_H

#include <string>

#include <gtkmm.h>

#include <TVisibleObject.h>

class TForm : public TVisibleObject
{
public:
    TForm();
    TForm(const TForm& orig);
    virtual ~TForm();
    Gtk::Window *getWindow();
    void    setWindow( Gtk::Window *window);

    void    SetSize( int Height, int Width );
  
    std::string Title;
   
 
private:
   
    int             mHeight;
    int             mWidth;
    Gtk::Window    *mWindow;
  
};

#endif /* TOBJECT_H */

