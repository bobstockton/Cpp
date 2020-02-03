/*
 * (c)R.Stockton.
 */

/* 
 * File:   TApplication.h
 * Author: robert
 *
 * Created on 31 January 2020, 12:59
 */

#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <gtkmm.h>

#include <string>
#include <TForm.h>

class TApplication 
{
public:
    TApplication();
    TApplication(const TApplication& orig);
    virtual ~TApplication();
    void CreateForm( std::string FormName, TForm *Form );
    void Initialise( int argc, char *argv[]);
    void Initialize( int argc, char *argv[]);
    void Run( int argc, char *argv[]);
    
    std::string     Name;
    
private:
 Glib::RefPtr<Gtk::Application> mGtkApp;
 TForm  *mMainForm;

};

#endif /* TAPPLICATION_H */

