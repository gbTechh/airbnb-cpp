#include <iostream>
#include <stdio.h>
#include "./screenView.h"
#include "./colors.h"

#include "./helpers/String.h"
// #include "./models/Admin.h"

using namespace std;

int main(int argc, char *argv[])
{   


    char input = 'm';
    
 
    ScreenView screen;
    screen.start(input);
   
    return 0;
}
