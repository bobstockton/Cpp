/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TObject.h
 * Author: robert
 *
 * Created on 31 January 2020, 12:25
 */

#ifndef TOBJECT_H
#define TOBJECT_H
#include <gtkmm.h>
#include <string>

class TObject {
public:
    TObject();
    TObject(const TObject& orig);
    virtual ~TObject();
    
    TObject     *Create();
 
    std::string getName();
    void        setName( std::string Name );
    virtual Gtk::Widget         *getGtkWidget();
private:
    
protected:
    
    
    TObject         *mParent;
    TObject         *mChildren;
    std::string     mClass;
    std::string     mName;  
  
};

#endif /* TOBJECT_H */

