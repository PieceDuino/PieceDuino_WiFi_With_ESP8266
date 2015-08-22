#include "pieceduino.h"
#define SSID        "Your SSID"
#define PASSWORD    "Your Password"
pieceduino wifi(Serial1);

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  wifi.begin();//初始化
  wifi.reset();//重啟WiFi
  wifi.setWifiMode(2);//將WiFi模組設定為Station模式
  if (wifi.setAP("PieceDuino-AP","",1,0)){
    Serial.println("Create AP Success");
    Serial.print("IP: ");       
    Serial.println(wifi.getIP());
  }else{
    Serial.println("Create AP Failure");
  }

  wifi.enableMUX();//開啟多人連線模式
}

void loop() {
  // put your main code here, to run repeatedly:

}
