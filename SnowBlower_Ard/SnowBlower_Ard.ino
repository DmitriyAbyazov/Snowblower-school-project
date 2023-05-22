/* Необходимые пины */
int Right_motor_pwm=9;
int Right_motor_1=8;
int Right_motor_0=7;
int Left_motor_pwm=5;
int Left_motor_1=6;
int Left_motor_0=4;

void forward()  //Вперёд
{
    digitalWrite(Right_motor_0,LOW);
    digitalWrite(Right_motor_1,HIGH);
  
    digitalWrite(Left_motor_0,LOW);
    digitalWrite(Left_motor_1,HIGH);
}

void left()  //Влево
{
    digitalWrite(Right_motor_0,LOW);
    digitalWrite(Right_motor_1,HIGH);
  
    digitalWrite(Left_motor_0,LOW);
    digitalWrite(Left_motor_1,LOW);
}

void right()  //Вправо
{
    digitalWrite(Right_motor_0,LOW);
    digitalWrite(Right_motor_1,LOW);
  
    digitalWrite(Left_motor_0,LOW);
    digitalWrite(Left_motor_1,HIGH);
}

void back()  //Назад
{
    digitalWrite(Right_motor_1,LOW);
    digitalWrite(Right_motor_0,HIGH);
  
    digitalWrite(Left_motor_1,LOW);
    digitalWrite(Left_motor_0,HIGH);
}

void brake()  //Остановка движения
{
    digitalWrite(Right_motor_0,LOW);
    digitalWrite(Right_motor_1,LOW);

    digitalWrite(Left_motor_0,LOW);
    digitalWrite(Left_motor_1,LOW);
}

void setup() 
{
    /* Подключаем пины */
    Serial.begin(115200);
    pinMode(Left_motor_0,OUTPUT);
    pinMode(Left_motor_pwm,OUTPUT);
    pinMode(Left_motor_1, OUTPUT);
    pinMode(Right_motor_pwm,OUTPUT);
    pinMode(Right_motor_0,OUTPUT);
    pinMode(Right_motor_1,OUTPUT);
  
    digitalWrite(Right_motor_pwm, HIGH);
    digitalWrite(Left_motor_pwm, HIGH);
  
    //forward();
}

void loop() 
{
    while(Serial.available())
    {
      char com = Serial.read();
      switch (com)
      {
        case 'f':
          forward();
          break;
        case 'l':
          left();
          break;
        case 'r':
          right();
          break;
        case 'b':
          back();
          break;
        case 's':
          brake();
          break;
        default:
          break;
      }
    }
}
