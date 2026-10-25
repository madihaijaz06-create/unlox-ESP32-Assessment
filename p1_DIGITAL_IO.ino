const int BUTTON1 = 18;
const int BUTTON2 = 19;
const int LED_PIN = 23;
const int BUZZER_PIN = 22;

int lastButton1 = HIGH;
int lastButton2 = HIGH;

unsigned long lastDebounce1 = 0;
unsigned long lastDebounce2 = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  int reading1 = digitalRead(BUTTON1);
  int reading2 = digitalRead(BUTTON2);

  if (reading1 == LOW && lastButton1 == HIGH &&
      millis() - lastDebounce1 >= debounceDelay) {
    lastDebounce1 = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    Serial.println("Button 1 pressed: LED toggled");
  }

  if (reading2 == LOW && lastButton2 == HIGH &&
      millis() - lastDebounce2 >= debounceDelay) {
    lastDebounce2 = millis();
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Button 2 pressed: Buzzer ON");
  }

  if (reading2 == HIGH) {
    digitalWrite(BUZZER_PIN, LOW);
  }

  lastButton1 = reading1;
  lastButton2 = reading2;
  delay(10);
}
