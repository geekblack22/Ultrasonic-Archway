void lessthan1()
{
  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 10, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }

  //talkMIDI(0xB0,0,0x70);
  talkMIDI(0xC0, instrument, 0);
  //Serial.println(instrument);
  noteOn(0, 0, 0);
  delay(10);
  noteOff(0, 0, 0);
}
void lessthan40()
{
  for (int i = gucci; i < i + 4; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(150, 150, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument, 0 );
  //Serial.println(instrument);
  noteOn(0, note, 200);
  delay(10);
  noteOff(0, note, 0);
  //digitalWrite(40, HIGH);
}




void lessthan70()
{
  for (int i = gucci; i < i + 4; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument, 0 );
  //Serial.println(instrument);
  noteOn(0, note + 10, 200);
  delay(10);
  noteOff(0, note + 10, 0);
  digitalWrite(42, HIGH);

}
void lessthan95()
{
  for (int i = gucci; i < i + 4; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 150, 150)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  //talkMIDI(0xB0,0,0x70 );
  talkMIDI(0xC0, instrument, 0 );
  Serial.println(instrument);
  noteOn(0, note + 15, 200);
  delay(10);
  noteOff(0, note + 15, 0);
  //digitalWrite(42, HIGH);
}

