/*
  Programa para manejar el robot Tatu-bot de Futhur Tech
 */
#include "tatubot.h"
#include "SoftwareSerial.h"
Robot tatubot;



void setup(){
  Serial.begin(9600);
  tatubot.iniciar();
  tatubot.despertar();
}

void loop(){
  //   tatubot.estoyEnBtStandBy = false;
  if (digitalRead(PIN_INICIO_ORDENES) == LOW) {
    Serial.print("Escuchando ordenes \n");
    tatubot.dibujarCaritaEntusiasmada();
    tatubot.reproducirSonido(2, 1900);         
    tatubot.escucharOrdenes();
  }
  if (digitalRead(PIN_ORDEN_AVANZAR) == LOW) {          
    tatubot.dibujarCaritaFeliz();
    tatubot.reproducirSonido(11, 150);
  }
  if (digitalRead(PIN_ORDEN_REVERSA) == LOW) {          
    tatubot.dibujarCaritaEntusiasmada();
    tatubot.reproducirSonido(11, 150);
    tatubot.bailarParaLaPresentacion(90); 
  }
  if (digitalRead(PIN_ORDEN_GIRO_DERECHA) == LOW) {          
    tatubot.reproducirSonido(18, 1900);//ruido de me pueden conectar el bluetooth
    tatubot.BtStandBy(200);
    
  }
  if (digitalRead(PIN_ORDEN_GIRO_IZQUIERDA) == LOW) {          
    tatubot.reproducirSonido(18, 1900);
    tatubot.ejecutarRutinaBT(255);
  }
  if (digitalRead(PIN_FIN_ORDENES) == LOW) {          
    tatubot.dibujarCaritaEntusiasmada();
    tatubot.reproducirSonido(3, 750); 
  }
  if (digitalRead(PIN_RESET) == LOW && tatubot.estoyEnBtStandBy == false ) {          
    tatubot.avisarMediaCapacidad();
  }
  tatubot.calcularCasosDeVelocidad();
  tatubot.revisarNivelDeBateria();
}
