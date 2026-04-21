#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin sama seperti kode awal, tambah btn3
const int button1 = 4; // Maju
const int button2 = 2; // Mundur
const int button3 = 3; // Menu Awal

// Data Pembalap F1
const int jumlah = 5;

String tim[] = {
  "Ferrari",
  "Red Bull",
  "Mercedes",
  "McLaren",
  "Aston Martin"
};

String pembalap[] = {
  "Lewis Hamilton",
  "Max Verstappen",
  "George Russell",
  "Lando Norris",
  "Fernando Alonso"
};

int idx = -1; // -1 = menu awal

void tampilMenu();
void tampilPembalap(int i);

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  tampilMenu();
}

void loop() {

  // Tombol 1 - Maju
  if (digitalRead(button1) == LOW) {
    delay(200);
    if (idx < jumlah - 1) idx++;
    else idx = 0;
    tampilPembalap(idx);
    while (digitalRead(button1) == LOW);
  }

  // Tombol 2 - Mundur
  if (digitalRead(button2) == LOW) {
    delay(200);
    if (idx > 0) idx--;
    else idx = jumlah - 1;
    tampilPembalap(idx);
    while (digitalRead(button2) == LOW);
  }

  // Tombol 3 - Menu Awal
  if (digitalRead(button3) == LOW) {
    delay(200);
    idx = -1;
    tampilMenu();
    while (digitalRead(button3) == LOW);
  }
}

void tampilMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Daftar Nama");
  lcd.setCursor(0, 1);
  lcd.print("Pembalap F1");
}

void tampilPembalap(int i) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tim ");
  lcd.print(tim[i]);
  lcd.setCursor(0, 1);
  lcd.print(pembalap[i]);
}