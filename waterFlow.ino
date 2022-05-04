const int sensor = A0;
int sensorValue = 0;
const int rele = 10;
bool isOn = false;
int count = 0;

void setup() {

  pinMode(rele, OUTPUT);
}

void loop() {

  sensorValue = analogRead(sensor);
  delay(1000);
  if(sensorValue > 200 && isOn == false)
  {
    digitalWrite(rele, HIGH);
    isOn = true;
  }
  else
  {
    count++;
    //Let the water flow for 5min
    if(count >= 300)
    {
      count = 0;
      isOn = false;
      digitalWrite(rele, LOW);
    }
    
  }

}
