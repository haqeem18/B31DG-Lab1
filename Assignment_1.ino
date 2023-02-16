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
    pulse(SigB_pin, paramB_high, 0);
}

void pulse(int pin, int high_width, int low_width)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(high_width);
  digitalWrite(pin, LOW);
  delayMicroseconds(low_width);
}