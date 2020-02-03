

/* 
 * File:   TObject.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 12:25
 */

#include "TObject.h"

TObject::TObject() {
}

TObject::TObject(const TObject& orig) {
}

TObject::~TObject() {
}

TObject *TObject::Create()
{
    
}

std::string TObject::getName()
{
    return mName;
}

void TObject::setName(std::string Name )
{
    mName = Name;
}
