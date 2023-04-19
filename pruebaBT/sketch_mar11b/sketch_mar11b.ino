// ejemplo

#include <SoftwareSerial.h>
SoftwareSerial miBT(2, 3);   //Instancia la conexion al bluetooth - PIN 2 a TX y PIN 3 a RX
String nameBluetooth = "CarBluetooth";
String BPS = "4";
String password = "12345";

// Dato recibido atraves de la aplicacion movil
char data = 'S';


char ddd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Inicia la comunicación en el monitor serial a 9600 Baudios
  miBT.begin(9600); // inicialmente la comunicacion serial a 9600 Baudios (velocidad de convencional)
  miBT.print("AT"); // Inicializa comando AT
  miBT.print("AT+NAME"); // Inicializa comando AT
  miBT.print(nameBluetooth);
  miBT.print("AT+BAUD"); // Configura la nueva velocidad
  miBT.print(BPS);
  miBT.print("AT+PIN"); // Configura en nuevo PIN
  miBT.print(password);
  
  Serial.println("Módulo conectado");
  Serial.println( miBT.print("AT+NAME") );
  Serial.println( miBT.print("AT+BAUD") );
  Serial.println( miBT.print("AT+PIN") );
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println( Serial.read() );

  
  if(Serial.available() > 0){
    ddd = Serial.read();
    Serial.println( ddd );
  }
  delay(500); 
  /*if(miBT.available() > 0){
      //data = miBT.read();
      Serial.println(miBT.read());
      Serial.println( "Ya me conecte =================== " );
    }
    else{
      Serial.println( "No estoy conectado" );
    }*/

    /*if(Serial.available())
      miBT.write(Serial.read());*/
    
}
