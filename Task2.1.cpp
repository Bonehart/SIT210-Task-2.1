
#include "lib1.h"

String aString = "nicolas";
int length = 7;

int led1 = D0;
int led2 = D8; 

String convert(char alpha)
{
    switch (alpha)
    {
    case 'a': return ".-";        
    case 'b': return "-...";        
    case 'c': return "-.-.";        
    case 'd': return "-..";        
    case 'e': return ".";        
    case 'f': return "..-.";        
    case 'g': return "--.";       
    case 'h': return "....";       
    case 'i': return "..";      
    case 'j': return ".---";      
    case 'k': return "-.-";    
    case 'l': return ".-..";
    case 'm': return "--";   
    case 'n': return "-."; 
    case 'o': return "---";  
    case 'p': return ".--.";  
    case 'q': return "--.-"; 
    case 'r': return ".-.";     
    case 's': return "...";    
    case 't': return "-";      
    case 'u':  return "..-";       
    case 'v': return "...-";       
    case 'w': return ".--";      
    case 'x': return "-..-";       
    case 'y': return "-.--";      
    case 'z': return "--..";       
    default: return " "; 
    }
}

int toDelay(char k)
{
    if (k == '.')
        return 100;
    else if (k == '-')
        return 1000;
    else if (k == ' ')
        return 0;
    else
        return 0;
}

void nameCode(String name)
{
    String coded;
    for (int i = 0; i <= length; i++)
    {
        String x = convert(name[i]);
        coded = coded + x + " ";
    }

    for (int i = 0; i <= coded.length(); i++)
    {
        int time;

        time = toDelay(coded[i]);
        if (time != 0)
        {
            digitalWrite(led2, HIGH);
        }

        delay(time);

        if (time != 0)
        {
            digitalWrite(led2, LOW);
        }

        delay(500);
    }
}

void setup()
{

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop()
{

    nameCode(aString);
}
