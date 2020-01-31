/* 
 * File:   TForm.h
 * Author: robert
 *
 * Created on 31 January 2020, 12:25
 */

#ifndef TFORM_H
#define TFORM_H

#include <string>

#include <TObject.h>
#include <gtk/gtk.h>

class TForm : public TObject
{
public:
    TForm();
    TForm(const TForm& orig);
    virtual ~TForm();
 
private:
    GtkWidget *window;
    int         Height;
    int         Width;

};

#endif /* TOBJECT_H */

