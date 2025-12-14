// ******** Моделирование падения цепочки ***************
// ******** (С) Степан Воротницкий **********************
// ******************************************* вер.2  ***

const double g = 9.8; // ускорение свободного падения
const double l = 0.72; // длина цепочки
const double mu = 0.3; // коэфициент трения
const double l0 = 0.32; // начальная длина свисающей цепочки
double x = l0; // текущая координата
double t = 0; // текущее время
double dt = 0.001; // шаг по времени
double v = 0; // текущая скорость
double vn = 0; // новая скорость
double c = 0;
int i = 0;
// ********************** SETUP ************************
void setup() {   
  Wire.begin(); 
  Serial.begin(9600); 
  Serial.println ();

  while (x<l) 
  {
    if (i % 100 == 0 ) { 
      Serial.print (t,4);  Serial.print ("    ");
      Serial.print (x,4); Serial.print ("    ");
      Serial.print (v,4); Serial.println();
    }
    c=g*(x*(1+mu)/l-mu);
    t=t+dt;
    vn=v+c*dt;  x=x+(v+vn)*dt/2; v=vn;
    i++; 
  }
} // ********************** END SETUP ********************
void loop() { } 
