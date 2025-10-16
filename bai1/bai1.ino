int listled[]={0,1,2,3,4,5,6,7,8,9};

void setup() {
  for(int i=0;i<10;i++){
    pinMode(listled[i],OUTPUT);
  }
}

void loop() {
  for(int i=0;i<10;i++){
    int ranNum=random(1,11);
    if(ranNum%2==0){
      digitalWrite(listled[i],LOW);

    }else{
      digitalWrite(listled[i],HIGH);
    }
  }
  delay(100);
}
