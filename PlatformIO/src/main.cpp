#include <Arduino.h>

/* macro defination */
#define GROUP_A_BUTTON_PIN  (D1)   
#define GROUP_A_LIGHT_PIN   (D2)

#define GROUP_B_BUTTON_PIN  (D3)
#define GROUP_B_LIGHT_PIN   (D4)

#define GROUP_C_BUTTON_PIN  (D5)
#define GROUP_C_LIGHT_PIN   (D6)

#define GROUP_D_BUTTON_PIN  (D7)
#define GROUP_D_LIGHT_PIN   (D8)

#define LIGHT_TIME          (5000) // ms

/* function prototype */
ICACHE_RAM_ATTR void BTN_A_ISR();
ICACHE_RAM_ATTR void BTN_B_ISR();
ICACHE_RAM_ATTR void BTN_C_ISR();
ICACHE_RAM_ATTR void BTN_D_ISR();

void ISR_Register(uint8_t btn_pin, void (*ISR)());

/* local variables */
unsigned long   previousMillis = 0;
static bool     b_count_flag = false;
static uint8_t  u8_ledpin_choice;

/* Function defination */
void setup() 
{
  Serial.begin(115200);

  pinMode(GROUP_A_LIGHT_PIN, OUTPUT);
  pinMode(GROUP_B_LIGHT_PIN, OUTPUT);
  pinMode(GROUP_C_LIGHT_PIN, OUTPUT);
  pinMode(GROUP_D_LIGHT_PIN, OUTPUT);

  ISR_Register(GROUP_A_BUTTON_PIN, BTN_A_ISR);
  ISR_Register(GROUP_B_BUTTON_PIN, BTN_B_ISR);
  ISR_Register(GROUP_C_BUTTON_PIN, BTN_C_ISR);
  ISR_Register(GROUP_D_BUTTON_PIN, BTN_D_ISR);

}

void loop() 
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= LIGHT_TIME) {
    digitalWrite(u8_ledpin_choice, LOW);
    Serial.println("Turn off LED\n");
  }
}

void ISR_Register(uint8_t btn_pin, void (*ISR)())
{
  pinMode(btn_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btn_pin), ISR, FALLING);
}

void Btn_Handle(uint8_t led_pin)
{
  if (b_count_flag == false){
    b_count_flag = true;
    previousMillis = millis();
    Serial.println("Turn on LED\n");
    digitalWrite(led_pin, HIGH);
    u8_ledpin_choice = led_pin;
  }
}

ICACHE_RAM_ATTR void BTN_A_ISR()
{
  Serial.println("BTN A is pressed!\n");
  Btn_Handle(GROUP_A_LIGHT_PIN);
}

ICACHE_RAM_ATTR void BTN_B_ISR()
{
  Serial.println("BTN B is pressed!\n");
  Btn_Handle(GROUP_B_LIGHT_PIN);
}

ICACHE_RAM_ATTR void BTN_C_ISR()
{
  Serial.println("BTN C is pressed!\n");
  Btn_Handle(GROUP_C_LIGHT_PIN);
}

ICACHE_RAM_ATTR void BTN_D_ISR()
{
  Serial.println("BTN D is pressed!\n");
  Btn_Handle(GROUP_D_LIGHT_PIN);
}