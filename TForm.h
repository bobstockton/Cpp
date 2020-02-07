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
#include <TFormDefinition.h>
#include <TButton.h>

#define MAXCOMPONENTS 500

class TForm : public TVisibleObject
{
public:
    TForm();
    TForm(const TForm& orig);
    virtual ~TForm();
    
    bool        isMainForm();
    bool        LoadForm(  );
    void        setHeight( int height );
    void        setLeft( int left );
    void        setSize(  );
    std::string getTitle();
    void        setTitle( std::string Title );
    void        setTop( int top );
    void        setWidth( int width );
    Gtk::Window *getWindow();
    void        setWindow( Gtk::Window *window);
    void        setPosition();
 
private:
    std::string     mTitle;
  
    bool            mMainForm;
    TFormDefinition *mFormDefinition;

    void            addComponent( TVisibleObject *component );
    bool            getToken( FILE *ifile , std::string &token, std::string &value);
    void            createComponent( int section );
    void            splitLine( char *line, std::string &token, std::string &value );
    
protected:
    Gtk::Window    *mWindow;
    
    TVisibleObject  *mComponentArray[MAXCOMPONENTS];
            
    int             mComponentCount;
            
  
};

#endif /* TOBJECT_H */

