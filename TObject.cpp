

/* 
 * File:   TObject.cpp
 * Author: robert
 * 
 * Created on 31 January 2020, 12:25
 */

#include "TObject.h"

TObject::TObject() {
    mName = mClass = "NotSet";
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

Gtk::Widget *TObject::getGtkWidget()
{
    return NULL;
}

void TObject::setName(std::string Name )
{
    mName = Name;
}
