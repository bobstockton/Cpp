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
    Form = new TForm();
    Form->setWindow( new Gtk::Window );
    Form->Title = "Demo Form Title";
    Form->SetSize( 100, 100 );
    mMainForm = Form;
 
}

void TApplication::Initialise( int argc, char *argv[] )
{
   auto gtkApp = Gtk::Application::create( argc, argv, "local.example.bcl");
   mGtkApp = gtkApp;
   
}
     
 
 void TApplication::Initialize( int argc, char *argv[] )
 {
     Initialise(argc, argv );
 }
 void TApplication::Run( int argc, char *argv[])
 {
    mGtkApp->run(*mMainForm->getWindow());
 }

