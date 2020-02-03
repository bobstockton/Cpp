
#include <TApplication.h>
#include <Form1.h>

TApplication *Application;
TForm        *Form1;


int main (int   argc,  char *argv[])
{  
    Application = new TApplication();
    
    Application->Initialise(argc, argv);
    Application->CreateForm( "Form1", Form1);
    Application->Run(argc, argv);
   
         
    return 0;
}


 

