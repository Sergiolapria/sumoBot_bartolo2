
void giro_izquierda(int t1){
  digitalWrite(IA1,HIGH);
  digitalWrite(IB1,LOW);
  digitalWrite(IA2,HIGH);
  digitalWrite(IB2,LOW);
  Serial.println("IZQUIERDA");
  delay(t1);
}
void giro_derecha(int t1){
  digitalWrite(IA1,LOW);
  digitalWrite(IB1,HIGH);
  digitalWrite(IA2,LOW);
  digitalWrite(IB2,HIGH);
  Serial.println("DERECHA");
  delay(t1);
}
void atras(int t1){
  digitalWrite(IA1,LOW);
  digitalWrite(IB1,HIGH);
  digitalWrite(IA2,HIGH);
  digitalWrite(IB2,LOW);
  Serial.println("ATRAS");
  delay(t1);
}
void adelante(int t1){
  digitalWrite(IA1,HIGH);
  digitalWrite(IB1,LOW);
  digitalWrite(IA2,LOW);
  digitalWrite(IB2,HIGH);
  Serial.println("ADELANTE");
  delay(t1);
}
void para(){
  digitalWrite(IA1,LOW);
  digitalWrite(IB1,LOW);
  digitalWrite(IA2,LOW);
  digitalWrite(IB2,LOW);
}
