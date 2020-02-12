/*
 * (c)R.Stockton.
 */

/* 
 * File:   TForm.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 12:46
 */

#include "TForm.h"
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace std;

TForm::TForm() {
    mClass      = "TForm";
    mHeight     = 10;
    mWidth      = 10;
    mTop        = 10;
    mLeft       = 10;
    mMainForm   = false;
    mFormDefinition = new TFormDefinition();
    mComponentCount = 0;
    
}

TForm::TForm(const TForm& orig) {
}

TForm::~TForm() {
}

Gtk::Window *TForm::getWindow()
{
    return mWindow;
}

bool TForm::isMainForm()
{
    return mMainForm;
}

void TForm::setHeight( int height )
{
    mHeight = height;
    setSize(  );
}

void    TForm::setLeft( int left )
{
    mLeft = left;
    setPosition( ) ;
}

void    TForm::setPosition()
{
    mWindow->move( mLeft, mTop );
}

void    TForm::setSize(  )
{
    mWindow->set_default_size( mWidth, mHeight );   
}

std::string TForm::getTitle()
{
    return mTitle;
}

void    TForm::setTitle( std::string Title )
{
    mTitle = Title;
    mWindow->set_title( mTitle.c_str());
}

void    TForm::setTop( int top )
{
    mTop = top;
    setPosition();
}

void    TForm::setWidth( int width )
{
    mWidth = width;
    setSize(  );
}

void    TForm::setWindow( Gtk::Window *window)
{
    mWindow = window;
}

bool   TForm::LoadForm(  )
{
    try
    {
        mWindow = new Gtk::Window;
        mFixed  = new Gtk::Fixed;
        mWindow->add(*mFixed);
        mFormDefinition->Load( mName );
        // Get form section values
        for( int i = 0 ; i< mFormDefinition->getSectionCount() ; i++ ) 
        {
                // new component
                createComponent( i );           
        }
        
        setPosition();
        setSize();  
        mWindow->show_all_children();
    }
    catch( string e )
    {
        
    }
    
}  
    

void    TForm::createComponent( int section)
{
    string  value;
    string   name;
    
    TFormDefinitionSection   *sectionDef;
    TVisibleObject           *component;
    
  
    
    
    if( !mFormDefinition->getValue(section, "class", value ))
    {
        throw ("Missing Class for COmponent" );
    }
    if( !mFormDefinition->getValue(section, "name", name ))
    {
        throw ("Missing Name for Component" );
    }

    sectionDef = mFormDefinition->getSection(section);
    
    if( value == "TForm" )
    {
        sectionDef->getInt(     "top",      mTop );
        sectionDef->getInt(     "left",     mLeft);
        sectionDef->getInt(     "height",   mHeight);
        sectionDef->getInt(     "width",    mWidth);
        sectionDef->getString(  "title",    mTitle);
        sectionDef->getBool(    "visible",  mVisible);
        sectionDef->getBool(    "mainform", mMainForm);
        sectionDef->getString(  "class",    mClass);
        return;
    }
    if( value == "TButton" )
    {
        TButton *button= new TButton( sectionDef, this );   
        gtk_container_add(GTK_CONTAINER(mFixed->gobj()),  GTK_WIDGET(button->getGtkButton()->gobj()) );
        addComponent( button );
        button->Initialise();
        
    }
    if( value == "TTextBox" )
    {
        TTextBox *textbox = new TTextBox( sectionDef, this );
        gtk_container_add(GTK_CONTAINER(mFixed->gobj()),  GTK_WIDGET(textbox->getGtkWidget()->gobj()) );
        addComponent( textbox );
        textbox->Initialise();
    }
}

void TForm::addComponent( TVisibleObject *component )
{
    mComponentArray[mComponentCount++] = component;
}

TVisibleObject *TForm::getComponent( string name )
{
    for( int i= 0 ; i< mComponentCount ; i++ )
    {
        if( mComponentArray[i]->getName() == name  )
        {
            return mComponentArray[i];
        }
    }
    return NULL;
}

Gtk::Widget  *TForm::getGtkWidget()
{
    return mFixed;
}


void    TForm::Initialise()
{
   
     
}


//{
//    TEvent  = new TEvent();
//    
//    TEvent->setFunctionName( functionName );
//    TEvent->setFunctionPointer( functionPtr );
//    
//    mEventArray[mEventCount++] = TEvent;
//    
//}
//


