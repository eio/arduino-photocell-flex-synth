
////////////////////////////////////////////////////////////////////////
//// Stereo Pressure-Synth with Light-Dependent Delay Between Tones ////
////              ~ Elliott Wobler, 5 May 2013 ~                    ////
////////////////////////////////////////////////////////////////////////

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the first (left) photocell:
  int photocellL = analogRead(A1);
  // print the sensor reading so you know its range
  Serial.println(photocellL);
  // map the analog input range 
  // to the duration of the delay between pulses
  int delayL = map(photocellL, 0, 1000, 1, 400);

  // read the second (right) photocell:
  int photocellR = analogRead(A4);
  // print the sensor reading so you know its range
  Serial.println(photocellR);
  // map the analog input range 
  // to the duration of the delay between pulses
  int delayR = map(photocellR, 0, 1000, 1, 400);

  //////////////////////////////////////////////////////
  
  // read the first (left) flex sensor:
  int sensorReadingL = analogRead(A0);
  // print the sensor reading so you know its range
  Serial.println(sensorReadingL);
  // map the analog input range 
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  int thisPitchL = map(sensorReadingL, 0, 1000, 20, 2200);
 
  // play the pitch through left speaker:
  // tone(10, thisPitchL, 10); // INSTRUMENT # 1 //
  tone(10, thisPitchL, delayL); //INSTRUMENT # 2 // cover/hold photocells to mute
  delay(delayL);        // actual duration L
  // noTone(10);
  
  // read the second (right) flex sensor:
  int sensorReadingR = analogRead(A5);
  // print the sensor reading so you know its range
  Serial.println(sensorReadingR);
  // map the analog input range 
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  int thisPitchR = map(sensorReadingR, 0, 1000, 20, 2200);

  // play the pitch through right speaker:
  // tone(11, thisPitchR, 10); // INSTRUMENT # 1 //
  tone(11, thisPitchR, delayR); // INSTRUMENT # 2 // cover/hold photocells to mute
  delay(delayR);        // actual duration R
  // noTone(11);
}
  













