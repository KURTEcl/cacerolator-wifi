#include <ESP8266WiFi.h> 
#include <Servo.h>

const char * ssid = ""; // Nombre SSID
const char * password = ""; // Contraseña

WiFiServer server(80);

Servo motor1;
int grados1 = 0;
int estado = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectada");

  server.begin();
  Serial.println("Servidor inicializado");

  Serial.printf("\n\nUtiliza esta URL para conectar: http://%s/\n", WiFi.localIP().toString().c_str());

  Serial.println("Conectando motor");
  motor1.attach(D7);
}

void loop() {

  if (estado == 1) {
    grados1 = 20;
    motor1.write(grados1);
    delay(100);

    grados1 = 0;
    motor1.write(grados1);
    delay(400);

    grados1 = 20;
    motor1.write(grados1);
    delay(100);

    grados1 = 0;
    motor1.write(grados1);
    delay(420);

    grados1 = 20;
    motor1.write(grados1);
    delay(150);

    grados1 = 0;
    motor1.write(grados1);
    delay(100);

    grados1 = 20;
    motor1.write(grados1);
    delay(150);

    grados1 = 0;
    motor1.write(grados1);
    delay(100);

    grados1 = 20;
    motor1.write(grados1);
    delay(150);

    grados1 = 0;
    motor1.write(grados1);
    delay(400);
  }


  WiFiClient client = server.available();
  if (!client) {
    return;
  }


  //Serial.println("nuevo cliente");
  while (!client.available()) {
    delay(1);
  }


  String peticion = client.readStringUntil('\r');
  Serial.println(peticion);
  client.flush();
  
  if (peticion.indexOf('/ON') != -1) {
    estado = 0;
  }
  if (peticion.indexOf('/OFF') != -1) {
    estado = 1;
  }


  client.println("HTTP/1.1 200 OK");
  client.println("");
  client.println("");
  client.println("");
  client.println("<html><head></head><body>");

  client.print("<h1 align=center>CACEROLATOR");

  if (estado == 1) {
    client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/ON'>");
  } else {
    client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/OFF'>");
  }

  client.println("</body></html>");
  delay(1);
  Serial.println("Peticion finalizada"); // Se finaliza la petición al cliente. Se inicializa la espera de una nueva petición.

}
