#define BUZZER_PIN   12  // пин с пищалкой
#define PLAYER_COUNT 2   // количество игроков-ковбоев

#define T_B 200          // единица длительности ноты (оригинал бумер примерно 200)
#define T 200

// объявляем пару списков: один с номерами пинов с кнопками, другой — со светодиодами
int buttonPins[PLAYER_COUNT] = {3, 13};
int ledPins[PLAYER_COUNT] = {9, 11};

void bumer()
{
  for(int alpha = 0; alpha < 6; alpha++) {
    tone(BUZZER_PIN, 988, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1175, 3*T_B);
    delay(7*T_B);
    tone(BUZZER_PIN, 1175, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 988, 3*T_B);
    delay(7*T_B);

    tone(BUZZER_PIN, 1319, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1175, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1319, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1175, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1319, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1175, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1319, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1175, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1319, T_B);
    delay(T_B);
    tone(BUZZER_PIN, 1480, 3*T_B);
    delay(7*T_B);
  }
}

void gooses()
{
  tone(BUZZER_PIN, 698, T);
  delay(T);
  tone(BUZZER_PIN, 659, T);
  delay(T);
  tone(BUZZER_PIN, 587, T);
  delay(T);
  tone(BUZZER_PIN, 523, T);
  delay(T);
  tone(BUZZER_PIN, 784, 1.9*T);
  delay(2*T);
  tone(BUZZER_PIN, 784, 1.9*T);
  delay(2*T);

  tone(BUZZER_PIN, 698, T);
  delay(T);
  tone(BUZZER_PIN, 659, T);
  delay(T);
  tone(BUZZER_PIN, 587, T);
  delay(T);
  tone(BUZZER_PIN, 523, T);
  delay(T);
  tone(BUZZER_PIN, 784, 1.9*T);
  delay(2*T);
  tone(BUZZER_PIN, 784, 1.9*T);
  delay(2*T);

  tone(BUZZER_PIN, 698, T);
  delay(T);
  tone(BUZZER_PIN, 880, .9*T);
  delay(T);
  tone(BUZZER_PIN, 880, T);
  delay(T);
  tone(BUZZER_PIN, 698, T);
  delay(T);
  tone(BUZZER_PIN, 659, T);
  delay(T);
  tone(BUZZER_PIN, 784, .9*T);
  delay(T);
  tone(BUZZER_PIN, 784, T);
  delay(T);
  tone(BUZZER_PIN, 659, T);
  delay(T);

  tone(BUZZER_PIN, 587, T);
  delay(T);
  tone(BUZZER_PIN, 659, T);
  delay(T);
  tone(BUZZER_PIN, 698, T);
  delay(T);
  tone(BUZZER_PIN, 587, T);
  delay(T);
  tone(BUZZER_PIN, 523, 1.9*T);
  delay(2*T);
  tone(BUZZER_PIN, 523, 1.9*T);
  delay(2*T);
}

void setup()
{  
  pinMode(BUZZER_PIN, OUTPUT);
  for (int player = 0; player < PLAYER_COUNT; ++player) {
    pinMode(ledPins[player], OUTPUT);
    pinMode(buttonPins[player], INPUT_PULLUP);
  }
}
 
void loop()
{
  //bumer();
  //gooses();
  
  // даём сигнал «пли!», выждав случайное время от 2 до 7 сек
  delay(random(2000, 7000));
  tone(BUZZER_PIN, 3000, 250); // 3 килогерца, 250 миллисекунд
 
  for (int player = 0; ; player = (player + 1) % PLAYER_COUNT) {
    // если игрок номер «player» нажал кнопку...
    if (!digitalRead(buttonPins[player])) {
      // ...включаем его светодиод и сигнал победы на 1 сек
      digitalWrite(ledPins[player], HIGH);
      tone(BUZZER_PIN, 4000, 1000);
      delay(1000);
      digitalWrite(ledPins[player], LOW);
      break; // Есть победитель! Выходим
    }
  }
  delay(1000);
}
