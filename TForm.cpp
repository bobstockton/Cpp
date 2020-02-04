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

TForm::TForm() {
   // mClass = "TForm";
}

TForm::TForm(const TForm& orig) {
}

TForm::~TForm() {
}

Gtk::Window *TForm::getWindow()
{
    return mWindow;
}

void    TForm::setSize( int Width, int Height )
{
    mWidth = Width;
    mHeight = Height;
    
    mWindow->set_default_size( Width, Height );   
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

void    TForm::setWindow( Gtk::Window *window)
{
    mWindow = window;
}

bool   TForm::LoadForm( std::string FormDefinitionFile )
{
    // Open form file
    FILE *FormFile;
    std::string token;
    
    FormFile = fopen( FormDefinitionFile.c_str(), "r" );
    if( FormFile == NULL )
    {
        return false;
    }
   
    
    // Check for first Object for form
    token = getToken( FormFile );
    if( token != "<Object>")
    {
        return false;
    }
    token = getToken( FormFile);
    // Process Form Data
    while( token != "</Object>" )
    {
        if( token == "<Object>" )
        {
            // Create new Component on the form
            createComponent( FormFile );
        }
        token = getToken( FormFile );
        if( token == "<EOF>")
        {
            throw (std::string("Invalid format for form definition file : ") + FormDefinitionFile ); 
        }
    }
}

void    TForm::createComponent( FILE *ifile )
{
    std::array<std::string, 100 > valueArray;
    std::string  token;
    int i = 0;
    
    // Build up a list of component values for one object
    token = "";
    while( token != "</Object>") 
    {
        token = getToken( ifile );
        if( token == "<EOF>" )
        {
            throw("Error" );
        }
        
        valueArray[i++] = token;
    }
}

std::string TForm::getToken( FILE *ifile )
{
    char line[DFMLINELENGTH];
    std::string str;
    
    if( fgets( line, DFMLINELENGTH , ifile ))
    {
        str = line;
        trim(str);
        return str;
    }
    return "<EOF>";
}
