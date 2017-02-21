int h=0;
void readid()
{
  h=0;
 if(s==0)
 {
   while(p<10)
  {
    a[p]="";
    p++;  
  }
  s++;
 }
    int l=0,j=0,c=0,k=0,x=0,f=0,m=0,flag=0;
    p=0;
    while(a[p]!= "")
  {
      p++;
      x++;
  }
  //TO SEARCH IF SCANNED CARD IS PRESENT OR NOT
   for(k=0;a[k]!="";k++)
  { 
    if(a[k]==code)
     c=1;  
  }
  k=0;
  
  if(c==1)
  {
    g--;
  while(a[l]!= "")
  {
  if(a[l]==code)
  { 
   lcd.clear();
   int j=0;
   for(j=0;j<4;j++) 
   {
     if(balance[j]==code)
       {
        ending1[j]=millis();
        break;  
       }        
   }
      Serial.print("ending is : ");
      Serial.print(ending1[j]);
 unsigned long int ellapsed = ending1[j] - start1[j]; 
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
 lcd.clear();
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW);
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW);
 //digitalWrite(A2,HIGH);
 //digitalWrite(A2,LOW); 
 flag=1;
 a[l]="";
 f=l;
 x--;
  }
 l++;  
}
  l=f;
  k=f+1;
 }
 
  if(flag==1)
{  
  while(a[k]!="")
  {
    a[l]=a[k];
    k++;
    l++;
    h++;
  }
  a[l]="";
}
  
  
  if(c==0)
  {
   a[p]=code;
   lcd.clear(); 
   lcd.print("Checking Balance..."); 
   if(!checkbalance())
  {     
    for(int j=0;j<4;j++)
    {
    Serial.print("\nbalance is : ");
    Serial.print(balance[j]);
    }
     for(int j=0;j<4;j++)
    {
    Serial.print("\namount lest is : ");
    Serial.print(amt[j]);
    }  
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("LOW BALANCE!!");
  delay(2000);
  addbalance();
  }
  else
  {
    for(int j=0;j<4;j++)
    {
    Serial.print("\namount lest is : ");
    Serial.print(amt[j]);
    }
   delay(2000); 
   lcd.setCursor(0,1);
   lcd.print("SUFFICIENT BALANCE!!");
   delay(2000);
  }
  
  for(int j=0;j<4;j++)
    { 
      if(balance[j]==code)
      start1[j]=millis();  
    }
    Serial.print("Starting is : ");
    Serial.print(start1[j]);
    m=1;
    lcd.clear();
    lcd.print("You Are Exisitng");
    lcd.setCursor(0,1);
    lcd.print("User!!");   
    lcd.clear();
   lcd.print("Welcome!!");
 
   digitalWrite(A2,HIGH);
   delay(500); 
   digitalWrite(A2,LOW);

   delay(3000);  
    int w=0;
    while(w<=4)
  {
      Serial.print("\nARRAY : "); 
      Serial.print(a[w]);
      w++;
  }
 }
}  

