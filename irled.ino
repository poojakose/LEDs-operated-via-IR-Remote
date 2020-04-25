#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0xFF6897
#define BUTTON_0 0xFF4AB5


int blue_LED = 7;

void setup()
{
  pinMode(blue_LED, OUTPUT);

  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTTON_0)
    {
      digitalWrite(blue_LED, LOW);
    }
    
    if (results.value == BUTTON_1)
    {
      digitalWrite(blue_LED, HIGH);
    }
   
    irrecv.resume();
  }
}
