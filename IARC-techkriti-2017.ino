
int a1 = A5, a2 = A4, a3 = A3, a4 = A2, a5 = A1, a6 = A0, rm1 = 3, rm2 = 5, lm2 = 10, lm1 = 9;
int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 11;
int echoPin2 = 12;
long duration1, duration2;
float distance1, distance2;
int n = 0, m = 0,k=0;

void ir_sensor()
{
  int a, b, c, d, e, f;
  a = analogRead(a1);
  b = analogRead(a2);
  c = analogRead(a3);
  d = analogRead(a4);
  e = analogRead(a5);
  f = analogRead(a6);

}

void left_move()
{
  analogWrite(rm1, 180);
  analogWrite(rm2, 0);
  analogWrite(lm1, 130);
  analogWrite(lm2, 0);
}


void right_move()
{

  analogWrite(rm1, 130);
  analogWrite(rm2, 0);
  analogWrite(lm1, 180);
  analogWrite(lm2, 0);
}

void stops()
{
   analogWrite(rm1, 0);
  analogWrite(rm2, 0);
  analogWrite(lm1, 0);
  analogWrite(lm2, 0);
}

void left_turn()
{

  analogWrite(rm1, 150);
  analogWrite(rm2, 0);
  analogWrite(lm1, 0);
  analogWrite(lm2, 0);
}

void right_turn()
{
  analogWrite(rm1, 0);
  analogWrite(rm2, 0);
  analogWrite(lm1, 150);
  analogWrite(lm2, 0);
}

void straight()
{
  analogWrite(rm1, 192);
  analogWrite(rm2, 0);
  analogWrite(lm1, 180);
  analogWrite(lm2, 0);
}


