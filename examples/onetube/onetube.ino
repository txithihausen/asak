#include<OneDigitalTube.h>
char segments[8];




OneDigitalTube tube;

void setup()

{


          for (int i=0;i<8;i++)

          {
            segments[i] = i+2;



          }
          
          tube.begin(segments, true);

}




void loop()
{
  for(int i = 0; i<10; i++) {
    tube.plotNumber(i);  
    delay(1000);
  }
  
  tube.disableAllSegments();
  tube.enableDP();
  delay(300);
  tube.disableDP();
  delay(300);
  tube.enableDP();
  delay(300);
  tube.disableDP();
  delay(300);  
  tube.enableDP();
  delay(300);
  tube.disableDP();
  delay(300);


}
