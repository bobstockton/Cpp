/*
 * (c)R.Stockton.
 */

/* 
 * File:   TFormDefinitionSection.cpp
 * Author: robert
 * 
 * Created on 06 February 2020, 11:34
 */

#include "TFormDefinitionSection.h"

TFormDefinitionSection::TFormDefinitionSection() {
     mCount = 0;
}

TFormDefinitionSection::TFormDefinitionSection(const TFormDefinitionSection& orig) {
}

TFormDefinitionSection::~TFormDefinitionSection() {
  
    for( int i = 0 ; i< mCount; i++ )
    {
        delete mSectionLines[i];
    }
}

void    TFormDefinitionSection::add( string token, string value )
{
    mSectionLines[mCount] = new struct DEFINITIONLINE;
    mSectionLines[mCount]->token = token;
    mSectionLines[mCount]->value = value;
    
    mCount++;
    
}

int TFormDefinitionSection::getParentSection()
{
    return mParentSection;
}

void    TFormDefinitionSection::setParentSection( int section )
{
    mParentSection = section;
}

string TFormDefinitionSection::getSection()
{
    return mSection;
}

void    TFormDefinitionSection::setSection( string section )
{
    mSection = section;
}


bool  TFormDefinitionSection::getValue( string token , string &value )
{
    for( int i=0 ; i < mCount ; i++ )
    {
        if( mSectionLines[i]->token == token )
        {
            value =  mSectionLines[i]->value;
            return true;
        }
    }
    value = "";
    return false;
}

bool    TFormDefinitionSection::getString( string token, string &value )
{
    bool ret;
    
    ret = getValue( token, value );
    
    return ret;
}

bool    TFormDefinitionSection::getInt( string token, int &value )
{
    bool ret;
    string  stringValue;
    
    ret = getValue( token, stringValue);
    value = stoi( stringValue );
    
}
bool    TFormDefinitionSection::getBool( string token, bool &value )
{
    bool ret;
    string  stringValue;
    
    ret = getValue( token, stringValue );
    value = ( stringValue == "true" );
    
    return ret;
}
    

