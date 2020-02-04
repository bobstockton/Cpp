/* 
 * File:   TForm.h
 * Author: robert
 *
 * Created on 31 January 2020, 12:25
 */

#ifndef TFORM_H
#define TFORM_H

#define DFMLINELENGTH     500

#include <string>

#include <gtkmm.h>
#include <stdio.h>
#include <TVisibleObject.h>

class TForm : public TVisibleObject
{
public:
    TForm();
    TForm(const TForm& orig);
    virtual ~TForm();
    
    bool        LoadForm( std::string FormDefinitionFile );
   
    void        setSize( int Height, int Width );
    std::string getTitle();
    void        setTitle( std::string Title );
    Gtk::Window *getWindow();
    void        setWindow( Gtk::Window *window);
 
private:
   
    int             mHeight;
    std::string     mTitle;
    int             mWidth;
    Gtk::Window    *mWindow;
    
    std::string     getToken( FILE *ifile );
    void            createComponent( FILE *ifile );
  
};

#endif /* TOBJECT_H */

