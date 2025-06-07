#include <Adafruit_NeoPixel.h>

// Configurações
#define PIN        5          // Pino de controle do WS2812
#define NUM_LEDS   16         // Quantidade de LEDs no anel

Adafruit_NeoPixel ring(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin();    
  ring.show();      // Limpa os LEDs
}

void loop() {
  rainbowCycle(10);  // Efeito arco-íris
}

// Funções auxiliares:
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) { 
    for (i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, Wheel((i * 256 / ring.numPixels() + j) & 255));
    }
    ring.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
