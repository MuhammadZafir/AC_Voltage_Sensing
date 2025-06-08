// Include the library code:
#include <LiquidCrystal.h> // Library for LCD
#include "EmonLib.h"       // Include Emon Library

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

EnergyMonitor emon1; // Create an instance of EnergyMonitor

void setup()
{
  emon1.voltage(A0, 187, 1.7); // Voltage: input pin, calibration, phase_shift

  lcd.begin(20, 4); // Set up the LCD's number of columns and rows
  lcd.setCursor(0, 0);
  lcd.print("  Voltage Measure    ");
  lcd.setCursor(0, 1);
  lcd.print(" Zafir 60B   ");
}

void loop()
{
  emon1.calcVI(20, 2000);          // Calculate all: No. of half wavelengths (crossings), time-out
  float VoltageRMS = emon1.Vrms;   // Extract RMS voltage into a variable
  float VoltagePeak = VoltageRMS * 1.414; // Calculate Peak voltage (Vrms * sqrt(2))

  // Display RMS Voltage
  lcd.setCursor(0, 2);
  lcd.print("RMS Voltage: ");
  lcd.print(VoltageRMS);
  lcd.print("V   ");

  // Display Peak Voltage
  lcd.setCursor(0, 3);
  lcd.print("Peak Voltage: ");
  lcd.print(VoltagePeak);
  lcd.print("V   ");

  delay(1000); // Update every second
}
