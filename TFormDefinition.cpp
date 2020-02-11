/*
 * (c)R.Stockton.
 */

/* 
 * File:   TFormDefinition.cpp
 * Author: robert
 * 
 * Created on 06 February 2020, 09:00
 */

#include "TFormDefinition.h"

TFormDefinition::TFormDefinition() 
{
    mSectionCount = 0;
}

TFormDefinition::TFormDefinition(const TFormDefinition& orig) {
}

TFormDefinition::~TFormDefinition() 
{
    for( int i = 0 ; i < mSectionCount; i++ )
    {
        delete mSections[i];
    }
    
}

bool  TFormDefinition::getValue( int section, string token , string &value )
{  
    if( section < mSectionCount )
    {
        return(mSections[section]->getValue( token, value ) );   
    }  
}

bool    TFormDefinition::Load( string formName )
{
    // Open form file
    FILE    *FormFile;
    string  formDefinitionFile;
    string  token;
    string  value;
    string  section;
   
    int     currentSection = 0;
    int     parentSection = 0;
       
    formDefinitionFile = formName + ".dfm";
    FormFile = fopen( formDefinitionFile.c_str(), "r" );
    if( FormFile == NULL )
    {
        return false;
    }
    
    mSectionCount = 0;
 
    while(!feof(FormFile) )
    {
        getToken( FormFile, token, value );
        if( token == "object" )
        {   
            // Add empty section ready for values  
            parentSection = currentSection;
            currentSection = mSectionCount++;
            mSections[currentSection] = new TFormDefinitionSection();
            mSections[currentSection]->setParentSection(parentSection);
            continue;
        }
        if( token == "/object" )
        {
            currentSection = mSections[currentSection]->getParentSection();
            continue;
        }
        
        mSections[currentSection]->add( token, value );
        
    }
    
} 
            
TFormDefinitionSection *TFormDefinition::getSection( int i )
{
    if( i < mSectionCount)
    {
        return mSections[i];
    }
    throw( "Missing Form Definition Section" );
    
}

 
int TFormDefinition::getSectionCount()
{
    return mSectionCount;
}
    
bool TFormDefinition::getToken( FILE *ifile , string &token, string &value )
{
    char line[DFMLINELENGTH];
    string str;
    
    if( fgets( line, DFMLINELENGTH , ifile ))
    {
        splitLine( line, token, value );
        token = boost::algorithm::to_lower_copy( token );
        return true;
    }
    token = "eof";
    value = "";
    return false;
}

void TFormDefinition::splitLine( char *line, string &token, string &value )
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



