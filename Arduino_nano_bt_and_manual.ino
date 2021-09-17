// define the GPIO connected with Relays and switches
#define Relay1 2  
#define Relay2 3
#define Relay3 9 
#define Relay4 10

#define switch1 5
#define switch2 6
#define switch3 7
#define switch4 8

int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;
    
char bt_data; // variable for storing bluetooth data 


void all_Switch_ON(){
  digitalWrite(Relay1, LOW);  delay(100);
  digitalWrite(Relay2, LOW);  delay(100);
  digitalWrite(Relay3, LOW);  delay(100);
  digitalWrite(Relay4, LOW);  delay(100);


}

void all_Switch_OFF(){
  digitalWrite(Relay1, HIGH); delay(100);
  digitalWrite(Relay2, HIGH); delay(100);
  digitalWrite(Relay3, HIGH); delay(100);
  digitalWrite(Relay4, HIGH); delay(100);


}

void Bluetooth_handle()
{
  bt_data = Serial.read();
//  Serial.println(bt_data);
  delay(20);

  switch(bt_data)
      {
        case 'W': digitalWrite(Relay1, LOW);   break; // if 'A' received Turn on Relay1
        case 'w': digitalWrite(Relay1, HIGH);  break; // if 'a' received Turn off Relay1
        case 'X': digitalWrite(Relay2, LOW);   break; // if 'B' received Turn on Relay2
        case 'x': digitalWrite(Relay2, HIGH);  break; // if 'b' received Turn off Relay2
        case 'Y': digitalWrite(Relay3, LOW);   break; // if 'C' received Turn on Relay3
        case 'y': digitalWrite(Relay3, HIGH);  break; // if 'c' received Turn off Relay3
        case 'Z': digitalWrite(Relay4, LOW);   break; // if 'D' received Turn on Relay4
        case 'z': digitalWrite(Relay4, HIGH);  break; // if 'd' received Turn off Relay4
        case 'A': all_Switch_ON(); break;  // if 'Z' received Turn on all Relays
        case 'a': all_Switch_OFF(); break; // if 'z' received Turn off all Relays
        default : break;
      }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

//During Starting all Relays should TURN OFF
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, LOW);
  digitalWrite(Relay3, LOW);
  digitalWrite(Relay4, LOW);
 
  delay(200);
}

void loop()
{  
  if (Serial.available()){
    delay(10); 
   Bluetooth_handle();
 }

 //Manual control
       
 if (digitalRead(switch1) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 0 )
    {
      digitalWrite(Relay1, LOW);
      switch_ON_Flag1_previous_I = 1;
    }
    

  }
  if (digitalRead(switch1) == HIGH )
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(Relay1, HIGH);
      switch_ON_Flag1_previous_I = 0;
    }
   
  }
 if (digitalRead(switch2) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 0 )
    {
      digitalWrite(Relay2, LOW);
      switch_ON_Flag2_previous_I = 1;
    }
    }
  if (digitalRead(switch2) == HIGH)
  {
    if (switch_ON_Flag2_previous_I == 1)
    {
      digitalWrite(Relay2, HIGH);
     switch_ON_Flag2_previous_I = 0;
    }
   
  }
   if (digitalRead(switch3) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 0 )
    {
      digitalWrite(Relay3, LOW);
      switch_ON_Flag3_previous_I = 1;
    }
    

  }
  if (digitalRead(switch3) == HIGH )
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(Relay3, HIGH);
      switch_ON_Flag3_previous_I = 0;
    }
   
  }
 if (digitalRead(switch4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 0 )
    {
      digitalWrite(Relay4, LOW);
      switch_ON_Flag4_previous_I = 1;
    }
    

  }
  if (digitalRead(switch4) == HIGH )
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(Relay4, HIGH);
      switch_ON_Flag4_previous_I = 0;
    }}

}
