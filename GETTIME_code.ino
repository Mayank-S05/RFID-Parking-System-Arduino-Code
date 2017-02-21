void showTime(unsigned long int t)
{
  int hr = ((t/3600000)%24);
  int mins=((t/60000)%60);
  int sec=((t/1000)%60); 
    lcd.clear();
    lcd.print("Parking Time : ");
    lcd.setCursor(0,1);
    if(hr!=0)
    {
      lcd.print(hr);
      lcd.print("Hours ");
    }
    lcd.print(mins);
    lcd.print("Mins "); 
    lcd.print(sec);
    lcd.print("sec");
 delay(2000);
 } 
