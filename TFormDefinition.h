/*
 * (c)R.Stockton.
 */

/* 
 * File:   TFormDefinition.h
 * Author: robert
 *
 * Created on 06 February 2020, 09:00
 */

#ifndef TFORMDEFINITION_H
#define TFORMDEFINITION_H

using namespace std;


#include <stdio.h>
#include <string.h>
#include <boost/algorithm/string.hpp>
#include <TFormDefinitionSection.h>

#define MAXSECTIONS         500
#define DFMLINELENGTH       1024


class TFormDefinition {
public:
    
    TFormDefinition();
    TFormDefinition(const TFormDefinition& orig);
    virtual ~TFormDefinition();
    
    TFormDefinitionSection *getSection( int i ); 
    int                     getSectionCount();
    bool                    getValue(int section, string token, string &value );
    bool                    Load( string formName );
private:
        
    bool                    getToken( FILE *ifile , string &token, string &value );
    void                    splitLine( char *line, string &token, string &value );
    
    TFormDefinitionSection  *mSections[MAXSECTIONS];
    int                     mSectionCount;
    

};

#endif /* TFORMDEFINITION_H */

