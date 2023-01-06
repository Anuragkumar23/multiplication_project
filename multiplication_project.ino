 #include <Wire.h> 
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// SDA - A4
// SCL - A5

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup()
{
  Serial.begin(9600);
 
}

void loop()
{
 char key = customKeypad.getKey();
 int c = key - '0';
 if(c>0){
for(int i=1;i<=10;i++)
{
  int j=c*i;
  
  Serial.print(String(c));
  Serial.print" * ";
  Serial.print(String(i));
  Serial.print"=";
  Serial.println(String(j));
  }
}
}
 
  
