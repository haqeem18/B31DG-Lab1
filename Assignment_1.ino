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
    pinMode(SigA_pin, OUTPUT);	// Set SigA_pin as output
    pinMode(SigB_pin, OUTPUT);	// Set SigB_pin as output
    pinMode(ButtonA_pin, INPUT);	// Set ButtonA_pin as input
    pinMode(ButtonB_pin, INPUT); 	// Set ButtonB_pin as input
}

void loop()
{
    // Execute waveform when Button A = LOW
    if (digitalRead(ButtonA_pin) == LOW)
    {
      pulse(SigB_pin, paramB_high, 0);			// Generate Signal B
      SigA_output(param_a, param_b, param_c, param_d);	// Generate Signal A

    }
}

// Generate Signal A waveform
void SigA_output(int a, int b, int c, int d)
{
    int add = 0;
    
    // Signal A (normal)
    if (digitalRead(ButtonB_pin) == LOW)
    {
        for (int i=0; i<c; i++)		// Repeat loop for c amount of cycle
        {
            pulse(SigA_pin, a + add, b); 	// Generate pulse for 1st,2nd,3rd,etc
            add = add + 50;		   	// Increment pulse width by 50 us
        }
        delayMicroseconds(d);
    }
    // Signal A (inverted)
    else
    {
        a = a + (c-1)*50;		  	// Calculate the longest pulse width
        for (int i=0; i<c; i++)		// Repeat loop for c amount of cycle
        {
            pulse(SigA_pin, a + add, b); 	// Generate pulse for 1st,2nd,3rd,etc
            add = add - 50;	           	// Decrement pulse width by 50 us
        }
        delayMicroseconds(d);
    }
}

// Generate one pulse
void pulse(int pin, int high_width, int low_width)
{
  digitalWrite(pin, HIGH);			// Set output pin to HIGH
  delayMicroseconds(high_width);		// Width during HIGH 
  digitalWrite(pin, LOW);			// Set output pin to LOW
  delayMicroseconds(low_width);		// Width for LOW
}
