char getmode()
{  char input;
  Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
  lcd.clear();
  lcd.print("1.RFid");
  lcd.setCursor(0,2);
  lcd.print("2.UserId");
  while(input == NO_KEY)
  {
     input = keypad.getKey(); 
  }
 return input;
 }
