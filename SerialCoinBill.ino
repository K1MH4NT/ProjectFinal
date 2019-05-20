//byte x ;
int y;

byte disableCoin[5] = {0x90, 0x05, 0x02, 0x03, 0x9a};
byte in [6];
String stringHexInput[6];
String stringHex;
String coin10 = "9061243af";
String coin11 = "9061263b1";
String coin12 = "9061213ac";
String coin21 = "9061223ad"; //silver
String coin22 = "9061253b0";
String coin5 = "9061233ae";


byte OK = {0x02}; //ok&enablebill
byte disablebill = {0x03}; //setdefaultbill
byte inCoin [2];
String stringHexBillInput[2];
String stringHexBill;
String ackCoin = "90055003e8";
String ackBillDisable = "808f";
String ackBill = "81";
String bill20 = "8140";
String bill50 = "8141";
String bill100 = "8142";

bool isFirstByte = true;

void setup ()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read data from Bill Acceptor
  while (Serial1.available()) {
    in[0] = Serial1.read();
    delay(100);
    stringHexBillInput[0] = String(in[0], HEX);
    Serial.println("stringHexBillInput[0]: " + stringHexBillInput[0]);
    isFirstByte = false;

    if (stringHexBillInput[0].equals("80")) {
      in[1] = Serial1.read();
      delay(100);
      stringHexBillInput[1] = String(in[1], HEX);
      Serial.println("stringHexBillInput[1]: " + stringHexBillInput[1]);

      if (stringHexBillInput[1].equals("8f")) {
        Serial1.write(0x02);
        isFirstByte = true;
      }

    } else if (stringHexBillInput[0].equals("81")) {

      in[1] = Serial1.read();
      delay(100);
      stringHexBillInput[1] = String(in[1], HEX);
      Serial.println("stringHexBillInput[1]: " + stringHexBillInput[1]);

      if (stringHexBillInput[1].equals("40")) {
        Serial1.write(0x02);
        isFirstByte = true;
        Serial.println("20 Baht");
      } else if (stringHexBillInput[1].equals("41")) {
        Serial1.write(0x02);
        isFirstByte = true;
        Serial.println("50 Baht");
      } else if (stringHexBillInput[1].equals("42")) {
        Serial1.write(0x02);
        isFirstByte = true;
        Serial.println("100 Baht");
      }
    }
  }

  // read data from Coin Acceptor
  while (Serial.available()) {

    for (int i = 0; i < 6; i++) {
      in[i] = Serial.read();
      stringHexInput[i] = String(in[i], HEX);
      delay(100);
    }

    stringHex  =  (stringHexInput[0] + stringHexInput[1] + stringHexInput[2] + stringHexInput[3] + stringHexInput[4] + stringHexInput[5]);
    Serial.println("string Coin = " + stringHex);
    if (stringHex.equals(coin11) || stringHex.equals(coin12)) {
      Serial.println("coin 1 Baht");
    } else if (stringHex.equals(coin21) || stringHex.equals(coin22)) {
      Serial.println("coin 2 Baht");
    } else if (stringHex.equals(coin5)) {
      Serial.println("coin 5 Baht");
    } else if (stringHex.equals(coin10)) {
      Serial.println("coin 10 Baht");
    }
  }
}

//void loop()
//{
//  while (Serial1.available()) {
//    do {
//      in[0] = Serial1.read();
//      stringHexBillInput[0] = String(in[0], HEX);
//    } while (!stringHexBillInput[0].equals("80") && !stringHexBillInput[0].equals("81"));
//    Serial.println("stringHexBillInput[0]: " + stringHexBillInput[0]);
//
//    if (stringHexBillInput[0].equals("80")) {
//      do {
//        in[1] = Serial1.read();
//        stringHexBillInput[1] = String(in[1], HEX);
//      } while (stringHexBillInput[1].equals("ff")); bhfgh
//      Serial.println("stringHexBillInput[1]: " + stringHexBillInput[1]);
//
//      if (stringHexBillInput[1].equals("8f")) {
//        Serial1.write(0x02);
//      }
//    } else if (stringHexBillInput[0].equals("81")) {
//      do {
//        in[1] = Serial1.read();
//        stringHexBillInput[1] = String(in[1], HEX);
//      } while (stringHexBillInput[1].equals("ff"));
//      Serial.println("stringHexBillInput[1]: " + stringHexBillInput[1]);
//
//      if (stringHexBillInput[1].equals("40")) {
//        Serial1.write(0x02);
//        Serial.println("20 Baht");
//      } else if (stringHexBillInput[1].equals("41")) {
//        Serial1.write(0x02);
//        Serial.println("50 Baht");
//      } else if (stringHexBillInput[1].equals("42")) {
//        Serial1.write(0x02);
//        Serial.println("100 Baht");
//      }
//    }
//  }
//
//  while (Serial.available()) {
//    for (int i = 0; i < 6; i++) {
//      in[i] = Serial.read();
//      delay(100);
//      stringHexInput[i] = String(in[i], HEX);
//      delay(100);
//    }
//    stringHex  =  (stringHexInput[0] + stringHexInput[1] + stringHexInput[2] + stringHexInput[3] + stringHexInput[4] + stringHexInput[5]);
//    Serial.println("string Coin = " + stringHex);
//    if (stringHex.equals(coin11) || stringHex.equals(coin12)) {
//      Serial.println("coin 1 Baht");
//    } else if (stringHex.equals(coin21) || stringHex.equals(coin22)) {
//      Serial.println("coin 2 Baht");
//    } else if (stringHex.equals(coin5)) {
//      Serial.println("coin 5 Baht");
//    } else if (stringHex.equals(coin10)) {
//      Serial.println("coin 10 Baht");
//    }
//  }
//}


