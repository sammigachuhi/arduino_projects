#include <WiFi.h>
#include <time.h>
#include <LiquidCrystal.h>

// --- YOUR WIFI CREDENTIALS ---
const char* ssid = "xxx";
const char* password = "xxx";

// --- NTP SERVER & KENYA TIMEZONE SETTINGS ---
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 10800;  // UTC+3 (Kenya)
const int daylightOffset_sec = 0;  // 0 for Kenya

// --- LCD PINS (Direct Parallel Mode) ---
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

// --- LED ALARM PIN ---
const int ledPin = 13;

// --- ALARM TIME SETTINGS (24-Hour Format) ---
const int alarmHour = 13;    // Set your target alarm hour (0-23)
const int alarmMinute = 10;  // Set your target alarm minute (0-59)

// Alarm state tracking variables
bool alarmTriggered = false;
unsigned long alarmStartTime = 0;
unsigned long lastBlinkTime = 0;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Ensure LED is off at startup

  // 1. Connect to Wi-Fi
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    lcd.print(".");
    attempts++;
  }

  lcd.clear();
  if (WiFi.status() == WL_CONNECTED) {
    lcd.setCursor(0, 0);
    lcd.print("WiFi Connected!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("WiFi Failed :(");
  }
  delay(2000);
  lcd.clear();

  // 2. Initialize and sync time via NTP server
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  unsigned long currentMillis = millis();

  // Pull current local time from system struct
  if (!getLocalTime(&timeinfo)) {
    lcd.setCursor(0, 0);
    lcd.print("Syncing Time... ");
    delay(1000);
    return;
  }

  // 3. Check if current time matches the alarm time
  if (!alarmTriggered && timeinfo.tm_hour == alarmHour && timeinfo.tm_min == alarmMinute) {
    alarmTriggered = true;
    alarmStartTime = currentMillis;  // Record when the alarm started
  }

  // 4. Handle Alarm Behavior (Incessant blinking for 1 minute = 60,000 ms)
  if (alarmTriggered) {
    if (currentMillis - alarmStartTime < 60000) {
      // Toggle LED every 200ms for a rapid, incessant flashing alarm effect
      if (currentMillis - lastBlinkTime >= 200) {
        lastBlinkTime = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState ? HIGH : LOW);
      }
    } else {
      // 1 minute is up! Stop alarm and turn off LED
      alarmTriggered = false;
      digitalWrite(ledPin, LOW);
    }

    // Display Alert on Row 1 during alarm
    lcd.setCursor(0, 1);
    lcd.print(">>> ALARM! <<<  ");
  } else {
    // Display set alarm target on Row 1 during normal operation
    lcd.setCursor(0, 1);
    lcd.print("Alarm: ");
    if (alarmHour < 10) lcd.print("0");
    lcd.print(alarmHour);
    lcd.print(":");
    if (alarmMinute < 10) lcd.print("0");
    lcd.print(alarmMinute);
    lcd.print("     ");
  }

  // 5. Display Live 24-Hour Clock Time on Row 0
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  char timeBuffer[9];
  sprintf(timeBuffer, "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  lcd.print(timeBuffer);

  delay(200);  // Small loop refresh delay
}
