void test_led (int pin,int waktu) {
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
  delay(waktu);
  digitalWrite(pin,LOW);
}
