/*
 * (c)R.Stockton.
 */

/* 
 * File:   TFormDefinitionSection.h
 * Author: robert
 *
 * Created on 06 February 2020, 11:34
 */

#ifndef TFORMDEFINITIONSECTION_H
#define TFORMDEFINITIONSECTION_H

using namespace std;
#include <string>

 #define MAXDEFINITIONLINES  500

class TFormDefinitionSection {
public:
   
    struct DEFINITIONLINE
    {
        string  token;
        string  value;
    };
    
    TFormDefinitionSection();
    TFormDefinitionSection(const TFormDefinitionSection& orig);
    virtual ~TFormDefinitionSection();
    
    void    add( string token, string value );
    int     getParentSection();
    void    setParentSection( int section );
    string  getSection();
    void    setSection( string section );
    bool    getValue( string token, string &value  );
    
   
    
private:
    struct DEFINITIONLINE   *mSectionLines[MAXDEFINITIONLINES];
    int                     mParentSection;
    string                  mSection;
    int                     mCount;

};

#endif /* TFORMDEFINITIONSECTION_H */

