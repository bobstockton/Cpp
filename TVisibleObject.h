/*
 * (c)R.Stockton.
 */

/* 
 * File:   TVisibleObject.h
 * Author: robert
 *
 * Created on 04 February 2020, 09:01
 */

#ifndef TVISIBLEOBJECT_H
#define TVISIBLEOBJECT_H
#include <gtkmm.h>
#include <string>

#include <TFormDefinitionSection.h>

#include <TObject.h>
#include <TPosition.h>
#include <TFont.h>
#include <TSize.h>



class TVisibleObject : public TObject
{
public:
    TVisibleObject();
    TVisibleObject(const TVisibleObject& orig);
    virtual ~TVisibleObject();    
    virtual void rtti_function() {};
    
    void        setPosition( int X, int Y );
    void        setSize( int X, int Y );
    
    void        setTooltipText( string text );
    
    bool        getVisible();
    void        setVisible( bool visible );
    Gtk::Widget *getWidget();
    
private:
    
        
protected: 
    TPosition   mPosition;
    TSize       mSize;
    TFont       mDefaultFont;
    bool        mVisible;
    bool        mFocus;
    int         mSequence;
    int         mHeight;
    int         mLeft;
    int         mTop;
    int         mWidth;
    string      mTooltip;
    
    Gtk::Widget *mWidget;
    
 
};

#endif /* TVISIBLEOBJECT_H */

