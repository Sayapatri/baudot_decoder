/*************************************************
   RTTY DECODER for GR-SAKURA v1.0 2014.07.04
  Sayapatri
   5BIT-BAUDOT-CODE, 45.45baud
   LCD 16x2
/*************************************************/
    
#include <rxduino.h>
#include <liquidcrystal.h>
 
LiquidCrystal lcd(4,5,6,7,8,9,10);
#define INPUT_PIN 2
 
byte i   = 0;
byte j   = 0;
byte k   = 0;
byte l;
byte sq  = 0;
byte d1  = 0;
byte d2  = 0;
byte d3  = 0;
byte d4  = 0;
byte d5  = 0;
byte dsp = 0;
byte fig = 0;
char ch;
char c[17];
 
void timer_interrupt(void)
{
        i++;
        if(sq == 0 && digitalRead(INPUT_PIN) == 0)
        {
                sq = 1;
                i = 0;
        }
        if(sq == 1 && i == 10)
        {
                if(digitalRead(INPUT_PIN) == 0)
                {
                        sq = 2;
                        i = 0;
                }
                else
                {
                        sq = 0;
                }
        }
        if(sq == 2 && i == 22)
        {
                d1 = digitalRead(INPUT_PIN);
        }
        if(sq == 2 && i == 44)
        {
                d2 = digitalRead(INPUT_PIN);
        }
        if(sq == 2 && i == 66)
        {
                d3 = digitalRead(INPUT_PIN);
        }
        if(sq == 2 && i == 88)
        {
                d4 = digitalRead(INPUT_PIN);
        }
        if(sq == 2 && i == 110)
        {
                d5 = digitalRead(INPUT_PIN);
                dsp = 1;
        }
        if(sq == 2 && i == 135)
        {        
                sq = 0;
        }
}
 
void setup()
{
        lcd.begin(16, 2);
        lcd.clear();
        pinMode(PIN_LED0, OUTPUT);
        timer_regist_userfunc(timer_interrupt);
}
 
void loop()
{
        if(dsp == 1)
        {
                ch = '\0';
                if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 1) //LETTERS
                {
                        fig = 0;
                        digitalWrite(PIN_LED0, LOW);
                }
                if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 1) //FIGURES
                {
                        fig = 1;
                        digitalWrite(PIN_LED0, HIGH);
                }            
                if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 0){         } //CR
                if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 0){ch = ' ';} //LF
                if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 0){ch = ' ';} //SPACE
                if(fig == 0)
                {
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 0){ch = 'A';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 1){ch = 'B';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 0){ch = 'C';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 0){ch = 'D';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 0){ch = 'E';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 0){ch = 'F';}
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 1){ch = 'G';}
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 1){ch = 'H';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 0){ch = 'I';}
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 0){ch = 'J';}
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 0){ch = 'K';}
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 1){ch = 'L';}
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 1){ch = 'M';}
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 0){ch = 'N';}
                        if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 1){ch = 'O';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 1){ch = 'P';}
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 1){ch = 'Q';}
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 0){ch = 'R';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 0){ch = 'S';}
                        if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 1){ch = 'T';}
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 0){ch = 'U';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 1){ch = 'V';}
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 1){ch = 'W';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 1){ch = 'X';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 1){ch = 'Y';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 1){ch = 'Z';}
                }
                if(fig == 1)
                {
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 0){ch = '-';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 1){ch = '?';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 0){ch = ':';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 0){         }
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 0){ch = '3';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 0){         }
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 1){         }
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 1){         }
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 0){ch = '8';}
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 0){         }
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 0){ch = '(';}
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 1){ch = ')';}
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 1){ch = '.';}
                        if(d1 == 0 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 0){ch = ',';}
                        if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 1 && d5 == 1){ch = '9';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 1){ch = '0';}
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 1){ch = '1';}
                        if(d1 == 0 && d2 == 1 && d3 == 0 && d4 == 1 && d5 == 0){ch = '4';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 0){         }
                        if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 1){ch = '5';}
                        if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 0 && d5 == 0){ch = '7';}
                        if(d1 == 0 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 1){         }
                        if(d1 == 1 && d2 == 1 && d3 == 0 && d4 == 0 && d5 == 1){ch = '2';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 1 && d5 == 1){ch = '/';}
                        if(d1 == 1 && d2 == 0 && d3 == 1 && d4 == 0 && d5 == 1){ch = '6';}
                        if(d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0 && d5 == 1){         }
                }
                if(ch != '\0')
                {
                        lcd.setCursor(j, k);
                        lcd.print(ch);
                        c[j] = ch;
                        j++;
                        if(j == 16 && k == 0)
                        {
                                j = 0;
                                k = 1;
                        }
                        if(j == 16 && k == 1)
                        {
                                lcd.clear();
                                for(l = 0; l < 16; l++)
                                {
                                        lcd.print(c[l]);
                                }
                                j = 0;
                                k = 1;
                        }
                }
                dsp = 0;
        }
        delay(5);
}
