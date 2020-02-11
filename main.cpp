
#include <TApplication.h>
#include <Form1.h>
//#include <Form2.h>
#include <iostream>

TApplication    *Application;
Form1           frmMain;
TForm           *Form2;


int main (int   argc,  char *argv[])
{  
    try
    {
        
        Application = new TApplication();
        
      
       // Form2 = new Form2();

        Application->Initialise(argc, argv);
        Application->CreateForm( "frmForm1", &frmMain);
      //  Application->CreateForm( "frmForm2", Form2);
        Application->Run(argc, argv);
    }
    catch( char *e )
    {
        cout << "Exception: " << e << "\n";
    }
    

         
    return 0;
}


 

