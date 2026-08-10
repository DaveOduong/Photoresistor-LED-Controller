const byte Photo_Resistor = A0;
unsigned const int Max_Delay= 500;
unsigned const int Mini_Delay= 50;

void setup()
{
pinMode(LED_BUILTIN,OUTPUT);
pinMode(Photo_Resistor,INPUT) ;

Serial.begin(9600);
}

void loop()
{
unsigned int Light_value = analogRead(Photo_Resistor);
Serial.print("Light Value:");
Serial.print(Light_value);
  
static unsigned int Max_light=Light_value ; 
static unsigned int Mini_light=Light_value ; 
  
if(Max_light>Light_value )
{Max_light=Light_value ;}
  
if(Mini_light<Light_value )
{Mini_light=Light_value ;}

unsigned int delay_value= map(Light_value,Max_light,Mini_light, Max_Delay, Mini_Delay);
Serial.print(" Delay Value:");
Serial.println(delay_value);
  
digitalWrite(LED_BUILTIN,HIGH);
delay(delay_value);  
  
digitalWrite(LED_BUILTIN,LOW);
delay(delay_value);   
}
