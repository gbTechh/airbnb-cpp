#include <iostream>
#include <stdio.h>
#include "./screenView.h"
#include "./colors.h"


using namespace std;

int main(int argc, char *argv[])
{   


    char input = 'm';    
 
    ScreenView screen;
    screen.start(input);
   
    return 0;
}
