#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second
int duration;
//setting up a variable for the distance calculated
int distance;
int gucci = 0;
 
//#define FADESPEED 5 

SoftwareSerial mySerial(2, 3); // RX, TX

byte note = 0; //The MIDI note value to be played
byte resetMIDI = 4; //Tied to VS1053 Reset line
byte ledPin = 13; //MIDI traffic inidicator
//int counter=15;
int instrument=35;







  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket




void setup() {
  Serial.begin(57600);
  

  //Reset the VS1053
  pinMode(resetMIDI, OUTPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);
  //talkMIDI(127, 0x07, 120); //0xB0 is channel message, set channel volume to near max (127)


//turn on serial monitor so you can read data
Serial.begin(9600);
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

pixels.begin(); // This initializes the NeoPixel library.//setting up a variable for the duration of the pulse




  
}

void loop() {


/* // put your main code here, to run repeatedly:
//give a short low pulse to ensure a clean long high pulse
digitalWrite(trig, LOW);
delayMicroseconds(2);
//Give high pulse that triggers the sensor to send an ultrasonic pulse.
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
//Time between pulse being sent out and received is duration
duration = pulseIn(echo, HIGH);
digitalWrite(trig, LOW);
delayMicroseconds(2);
//Give high pulse that triggers the sensor to send an ultrasonic pulse.

distance = (duration*.034)/2;*/




for (int x = 22;x < 36;x+=2)

{

  //Serial.print(counter);

// instrument= counter*2;
Serial.print(x);
  pinMode(x, OUTPUT);
  pinMode(x+1, INPUT); 





if (x==22)
{
  note=40;
  gucci = 0;
}
else if (x==24)
{
  note=47;
  gucci = 4;
}

else if (x==26)
{
  note=50;
  gucci = 8;
}

else if (x==28)
{
 note=55;
 gucci = 12; 
}

else if (x==30)
{
  note=59;
  gucci = 16;
}
else if (x==32)
{
 note=64;
 gucci = 20;
}
else if (x==34)
{
 note=67;
 gucci = 24;
}

  

/*trig = x;
echo = x+1;*/

 // put your main code here, to run repeatedly:
//give a short low pulse to ensure a clean long high pulse
digitalWrite(x, LOW);
delayMicroseconds(2);
//Give high pulse that triggers the sensor to send an ultrasonic pulse.
digitalWrite(x, HIGH);
delayMicroseconds(10);
digitalWrite(x,LOW);
//Time between pulse being sent out and received is duration
duration = pulseIn(x+1, HIGH);
digitalWrite(x, LOW);
delayMicroseconds(2);
//Give high pulse that triggers the sensor to send an ultrasonic pulse.

distance = (duration*.034)/2;

Serial.print("distance:");
Serial.print(distance);
Serial.println();

if(distance<1)
{
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,10,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }

  //talkMIDI(0xB0,0,0x70);
 talkMIDI(0xC0,instrument,0);
 //Serial.println(instrument);
   noteOn(0, 0, 0);
   delay(10);
   noteOff(0,0,0);

   
}



else if (distance<40)
{
    for(int i=gucci;i<i+4;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(150,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

   

  }
   //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument,0 );
   //Serial.println(instrument);
   noteOn(0, note, 200);
   
   delay(10);
   noteOff(0,note, 0);
   

   //digitalWrite(40, HIGH);

}
else if (distance <70){
   for(int i=gucci;i<i+4;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    
    }
   //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument,0 );
   //Serial.println(instrument);
   noteOn(0, note+10, 200);
   delay(10);
   noteOff(0,note+10, 0);
   digitalWrite(42, HIGH); 
  
   }

else if (distance<95)
{
   for(int i=gucci;i<i+4;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,150)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    
   }
   //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument,0 );
   Serial.println(instrument);
   noteOn(0, note+15, 200);
   delay(10);
   noteOff(0,note+15, 0);
   //digitalWrite(42, HIGH); 
   }


else {
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,10,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }

   
   
   
  
}



/*if (counter>20)
{
  //instrument+20;
  //counter=0;

}
//counter++;*/
}










  //Demo Basic MIDI instruments, GM1
  //=================================================================
  Serial.println("Basic Instruments");
  talkMIDI(0xB0, 0, 0x00); //Default bank GM1

  //Change to different instrument
 /* for(instrument = 80 ; instrument < 127 ; instrument++) {

    Serial.print(" Instrument: ");
    Serial.println(instrument, DEC);

    talkMIDI(0xC0, instrument, 0); //Set instrument number. 0xC0 is a 1 data byte command

    //Play notes from F#-0 (30) to F#-5 (90):
    for (note = 30 ; note < 40 ; note++) {
      Serial.print("N:");
      Serial.println(note, DEC);
      
      //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOn(0, note, 60);
      delay(50);

      //Turn off the note with a given off/release velocity
      noteOff(0, note, 60);
      delay(50);
    }

    delay(100); //Delay between instruments
  }*/
  //=================================================================



/*
  //Demo GM2 / Fancy sounds
  //=================================================================
  Serial.println("Demo Fancy Sounds");
  talkMIDI(0xB0, 0, 0x78); //Bank select drums

  //For this bank 0x78, the instrument does not matter, only the note
  for(instrument = 30 ; instrument < 31 ; instrument++) {

    Serial.print(" Instrument: ");
    Serial.println(instrument, DEC);

    talkMIDI(0xC0, instrument, 0); //Set instrument number. 0xC0 is a 1 data byte command

    //Play fancy sounds from 'High Q' to 'Open Surdo [EXC 6]'
    for (note = 27 ; note < 87 ; note++) {
      Serial.print("N:");
      Serial.println(note, DEC);
      
      //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOn(0, note, 60);
      delay(100);

      //Turn off the note with a given off/release velocity
      noteOff(0, note, 60);
      delay(100);
    }

    delay(100); //Delay between instruments
  }
*/


/*
  //Demo Melodic
  //=================================================================
  Serial.println("Demo Melodic? Sounds");
  talkMIDI(0xB0, 0, 0x79); //Bank select Melodic
  //These don't sound different from the main bank to me

  //Change to different instrument
  for(instrument = 27 ; instrument < 87 ; instrument++) {

    Serial.print(" Instrument: ");
    Serial.println(instrument, DEC);

    talkMIDI(0xC0, instrument, 0); //Set instrument number. 0xC0 is a 1 data byte command

    //Play notes from F#-0 (30) to F#-5 (90):
    for (note = 30 ; note < 40 ; note++) {
      Serial.print("N:");
      Serial.println(note, DEC);
      
      //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOn(0, note, 60);
      delay(50);

      //Turn off the note with a given off/release velocity
      noteOff(0, note, 60);
      delay(50);
    }

    delay(100); //Delay between instruments
  }
*/


}

//Send a MIDI note-on message.  Like pressing a piano key
//channel ranges from 0-15
void noteOn(byte channel, byte note, byte attack_velocity) {
  talkMIDI( (0x90 | channel), note, attack_velocity);
}

//Send a MIDI note-off message.  Like releasing a piano key
void noteOff(byte channel, byte note, byte release_velocity) {
  talkMIDI( (0x80 | channel), note, release_velocity);
}

//Plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that data values are less than 127
void talkMIDI(byte cmd, byte data1, byte data2) {
  digitalWrite(ledPin, HIGH);
  mySerial.write(cmd);
  mySerial.write(data1);

  //Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes 
  //(sort of: http://253.ccarh.org/handout/midiprotocol/)
  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2);

  digitalWrite(ledPin, LOW);
}