void setup() {
  
 
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  
  
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A0, INPUT);
  pinMode(rm1, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop()
{
 while (1)
  {
    int a, b, c, d, e, f;
    a = analogRead(a1);
    Serial.print(a);
    Serial.print("\t");
    b = analogRead(a2);
    Serial.print(b);
    Serial.print("\t");
    c = analogRead(a3);
    Serial.print(c);
    Serial.print("\t");
    d = analogRead(a4);
    Serial.print(d);
    Serial.print("\t");
    e = analogRead(a5);
    Serial.print(e);
    Serial.print("\t");
    f = analogRead(a6);
    Serial.print(f);
    Serial.print("\t");
    Serial.print("\n");
    

  

    //line only on left side so turn left
    if (((a < 500 && b < 500 && c < 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c < 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b < 500 && c > 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b < 500 && c < 500 && d < 500 && e < 500 && f > 500) || (a < 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500) || (a < 500 && b < 500 && c < 500 && d > 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c > 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500))&&m==1)
    {
      if ((a < 500 && b < 500 && c < 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c < 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b < 500 && c > 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b < 500 && c < 500 && d < 500 && e < 500 && f > 500) || (a < 500 && b < 500 && c < 500 && d < 500 && e < 500 && f > 500) || (a < 500 && b < 500 && c < 500 && d > 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c > 500 && d < 500 && e > 500 && f > 500) || (a < 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500))
      {   analogWrite(rm1, 105);
        analogWrite(rm2, 0);
        analogWrite(lm1, 105);
        analogWrite(lm2, 0);
        delay(40);
        left_turn();
        delay(200);
      
        ir_sensor();
        while (1)
        {
          if (analogRead(A3) < 500)
            break;
          left_turn();
        }
        right_turn();
        delay(70);
      

        if ((analogRead(A5) < 500) || ( analogRead(A5) < 500 && analogRead(A4) < 500) || ( analogRead(A0) < 500))
          break;
          right_turn();
    
        
    straight();
        a = analogRead(a1);
  b = analogRead(a2);
  c = analogRead(a3);
  d = analogRead(a4);
  e = analogRead(a5);
  f = analogRead(a6);
 a = analogRead(a1);
  b = analogRead(a2);
  c = analogRead(a3);
  d = analogRead(a4);
  e = analogRead(a5);
  f = analogRead(a6);

      }
    }


    ir_sensor();

      if (a > 500 && b > 500 && c < 500 && d < 500 && e > 500 && f > 500)
    {
      straight();
      m = 1;
    }

    //right move
    if ((a > 500 && b > 500 && c < 500 && d < 500 && e < 500 && f > 500) || (a > 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500) )
    {
      right_move();
      m = 1;
    }


    //left move
    if ((a > 500 && b < 500 && c < 500 && d < 500 && e > 500 && f > 500) || (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f > 500) )
    {
      left_move();
      m = 1;
    }

    if((a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500))
    {
      analogWrite(rm1,220);
      analogWrite(rm2,0);
      analogWrite(lm1,160);
      analogWrite(lm2,0);
    }

    if( (a > 500 && b > 500 && c > 500 && d < 500 && e > 500 && f > 500))
    {
       analogWrite(rm1,170);
      analogWrite(rm2,0);
      analogWrite(lm1,200);
      analogWrite(lm2,0);
    }

    //line only on right side so first go straight and check
    if ((a > 500 && b > 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d > 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d < 500 && e > 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f < 500) || (a > 500 && b > 500 && c > 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c > 500 && d < 500 && e > 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f < 500))
    {
      if ((a > 500 && b > 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d > 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d < 500 && e > 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f < 500) || (a > 500 && b > 500 && c > 500 && d < 500 && e < 500 && f < 500) || (a > 500 && b > 500 && c > 500 && d < 500 && e > 500 && f < 500) || (a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f < 500) || (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f < 500))
      {
        analogWrite(rm1, 105);
        analogWrite(rm2, 0);
        analogWrite(lm1, 105);
        analogWrite(lm2, 0);
        delay(40);


        m = 2;

        if (analogRead(A0) < 500)
        {
          left_turn();
          delay(180);

          ir_sensor();
          while (1)
          {
            if (analogRead(A3) < 500)
              break;
            left_turn();
          }
          right_turn();
          delay(70);
          straight();
          
          right_turn();
          m = 0;




          if ((analogRead(A5) < 500) || ( analogRead(A5) < 500 && analogRead(A4) < 500) || ( analogRead(A0) < 500))
            break;
          m = 0;
        }


        else if (analogRead(A2) < 500 || analogRead(A3) < 500)
        {
          straight();
          
         
        }
        else
        {
          while (1)
          {
            if (analogRead(A2) < 500)
              break;
            right_turn();
          }
          left_turn();
          delay(90);
          m = 0;
        
        }

      }
    }

if(m==2&&a>500&&b>500&&c>500&&d>500&&e>500&&f>500)
{
   while (1)
          {
            if (analogRead(A2) < 500)
              break;
            right_turn();
          }
          left_turn();
          delay(90);
          m = 0;
}

    //all on black so turn left
    if ((a < 500 && b < 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a < 500 && b < 500 && c < 500 && d < 500 && e > 500 && f < 500) || (a < 500 && b > 500 && c < 500 && d < 500 && e < 500 && f < 500) || (a < 500 && b > 500 && c < 500 && d < 500 && e > 500 && f < 500) || (a < 500 && b < 500 && c < 500 && d < 500 && e < 500 && f > 500))
    {
      analogWrite(rm1, 105);
      analogWrite(rm2, 0);
      analogWrite(lm1, 105);
      analogWrite(lm2, 0);
      delay(40);
      left_turn();
      delay(360);

      while (1)
      {
        if (analogRead(A3) < 500)
          break;
        left_turn();
      }
      right_turn();
      delay(25);
  
      straight();
     
          if ((analogRead(A5) < 500) || ( analogRead(A5) < 500 && analogRead(A4) < 500) || ( analogRead(A0) < 500))
            break;
    }

      


   
    if ((a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && m != 0&&m!=2))
    {
      stops();
      delay(10);
    analogWrite(rm1, 105);
      analogWrite(rm2, 0);
      analogWrite(lm1, 105);
      analogWrite(lm2, 0);
      delay(40);
      while (1)
      {
        if (analogRead(A3) < 500)
          break;
        analogWrite(rm1, 100);
        analogWrite(rm2, 0);
        analogWrite(lm1, 0);
        analogWrite(lm2, 100);
      }
      right_turn();
      delay(60);
    }
  }

 right_turn();
 delay(150);

 stops();
 delay(100);

  while (1)
  {
    float t;
    float distance1, distance2, duration1, duration2;
    int a, b, c, d, e, f;
    

    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1 * 0.034 / 2;

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2 * 0.034 / 2;


    Serial.print("distance1");
    Serial.println(distance1);
    Serial.print("distance2");
    Serial.println(distance2);
    Serial.print("\n");


    if (distance1 > 14 & distance1 < 20 && distance2 > 22 && n > 0)
    {
      t = 150 - (distance1 - 12) * 10;
      analogWrite(rm1, 150);
      analogWrite(rm2, 0);
      analogWrite(lm1, t);
      analogWrite(lm2, 0);
      
    }
    if (distance1 < 14 && distance1 > 8 && distance2 > 22 && n > 0)
    {
      t = 150 - (12 - distance1) * 10;
      analogWrite(rm1, t);
      analogWrite(rm2, 0);
      analogWrite(lm1, 150);
      analogWrite(lm2, 0);
      
    }

    if (distance1 == 14 && distance2 > 22 && n > 0)
    {

      analogWrite(rm1, 150);
      analogWrite(rm2, 0);
      analogWrite(lm1, 150);
      analogWrite(lm2, 0);
      
    }

    if (distance1 >= 32 && distance1 < 80 && distance2 > 23 && n > 0)
    {
      analogWrite(rm1, 95);
      analogWrite(rm2, 0);
      analogWrite(lm1, 105);
      analogWrite(lm2, 0);
      delay(350);
      a = analogRead(a1);
      b = analogRead(a2);
      c = analogRead(a3);
      d = analogRead(a4);
      e = analogRead(a5);
      f = analogRead(a6);
      if (a < 500 || b < 500 || c < 500 || d < 500 || e < 500 || f < 500)
       break; 
      analogWrite(rm1, 70);
      analogWrite(rm2, 0);
      analogWrite(lm1, 0);
      analogWrite(lm2, 0);
      delay(1150);
      analogWrite(rm1, 100);
      analogWrite(rm2, 0);
      analogWrite(lm1, 100);
      analogWrite(lm2, 0);
      delay(500);
      
    }


    if (distance2 < 22 && distance2 > 10 && n > 0)
    {
      analogWrite(rm1, 0);
      analogWrite(rm2, 0);
      analogWrite(lm1, 70);
      analogWrite(lm2, 0);
      delay(970);
      
    }

    if (n == 0)
    {
      analogWrite(rm1, 0);
      analogWrite(rm2, 0);
      analogWrite(lm1, 0);
      analogWrite(lm2, 0);
      
    }

    if (distance2 < 10 && distance2!=0 && n > 0)
    {
      analogWrite(rm1, 0);
      analogWrite(rm2, 70);
      analogWrite(lm1,0);
      analogWrite(lm2, 70);
      delay(1200);
      
    }
    if (distance1 > 80)
    {
      analogWrite(rm1, 80);
      analogWrite(rm2, 0);
      analogWrite(lm1, 50);
      analogWrite(lm2, 0);
      
    }

    if (distance1 < 8 && distance2 > 20)
    { analogWrite(rm1, 60);
      analogWrite(rm2, 0);
      analogWrite(lm1, 90);
      analogWrite(lm2, 0);
      
    }

    if (distance1 > 20 && distance1 < 33 && distance2 > 24)
    { analogWrite(rm1, 41);
      analogWrite(rm2, 0);
      analogWrite(lm1, 30);
      analogWrite(lm2, 0);
     
       digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2 * 0.034 / 2;

    }
 
    n = 2;
  }
  n=0;m=0;
k=0;
 while(1)
  {
  int a, b, c, d, e, f;

  a = analogRead(a1);
  Serial.print(a);
  Serial.print("\t");
  b = analogRead(a2);
  Serial.print(b);
  Serial.print("\t");
  c = analogRead(a3);
  Serial.print(c);
  Serial.print("\t");
  d = analogRead(a4);
  Serial.print(d);
  Serial.print("\t");
  e = analogRead(a5);
  Serial.print(e);
  Serial.print("\t");
  f = analogRead(a6);
  Serial.print(f);
  Serial.print("\t");
  float distance1, distance2, duration1, duration2, t;

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(1);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(1);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;


  Serial.print("distance1");
  Serial.println(distance1);
  Serial.print("distance2");
  Serial.println(distance2);
  Serial.print("\n");

  if (a > 500 && b > 500 && c < 500 && d < 500 && e > 500 && e > 500 && distance1 > 16)
  {
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 51.3);
    analogWrite(lm2, 0);
    m = 1;
    n=0;
  }

  ir_sensor();

  if (a > 500 && b < 500 && c < 500 && d < 500 && e > 500 && f > 500 && distance1 > 16)
  {
    analogWrite(rm1, 100);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    delay(15);
    m = 2;
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    n=0;
  }

  if (a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f > 500 && distance1 > 16)
  {
    analogWrite(rm1, 100);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    delay(50);
      analogWrite(rm1, 0);
    analogWrite(rm2, 0);
    analogWrite(lm1, 100);
    analogWrite(lm2, 0);
    delay(20);
    m = 2;
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    n = 0;
  }

  ir_sensor();

  if (a > 500 && b > 500 && c < 500 && d < 500 && e < 500 && f > 500 && distance1 > 16)
  {
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 100);
    analogWrite(lm2, 0);
    delay(15);
    m = 3;
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    n=0;
  }

  if (a > 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500 && distance1 > 16)
  {
    analogWrite(rm1, 40);
    analogWrite(rm2, 0);
    analogWrite(lm1, 100);
    analogWrite(lm2, 0);
    delay(70);
      analogWrite(rm1, 0);
    analogWrite(rm2, 0);
    analogWrite(lm1, 100);
    analogWrite(lm2, 0);
    delay(20);
    m = 3;
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 50);
    analogWrite(lm2, 0);
    n=0;
  }

  ir_sensor();

  if (distance2 < 15&& distance2>8 && (m == 1 || m == 2 || m == 3))
  {
    analogWrite(rm1, 0);
    analogWrite(rm2, 0);
    analogWrite(lm1, 70);
    analogWrite(lm2, 0);
    delay(850);
     k++;
    
    //lcd.print(k);
    m = 4;
  }

 if (distance2 < 15&&distance2>8 &&(m == 1 || m == 2 || m == 3))
  {
    analogWrite(rm1, 0);
    analogWrite(rm2, 70);
    analogWrite(lm1, 0);
    analogWrite(lm2, 70);
    delay(1000);
    
  }

