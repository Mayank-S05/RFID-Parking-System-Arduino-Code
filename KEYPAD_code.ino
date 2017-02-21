int b=0;
int v=0;
int full=0;
void getkeys()
{
  v=0;
  Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
  lcd.clear();
  lcd.write("Enter Six ");
  lcd.setCursor(0,2);
  lcd.write("Bit UserID...");
  delay(3000);
  int i=0;
  int y=0;
  int c=0,count=0,s=0;
  char customKey;
  int dummy[5];  
  lcd.clear();

 if(b==0){  
  for(int y =0 ;y<6;y++)
  {
    dummy[y]=0;
    for(int h=0;h<6;h++)
    {
      keys[y][h]=0; 
    }
  }
  b++;
  }
    while(i<6)
    {
    while(customKey == NO_KEY)
    {
      customKey = keypad.getKey();
    }
    
    if(customKey != NO_KEY)
    {
    dummy[i]=customKey-'0';
    int e = customKey-'0';
    Serial.println(e);
    lcd.write(customKey);
    }
    i++;
  customKey = NO_KEY;
  }   
 int u=0;
 int o=0;
  for(int i=keys[c][0];i!=0;)
  {
    count=0;
    s=0;
    while(s<6)
    { 
      if(keys[c][s]==dummy[s])
       count++;
       s++; 
    }
  if(count==6)
  { 
   
    u=1;
    o=c;
    i=0;
  }  
  else
  { 
    i=keys[++c][0];
    u=0;
  }
}
    if(u==0)
      {
      
      q++;
      full++;
      s=0;
      while(s<6)
      {
      keys[q-1][s]=dummy[s];
      
      Serial.print("\nkeys is ");
      Serial.print(keys[q-1][s]);
      s++;
      }
      Serial.print(q);
      start[full-1]=millis();
      lcd.clear();
      lcd.print("You Are Now");
      lcd.setCursor(0,1);
      lcd.print("Registered!!");
      delay(2000);
      lcd.clear();
      lcd.print("Welcome!!"); 
      
      digitalWrite(A2,HIGH); 
      delay(500);
      digitalWrite(A2,LOW); 
     
      }
      
  if(u==1)
 {
  Serial.print("\n to delete row");
  Serial.print(q);
  y=1;    
  }
 int f=o+1;
 if(y==1)
 { 
   Serial.print("\nshifting\n");
   Serial.print("\nO is ");
   Serial.print(o);
   int m=0;
   while(keys[f][0]!=0)
    { v++;
      m=0;
      Serial.print("\bf before edit is : ");
      Serial.print(f);
    while(m<6)
    {
        keys[f-1][m]=keys[f][m];
        m++;
    }
  f++;
  }
 
  
    ending[full-v-1]=millis();
    unsigned long int ellapsed = ending[full-v-1] - start[full-v-1] ; 
    showTime(ellapsed);
    int rate = deductbalance(ellapsed,0);
    lcd.clear();
    lcd.print("You Were Charged");
    lcd.setCursor(0,1);
    lcd.print(rate);
    lcd.print("Rupees");
    delay(3000);
    lcd.clear();
    lcd.print("Thank You!!");
    q=q-1;
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW);
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW);
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW);
    for(int j=0;j<6;j++)
      keys[f-1][j]=0; 
 }  
 for(int j=0;j<6;j++)
  { Serial.print("\nkeys : ");
  for(int k=0;k<6;k++)
    { 
      Serial.print(keys[j][k]);
      Serial.print("   ");
    }
  }
}
