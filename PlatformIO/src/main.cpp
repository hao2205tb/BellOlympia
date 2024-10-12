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

/* function prototype */
ICACHE_RAM_ATTR void BTN_A_ISR();
ICACHE_RAM_ATTR void BTN_B_ISR();
ICACHE_RAM_ATTR void BTN_C_ISR();
ICACHE_RAM_ATTR void BTN_D_ISR();

/* local variables */
static uint32 u32_delta_time;
static bool   b_count_flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {

}

ICACHE_RAM_ATTR void BTN_A_ISR()
{

}
ICACHE_RAM_ATTR void BTN_B_ISR()
{

}
ICACHE_RAM_ATTR void BTN_C_ISR()
{

}
ICACHE_RAM_ATTR void BTN_D_ISR()
{

}