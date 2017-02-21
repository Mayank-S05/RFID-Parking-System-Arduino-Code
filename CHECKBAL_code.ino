bool checkbalance()
{
  int y=0;
  while(y<=balid)
  {
 if(balance[y]==code)
  {
    if(amt[y]>=50)
    return true;
    else
    return false;
  }
 
 else if(y==balid)
  { 
    balance[balid] = code; 
    balid++;
    return false;
  }
  y++;
  }  
}

void addbalance()
{ int y=0;
  int z=0;
  int d=100;
 Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 lcd.clear();
 lcd.print("Enter The Recharge");
 lcd.setCursor(0,1); 
 lcd.print("Amount>99");
 delay(3000);
 lcd.clear();
 lcd.print("Rupee: ");
 char customKey;
 int i=0;
 while(balance[y]!=code)
 y++;
 while(i<3)
    {
      while(customKey == NO_KEY)
    {
      customKey = keypad.getKey();
    }
    
    if(customKey != NO_KEY)
    {
      int r = (customKey - '0');
      z = (r*d) + z;
      d=d/10;
    }
    Serial.println(customKey);
    lcd.write(customKey);
    i++;
  customKey = NO_KEY;
   }
  amt[y]+=z;

 for(int j=0;j<4;j++)
    {
    Serial.print("\n amount left is : ");
    Serial.print(amt[j]);
    }  
}

int deductbalance(unsigned long int t,int x=1)
{ int y=0;
  int sec=((t/1000));
  int rate = sec/2;
    for(int j=0;j<4;j++)
    {
    Serial.print("\nbalance is : ");
    Serial.print(balance[j]);
    }
    for(int j=0;j<4;j++)
    {
    Serial.print("\n amount left is : ");
    Serial.print(amt[j]);
    }  
    if(x==1)
   {
    while(balance[y]!=code)
    y++;  
  amt[y] = amt[y]-rate;
   }
   else if(x==0)
   return rate;
}
