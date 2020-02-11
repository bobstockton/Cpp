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
    mFormCount = 0;
}

TApplication::TApplication(const TApplication& orig) {
}

TApplication::~TApplication() {
    // Destroy all forms
    for( int i = 0 ; i < mFormCount; i++ ) 
    {
        delete mForms[i];
    }
    delete &mGtkApp;
}

void TApplication::CreateForm( std::string FormName, TForm *Form )
{
    // Read definition of this form form the definition file & create the components
 
   
    Form->setName( FormName );
    Form->LoadForm();
    Form->Initialise();
    if( Form->isMainForm())
    {
        mMainForm = Form;
    }
   
    mForms[mFormCount++] = Form;

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
    if( mMainForm == NULL ) throw ("No Main Form Defined");
    mGtkApp->run(*mMainForm->getWindow());
 }

