void scan_laser(){
  distance=sensor.readRangeContinuousMillimeters();
  Serial.print("DISTANCE: ");
  Serial.println(distance);
  if (sensor.timeoutOccurred()) {
    adelante(100);
  }
  if(distance>distance_thresh1){
    laser_status='A';
    laser_status1=false;
    laser_status2=false;
    laser_status3=false;
    laser_status4=false;
  }
  if(distance<distance_thresh1 && distance>distance_thresh2){
    laser_status='B';
    laser_status1=true;
    laser_status2=false;
    laser_status3=false;
    laser_status4=false;
  }
  if(distance<distance_thresh2 && distance>distance_thresh3){
    laser_status='C';
    laser_status1=false;
    laser_status2=true;
    laser_status3=false;
    laser_status4=false;
  }
  if(distance<distance_thresh3 && distance>distance_thresh4){
    laser_status='D';
    laser_status1=false;
    laser_status2=false;
    laser_status3=true;
    laser_status4=false;
  }
  if(distance<distance_thresh4){
    laser_status='E';
    laser_status1=false;
    laser_status2=false;
    laser_status3=false;
    laser_status4=true;
  }
}
void scan_floor(){
  int right_value=analogRead(0);//
  int left_value=analogRead(1);//lee bien 
  Serial.print("FLOOR: ");
  Serial.print(right_value);
  Serial.print(" : ");
  Serial.print(left_value); 
  Serial.print(" | ");
  if(right_value<black_thresh){
    floor_left=false;
  }else{
       floor_left=true;
  }
  if(left_value<black_thresh){
    floor_left=false;
  }else{
    floor_left=true;
  }
  Serial.print(floor_left);
  Serial.print(" : ");
  Serial.print(floor_right);
  Serial.print(" | ");
}
