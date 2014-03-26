#define RP1 5
#define GP1 6
#define BP1 3
#define RP2 10
#define GP2 11
#define BP2 9

String readstring;

void setup() {
  Serial.begin(9600);
  Serial.println("hello world");
  readstring = "";
}

void loop(){
  delay(300);
  while(Serial.available() > 0) {
    char c = Serial.read();
    readstring += c;
    if (c == '\n'){    
      int r1 = readstring.substring(0,3).toInt();
      int g1 = readstring.substring(3,6).toInt();
      int b1 = readstring.substring(6,9).toInt();
      int r2 = readstring.substring(9,12).toInt();
      int g2 = readstring.substring(12,15).toInt();
      int b2 = readstring.substring(15,18).toInt();     
      
      Serial.print("received: (");
      Serial.print(r1);
      Serial.print(", ");
      Serial.print(g1);
      Serial.print(", ");
      Serial.print(b1);
      Serial.print("), (");      
      Serial.print(r2);
      Serial.print(", ");
      Serial.print(g2);
      Serial.print(", ");
      Serial.print(b2);
      Serial.println(")");
      
      analogWrite(RP1, r1);
      analogWrite(GP1, g1);
      analogWrite(BP1, b1);
      analogWrite(RP2, r2);
      analogWrite(GP2, g2);
      analogWrite(BP2, b2);      
      
      readstring = "";
    }
  }
}
  
