#define FASTADC 1
#define THRESHOLD 600


// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup() {
 int start ;
 int i ;
 
#if FASTADC
 // set prescale to 16
 sbi(ADCSRA,ADPS2) ;
 cbi(ADCSRA,ADPS1) ;
 cbi(ADCSRA,ADPS0) ;
#endif

 Serial.begin(9600) ;
 Serial.print("ADCTEST: ") ;
 start = millis() ;
 for (i = 0 ; i < 1000 ; i++)
   analogRead(0) ;
 Serial.print(millis() - start) ;
 Serial.println(" msec (1000 calls)") ;
 
 pinMode(13, OUTPUT);
 pinMode(12, OUTPUT);
 digitalWrite(12, LOW);
}

void loop() {
  
  digitalWrite(13, HIGH);
  int val = 0;
  long time_ = micros();
  while(val < THRESHOLD)
  {
    val = analogRead(A0);
  }
  
  int diff = micros() - time_;
  Serial.println(diff);
  digitalWrite(13, LOW);

  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);


}
