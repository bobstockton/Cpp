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
    
    mWindow = new Gtk::Window;
    mFormDefinition = new TFormDefinition();
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
    string  value;
    try
    {
        mFormDefinition->Load( mName );
        // Get form section values
        for( int i = 0 ; i< mFormDefinition->getSectionCount() ; i++ ) 
        {
            mFormDefinition->getValue( i, "name", value );
            if( value == mName )
            {
                // Section is for this form
                if( mFormDefinition->getValue(i, "top", value ))    mTop        = stoi( value );
                if( mFormDefinition->getValue(i, "left", value))    mLeft       = stoi( value ); 
                if( mFormDefinition->getValue(i, "height", value))  mHeight     = stoi( value );
                if( mFormDefinition->getValue(i, "width", value))   mWidth      = stoi( value );
                if( mFormDefinition->getValue(i, "title", value))   mTitle      = value;
                if( mFormDefinition->getValue(i, "visible", value)) mVisible    = (value == "true");
                if( mFormDefinition->getValue(i, "mainform", value))mMainForm   = (value == "true" );
                if( mFormDefinition->getValue(i, "class", value))   mClass      = value;
                
            }
            else
            {
                // new component
            }
            
        }
        
        
    }
    catch( string e )
    {
        
    }
    
}  
    

void    TForm::createComponent( FILE *ifile )
{
    
}



