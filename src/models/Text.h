#pragma once

class Text {
public:
    Text(char* text);
    Text();
    
    void getText();   
    void setText(char* text);
 

private:
    char* text;
};