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

#include <gtk/gtk.h>

#include <string>
#include <TForm.h>

class TApplication : public TObject
{
public:
    TApplication();
    TApplication(const TApplication& orig);
    virtual ~TApplication();
    void CreateForm( std::string FormName, TForm *orm );
    void Initialise();
    void Initialize();
    void Run();
    
    std::string     Name;
    
private:
    GtkApplication *gtkApp;

};

#endif /* TAPPLICATION_H */