if (distance2 < 8&& (m == 1 || m == 2 || m == 3))
  {
    analogWrite(rm1, 0);
    analogWrite(rm2, 70);
    analogWrite(lm1, 0);
    analogWrite(lm2, 70);
    delay(1000);
  }

  if (a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 == 5)
  {
    analogWrite(rm1, 60);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
  }


  if (a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 5 && distance1 < 10)
  {
    analogWrite(rm1, 70);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
  }

  if (a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 10 && distance1 < 20)
  {
    analogWrite(rm1, 80);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
  }

  if (a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 < 5)
  {
    analogWrite(rm1, 50);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
  }

  if (a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 4 && n < 2)
  {

    analogWrite(rm1, 60);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
    delay(270);
    analogWrite(rm1, 70);
    analogWrite(rm2, 0);
    analogWrite(lm1, 0);
    analogWrite(lm2, 0);
    delay(1060);
    analogWrite(rm1, 60);
    analogWrite(rm2, 0);
    analogWrite(lm1, 60);
    analogWrite(lm2, 0);
    delay(180);
    n++;
  }

  if (a<500||f<500)
  {
    while(1)
    {
      if(analogRead(A0)>500&&analogRead(A5)>500)
      break;
     else
     {analogWrite(rm1, 0);
        analogWrite(rm2, 0);
        analogWrite(lm1, 60);
        analogWrite(lm2, 0);
    }
    }
    while (1)
    {
      if (analogRead(A2) < 500)
        break;
      else
      {
        analogWrite(rm1, 0);
        analogWrite(rm2, 0);
        analogWrite(lm1, 60);
        analogWrite(lm2, 0);
        n=0;
        m=0;
      }
         
    }
     analogWrite(rm1, 130);
        analogWrite(rm2, 0);
        analogWrite(lm1, 120);
        analogWrite(lm2, 0);
        
        analogWrite(rm1, 70);
        analogWrite(rm2, 0);
        analogWrite(lm1, 60);
        analogWrite(lm2, 0);
        n=0;
      
  }

  if ((a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 1) || (a > 500 && b > 500 && c > 500 && d > 500 && e < 500 && f > 500 && distance1 > 20 && m == 1) || (a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 1) || (a > 500 && b < 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 1))
  {
    analogWrite(rm1, 134);
    analogWrite(rm2, 0);
    analogWrite(lm1, 130);
    analogWrite(lm2, 0);
    n = 4;
  }

  if ((a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 2) || (a > 500 && b > 500 && c > 500 && d > 500 && e < 500 && f > 500 && distance1 > 20 && m == 2) || (a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 2) || (a > 500 && b < 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 2))
  {
    analogWrite(rm1, 136);
    analogWrite(rm2, 0);
    analogWrite(lm1, 130);
    analogWrite(lm2, 0);
    n = 4;
  }

  if ((a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 3) || (a > 500 && b > 500 && c > 500 && d > 500 && e < 500 && f > 500 && distance1 > 20 && m == 3) || (a > 500 && b > 500 && c < 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 3) || (a > 500 && b < 500 && c > 500 && d > 500 && e > 500 && f > 500 && distance1 > 20 && m == 3))
  {
    analogWrite(rm1, 134);
    analogWrite(rm2, 0);
    analogWrite(lm1, 130);
    analogWrite(lm2, 0);
    n = 4;
  }

  if(n==4&&(a<500||b<500||c<500||d<500||e<500||f<500))
  break;
 }

