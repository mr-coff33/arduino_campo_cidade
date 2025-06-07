#define TDS_PIN 18
#define NUM_READINGS 10

float readings[NUM_READINGS];
int readIndex = 0;
float total = 0;
float average = 0;

void setup() {
  Serial0.begin(115200);
  analogReadResolution(12);
  delay(1000);
  Serial0.println("Iniciando leitura TDS com média móvel");
  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];          // Remove a leitura mais antiga
  readings[readIndex] = analogRead(TDS_PIN);   // Lê valor novo
  total = total + readings[readIndex];          // Adiciona nova leitura
  readIndex = (readIndex + 1) % NUM_READINGS;   // Move índice circular

  average = total / NUM_READINGS;                // Calcula média

  float voltage = average * 3.3 / 4095.0;
  float tdsValue = (133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage) * 0.5;

  Serial0.print("Tensão média: ");
  Serial0.print(voltage, 2);
  Serial0.print(" V | TDS média: ");
  Serial0.print(tdsValue, 2);
  Serial0.println(" ppm");

  delay(1000);
}
