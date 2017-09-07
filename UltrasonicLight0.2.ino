/*UtrasonicArchway project
 * Program created by Serena Fernandopulle and Yveder Joseph
 * The purpose of this project was to create a fairly large archway 
  that whould create music based on you're movements in the archway.
 *Music shield obtainable at: https://www.sparkfun.com/products/10587
 *A motor controller is neeeded to controll the 16 Neopixels
 * Obtainable at:https://www.amazon.com/dp/B014KMHSW6/ref=asc_df_B014KMHSW65158892/?tag=hyprod-20&creative=395033&creativeASIN=B014KMHSW6&linkCode=df0&hvadid=167139094796&hvpos=1o3&hvnetw=g&hvrand=8208415480363142874&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9002003&hvtargid=pla-306436938191
 *A twelve volt powersuply is also needed for the lighst
 *Obtainable at:https://www.adafruit.com/product/276?gclid=Cj0KCQjw3MPNBRDjARIsAOYU6x_1FKFqG501hJW10iqWRKnFzDEyDriRwYkswJ1_UYAz6825z5_gULYaAhyUEALw_wcB
 */ 

#include <SoftwareSerial.h>

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
int instrument = 35;







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

void loop() 
{

  for (int x = 22; x < 36; x += 2)
  {
    //Serial.print(counter);
    // instrument= counter*2;
    Serial.print(x);
    pinMode(x, OUTPUT);
    pinMode(x + 1, INPUT);

    if (x == 22) {note = 40;  gucci = 0; }
    else if (x == 24){ note = 47; gucci = 4; }
    else if (x == 26){note = 50;gucci = 8;}
    else if (x == 28){note = 55;gucci = 12;}
    else if (x == 30){note = 59;gucci = 16;}
    else if (x == 32){note = 64;gucci = 20;}
    else if (x == 34){note = 67; gucci = 24;}
    
    //give a short low pulse to ensure a clean long high pulse
    digitalWrite(x, LOW);
    delayMicroseconds(2);
    //Give high pulse that triggers the sensor to send an ultrasonic pulse.
    digitalWrite(x, HIGH);
    delayMicroseconds(10);
    digitalWrite(x, LOW);
    //Time between pulse being sent out and received is duration
    duration = pulseIn(x + 1, HIGH);
    digitalWrite(x, LOW);
    delayMicroseconds(2);
    //Give high pulse that triggers the sensor to send an ultrasonic pulse.
    distance = (duration * .034) / 2;
    Serial.print("distance:");
    Serial.print(distance);
    Serial.println();

    if (distance < 1)lessthan1();
    else if (distance < 40)lessthan40();
    else if (distance < 70)lessthan70();
    else if (distance < 95) lessthan95();
  }

  Serial.println("Basic Instruments");
  talkMIDI(0xB0, 0, 0x00); //Default bank GM1
}

//Send a MIDI note-on message.  Like pressing a piano key
//channel ranges from 0-15





