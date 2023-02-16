// Signal pins & Switch pins
#define SigA_pin 4    // led 1 pin
#define SigB_pin 5    // led 2 pin
#define ButtonA_pin 1 // button 1 pin
#define ButtonB_pin 2 // button 2 pin

// Signal A parameter
int param_a = 100;  // initial width
int param_b = 700;  // between pulses
int param_c = 6;    // no. of pulses
int param_d = 4500; // end delayMicroseconds of waveform

// Signal B parameter
int paramB_high = 50; // signal b width

void setup()
{
    // Serial monitor setup
    Serial.begin(115200);

    // Set signal output pin
    pinMode(SigA_pin, OUTPUT);
    pinMode(SigB_pin, OUTPUT);
    pinMode(ButtonA_pin, INPUT);
    pinMode(ButtonB_pin, INPUT); 
}

void loop()
{
    if (digitalRead(ButtonA_pin) == LOW)
    {
      pulse(SigB_pin, paramB_high, 0);
      SigA_output(param_a, param_b, param_c, param_d);
    }
}

void SigA_output(int a, int b, int c, int d)
{
    int add = 0;
        
    for (int i=0; i<c; i++)
    {
        pulse(SigA_pin, a + add, b);
        add = add + 50;
    }
    delayMicroseconds(d);
}


void pulse(int pin, int high_width, int low_width)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(high_width);
  digitalWrite(pin, LOW);
  delayMicroseconds(low_width);
}