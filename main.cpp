
#include <TApplication.h>
#include <Form1.h>

TApplication    *Application;
TForm           *Form1;
TForm           *Form2;


int main (int   argc,  char *argv[])
{  
    Application = new TApplication();
    
    Application->Initialise(argc, argv);
    Application->CreateForm( "Form1", Form1);
    Application->CreateForm( "Form2", Form2);
    Application->Run(argc, argv);
   
         
    return 0;
}


 

