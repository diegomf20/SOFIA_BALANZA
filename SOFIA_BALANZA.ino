String data[2];

void setup()
{
  Serial.begin(9600);
}

int contar=0;
void loop()
{
    while (Serial.available())
    {
        String bufferData=String(Serial.read(),HEX);
        if(bufferData=="ff"){ 
          contar=0; 
        }
        if(contar==2){
          data[1]=bufferData;
            
        }else if(contar==3){
          data[0]=bufferData;
          String peso=data[0]+data[1];
          Serial.println(peso);
        }
        contar++;
    }
}
