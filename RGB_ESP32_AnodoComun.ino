/*
  Este código sirve para controlar un LED RGB de ÁNODO COMÚN mediante PWM
*/

//Declaramos los pines---------
#define LED_ROJO   3 //Rojo    GPIO 3
#define LED_VERDE   1 //Verde  GPIO 1
#define LED_AZUL   22 //Azul   GPIO 22
//-----------------------------

//Declaramos los canales para el PWM---------
#define PWM_Ch0    0 //Canal 0 - Rojo
#define PWM_Ch1    1 //Canal 1 - Verde
#define PWM_Ch2    2 //Canal 2 - Azul
//-------------------------------------------

//Declaramos los bits de resolución y la frecuencia para el PWM----
#define PWM_Res   8 //Resolución de  8 bits (ESP32 puede con 16bits) 2^8 = 256 valores para que pueda tomar los valores 255 de colores
#define PWM_Freq  1000 //Frecuencia
//-----------------------------------------------------------------

//Creamos variables que almacenen el ciclo de trabajo y las inicializamos en 0----
int PWM1_DutyCycle = 0; //Ciclo de trabajo 1
int PWM2_DutyCycle = 0; //Ciclo de trabajo 2
int PWM3_DutyCycle = 0; //Ciclo de trabajo 3
//--------------------------------------------------------------------------------

void setup() //Configuraciones
{
  //CONFIGURACIÓN PWM ROJO
  ledcAttachPin(LED_ROJO, PWM_Ch0); //Le asignamos el canal 0 al pin 3 (ROJO)
  ledcSetup(PWM_Ch0, PWM_Freq, PWM_Res); //Configuramos el PWM (le asignamos el canal, la frecuencia y la cantidad de bits de resolución)

  //CONFIGURACIÓN PWM VERDE
  ledcAttachPin(LED_VERDE, PWM_Ch1); //Le asignamos el canal 1 al pin 1 (VERDE)
  ledcSetup(PWM_Ch1, PWM_Freq, PWM_Res); //Configuramos el PWM (le asignamos el canal, la frecuencia y la cantidad de bits de resolución)

  //CONFIGURACIÓN PWM AZUL
  ledcAttachPin(LED_AZUL, PWM_Ch2); //Le asignamos el canal 2 al pin 22 (AZUL)
  ledcSetup(PWM_Ch2, PWM_Freq, PWM_Res); //Configuramos el PWM (le asignamos el canal, la frecuencia y la cantidad de bits de resolución)
}
 
void loop(){ //Ciclo repetitivo

  // llamamos la función "color" para que "imprima" el color que le pasemos
  color(255,0,128);  //Colocamos el código de color RGB que queremos que tengo el LED RGB
}

void color (int R, int G,int B){ //Esta función se encarga de pasar de CATODO a ANODO COMÚN y también controlamos el PWM con "ledcWrite"
  
 //Esta sección es para pasar de CATODO COMÚN a ANODO COMÚN---
    //POSDATA: si tienes CÁTODO COMÚN puedes borrar esto
  R = 255 - R;
  G = 255 - G;
  B = 255 - B;
//------------------------------------------------------------

  ledcWrite(PWM_Ch0, R); //"imprime" mediante PWM el valor que le pasemos por la variable "R"
  ledcWrite(PWM_Ch1, G); //"imprime" mediante PWM el valor que le pasemos por la variable "G"
  ledcWrite(PWM_Ch2, B); //"imprime" mediante PWM el valor que le pasemos por la variable "B"
}
