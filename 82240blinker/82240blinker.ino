
void send_pulse(){
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  PORTD |= B00000100;
  delayMicroseconds(15);
  PORTD &= B11111011;
  delayMicroseconds(15);
  delayMicroseconds(217);
}

void send_nothing(){
  delayMicroseconds(427);
}

void send_byte(uint8_t b){
  uint8_t bursts[27] = {0};
  bursts[26] = 1;
  bursts[25] = 1;
  bursts[24] = 1;

  uint8_t ecc11 = ((b & 0x40) >> 6) + ((b & 0x20) >> 5) + ((b & 0x10) >> 4) + ((b & 0x08) >> 3);
  ecc11 = ecc11 & 1;
  if(ecc11)bursts[23]=1;
  else bursts[22]=1;

  uint8_t ecc10 = ((b & 0x80) >> 7) + ((b & 0x40) >> 6) + ((b & 0x20) >> 5) + ((b & 0x04) >> 2) + ((b & 0x02) >> 1);
  ecc10 = ecc10 & 1;
  if(ecc10)bursts[21]=1;
  else bursts[20]=1;

  uint8_t ecc9 = ((b & 0x80) >> 7) + ((b & 0x40) >> 6) + ((b & 0x10) >> 4) + ((b & 0x04) >> 2) + (b & 0x01);
  ecc9 = ecc9 & 1;
  if(ecc9)bursts[19]=1;
  else bursts[18]=1;

  uint8_t ecc8 = ((b & 0x80) >> 7) + ((b & 0x08) >> 3) + ((b & 0x02) >> 1) + (b & 0x01);
  ecc8 = ecc8 & 1;
  if(ecc8)bursts[17]=1;
  else bursts[16]=1;
  
  for(int i=0; i<16; i+=2){
    if(b & 1){
      bursts[i+1]=1;
    }else{
      bursts[i]=1;
    }  
    b = b >> 1;
  }

  for(int i=26; i>=0; i--)if(bursts[i])send_pulse();else send_nothing();
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
 if (Serial.available() > 0)send_byte(Serial.read());
}
