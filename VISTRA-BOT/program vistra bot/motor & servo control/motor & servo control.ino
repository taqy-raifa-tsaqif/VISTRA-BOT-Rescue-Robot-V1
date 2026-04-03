#include <Ps3Controller.h>
#include <ESP32Servo.h>

// ================= MOTOR =================
int ENA= 13;
int IN1= 12;
int IN2= 14;
int IN3= 27;
int IN4= 26;
int ENB= 25;

// ================= RELAY =================
int relayPin = 22;

// ================= SERVO =================
Servo servoUD;   // atas bawah
Servo servoLR;   // kiri kanan

int servoUDPin = 33;
int servoLRPin = 32;

int posUD = 90;
int posLR = 90;

// ================= JOYSTICK =================
int leftx = 0;
int righty = 0;

// ================= CONNECT =================
void onConnect(){
  Serial.println("PS3 Controller Connected");
}

void setup() {

  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);

  // relay
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  Serial.begin(115200);

  // ================= SERVO SETUP =================
  servoUD.attach(servoUDPin);
  servoLR.attach(servoLRPin);

  servoUD.write(posUD);
  servoLR.write(posLR);

  // ================= PS3 =================
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("0cc:db:a7:96:20:de");
}

// ================= MOTOR FUNCTION =================

void maju() {
digitalWrite (ENA, HIGH);
digitalWrite (IN1, LOW);
digitalWrite (IN2, HIGH);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);
digitalWrite (ENB, HIGH);
}

void mundur() {
digitalWrite (ENA, HIGH);
digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW);
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
digitalWrite (ENB, HIGH);
}

void kanan() {
digitalWrite (ENA, HIGH);
digitalWrite (IN1, LOW);
digitalWrite (IN2, HIGH);

digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
digitalWrite (ENB, HIGH);
}

void kiri() {
digitalWrite (ENA, HIGH);
digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW);

digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);
digitalWrite (ENB, HIGH);
}

void stopMotor() {
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}

// ================= LOOP =================
void loop() {

  righty = Ps3.data.analog.stick.ry;
  leftx  = Ps3.data.analog.stick.lx;

  // ===== MOTOR CONTROL =====
  if (righty <= -50){
    maju();
  }
  else if(righty >= 50){
    mundur ();
  }
  else if(leftx >= 50){
    kiri ();
  }
  else if(leftx <= -50){
    kanan ();
  }
  else{
    stopMotor ();
  }

  // ===== SERVO CONTROL =====

  if(Ps3.data.button.up){
    posUD += 2;
  }
  if(Ps3.data.button.down){
    posUD -= 2;
  }
  if(Ps3.data.button.left){
    posLR += 2;
  }
  if(Ps3.data.button.right){
    posLR -= 2;
  }

  posUD = constrain(posUD, 0, 180);
  posLR = constrain(posLR, 0, 180);
  servoUD.write(posUD);
  servoLR.write(posLR);

  // ===== RELAY CONTROL =====
  if(Ps3.data.button.r2){
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
  }
  // ===== SERIAL DEBUG =====
  Serial.print("LX: ");
  Serial.print(leftx);
  Serial.print("  RY: ");
  Serial.print(righty);
  Serial.print("  ServoUD: ");
  Serial.print(posUD);
  Serial.print("  ServoLR: ");
  Serial.println(posLR);
  delay(20);
}