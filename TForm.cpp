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
    setSize( mWidth, mHeight );
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

void    TForm::setTop( int top )
{
    mTop = top;
    setPosition();
}

void    TForm::setWidth( int width )
{
    mWidth = width;
    setSize( mWidth, mHeight );
}

void    TForm::setWindow( Gtk::Window *window)
{
    mWindow = window;
}

bool   TForm::LoadForm(  )
{
    // Open form file
    FILE *FormFile;
    std::string  formDefinitionFile;
    std::string token;
    std::string value;
    
    formDefinitionFile = mName + ".dfm";
    FormFile = fopen( formDefinitionFile.c_str(), "r" );
    if( FormFile == NULL )
    {
        return false;
    }
    
    parseFormDefinitionFile( FormFile,  )
     
    // Check for first Object for form values
    getToken( FormFile, token, value );
    if( token != "object")
    {
        return false;
    }
    getToken( FormFile, token, value );
    // Process Form Data
    while( token != "/object" )
    {
        if( token == "eof")
        {
            throw (std::string("Invalid format for form definition file : ") + formDefinitionFile ); 
        }
        if( token == "title" )
        {
            setTitle(value);
        }
        else if( token == "top" )
        {
            setTop(std::stoi(value));
        }
        else if( token == "left" )
        {
            setLeft( std::stoi(value ));
       }
        else if( token == "height")
        {
            setHeight( std::stoi(value ));
        }
        else if( token == "width" )
        {
            setWidth(std::stoi(value));
        }
        else if( token == "type" )
        { 
        }
        else if( token == "mainform" )
        { 
            mMainForm = ( value == "true" );
        }
        else if( token == "visible" )
        {
            mVisible = ( value == "true" );
        }
        else if( token == "object" )
        {
            // Create new Component on the form
            createComponent( FormFile );
        }
        getToken( FormFile, token, value );   
            
    }
}

void    TForm::createComponent( FILE *ifile )
{
    pair<string, string> tokenArray[100];
    string  token;
    string  value;
    string  objclass;
    int i = 0;
    
    // Build up a list of component values for one object
    token = "";
    while( token != "/object") 
    {
        if( !getToken( ifile , token, value )) throw ("EOF Reached");
        if( token == "eof" )
        {
            throw("EOF Reached" );
        }
        tokenArray[i++] = { token, value };
    } 
}

bool TForm::getToken( FILE *ifile , string &token, string &value )
{
    char line[DFMLINELENGTH];
    string str;
    
    if( fgets( line, DFMLINELENGTH , ifile ))
    {
        splitLine( line, token, value );
        return true;
    }
    token = "eof";
    value = "";
    return false;
}

void TForm::splitLine( char *line, string &token, string &value )
{
    char *start;
    char *end;

    char    tmp[200];
    
    value = "";
   
    start = strchr( line, '<' );
    end = strchr(line, '>' );
    strncpy( tmp, start+1, end-start);
    tmp[end-start-1] = '\0';
    token = tmp;
    try
    {
         start = strchr( end+1,'<' );
         if( start > 0 )
         {
            strncpy( tmp, end+1, start-end-1);
            tmp[start-end-1] = '\0';
    
            value = tmp;
         }
       
    }
    catch(...)
    {
    }           
  
}