while(1)
{
   int a, b, c, d, e, f;
  a = analogRead(a1);
  b = analogRead(a2);
  c = analogRead(a3);
  d = analogRead(a4);
  e = analogRead(a5);
  f = analogRead(a6);

  if((a > 500 && b > 500 && c < 500 && d < 500 && e > 500 && f > 500))
  straight();

  if((a > 500 && b < 500 && c < 500 && d < 500 && e > 500 && f > 500)||(a > 500 && b < 500 && c < 500 && d > 500 && e > 500 && f > 500)||(a < 500 && b < 500 && c > 500 && d > 500 && e > 500 && f > 500)||(a < 500 && b > 500 && c > 500 && d > 500 && e > 500 && f > 500))
  left_move();

  if((a > 500 && b > 500 && c < 500 && d < 500 && e < 500 && f > 500)||(a > 500 && b > 500 && c > 500 && d < 500 && e < 500 && f > 500)||(a > 500 && b > 500 && c > 500 && d > 500 && e < 500 && f < 500)||(a > 500 && b > 500 && c > 500 && d > 500 && e > 500 && f < 500))
  right_move();

  if(a<500&&b<500&&c<500&&d<500&&e<500&&f<500)
  {stops();
  break;}
}

digitalWrite(13,HIGH);
delay(4000);
}
