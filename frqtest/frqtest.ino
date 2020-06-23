void setup() {
 pinMode(13, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(8, INPUT);
 Serial.begin(9600);
 digitalWrite(13, LOW);
}

void loop() {
  long delay_avg = 0;
  for(int i = 0; i < 1000; i ++)
  {
  long delay_ = pulseIn(8, HIGH);
  delay_avg = delay_avg + delay_;
  }
 // Serial.println(delay_avg / 1000);
  
  if(delay_avg/1000 >73)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  
  delay_avg = 0;

}
