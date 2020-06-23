#define THRESHOLD 89
void setup() {
 pinMode(13, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(8, INPUT);
 Serial.begin(9600);
 digitalWrite(13, LOW);
}

int strikes = 0; 
void loop() {
  long delay_avg = 0;
  for(int i = 0; i < 1000; i ++)
  {
    long delay_ = pulseIn(8, HIGH);
    delay_avg = delay_avg + delay_;
  }

  delay_avg = delay_avg/1000;
//  Serial.println(delay_avg);
  if(delay_avg >THRESHOLD)
  {
    strikes++; 
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
    if(strikes > 0)
    {
      strikes--;
    }
  }
  //Serial.println(strikes);
  if(strikes > 40)
  {
    digitalWrite(13, HIGH);
    while(true)
    {
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      delay(500);
    }
  }
  
  delay_avg = 0;

}
