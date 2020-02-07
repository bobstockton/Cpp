
#include <TApplication.h>
#include <Form1.h>
#include <iostream>

TApplication    *Application;
TForm           *Form1;
TForm           *Form2;


int main (int   argc,  char *argv[])
{  
    try
    {
        
        Application = new TApplication();

        Application->Initialise(argc, argv);
        Application->CreateForm( "frmForm1", Form1);
        Application->CreateForm( "frmForm2", Form2);
        Application->Run(argc, argv);
    }
    catch( char *e )
    {
        cout << "Exception: " << e << "\n";
    }
    

         
    return 0;
}


 

