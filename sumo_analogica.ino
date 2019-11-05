
#include <Wire.h>
#include <VL53L0X.h>
///PINES DE CONTROL DEL MOTOR
#define IA1 10
#define IB1 9
#define IA2 12
#define IB2 11
//Haremos un control P de la distancia
int distance_thresh1 = 500;
int distance_thresh2=350;
int distance_thresh3=100;
int distance_thresh4=50;
bool laser_status1=false;
bool laser_status2=false;
bool laser_status3=false;
bool laser_status4=false;
char laser_status=0;
int t_push=10;
////////
int black_thresh=100;
int distance = 0;
boolean floor_right=false;
boolean floor_left=false;
boolean floor_status=false;
VL53L0X sensor;

void setup() {
  Wire.begin();
  Serial.begin(9600);//habilito serial para depuracion
  //Configuracion de GPIO
  setup_GPIO();
  sensor.init();
  sensor.setTimeout(500);
  
  ///Vamos a establecer el modo de lectura continua
  sensor.startContinuous();//si quisieramos establecer un intervalo de 100 ms hariamos
  //sensor.startContinuous(100);
  delay(5000);//retraso antes de comenzar de 5 sg
}
void setup_GPIO(){
  pinMode(IA1, OUTPUT);
  pinMode(IB1, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);
  

}
void loop() {
 
  scan_floor();
  if(floor_left==true){
    scan_laser();
   if(laser_status1==false && laser_status2==false && laser_status3==false && laser_status4==false){
    giro_izquierda(20); 
   }else{
    ///CONTROL P
      switch (laser_status){
        case 'A':
          adelante(t_push);
        break;
        case 'B':
          adelante(2*t_push);
        break;
        case 'C':
          adelante(3*t_push);
        break;
        case 'D':
          adelante(4*t_push);
        break;
        case 'E':
          adelante(5*t_push);
        break;
      }
   }
  }
  else{
         atras(500);
  }
}
