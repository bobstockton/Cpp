/*
 * (c)R.Stockton.
 */

/* 
 * File:   TApplication.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 12:59
 */

#include "TApplication.h"

TApplication::TApplication() {
}

TApplication::TApplication(const TApplication& orig) {
}

TApplication::~TApplication() {
}

void TApplication::CreateForm( std::string FormName, TForm *Form )
{
    // Read definition of this form form the definition file & create the components
    Form->Title = "Demo Form Title";
    Form->Height = 400;
    Form->Width  = 800;
    
    Form->Window = gtk_application_windows_new( GTK_ORIENTATION_HORIZONTAL );
    
  
}

void TApplication::Initialise()
{
    gtkApp = gtk_application_new( Name.c_str(), G_APPLICATION_FLAGS_NONE ); 
    
}
     
 
 void TApplication::Initialize()
 {
     return Initialise();
 }
 void TApplication::Run()
 {
     
 }

