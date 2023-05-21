#include <display.hpp>



void NokiaDisplay::drawBitmap(const byte bitmap[]) {
  display.clearDisplay();
  for(int i = 0; i < display.width() * display.height() /8 ; i++){
    for(int bit  = 0; bit < 8; bit++){
      if((pgm_read_byte(&(bitmap[i])) & ( 1 << bit )) >> bit){
        display.drawPixel((i*8+(7-bit)) % display.width(), (i*8+(7-bit)) / display.width(), BLACK);
      }
    }
  }
  display.display();
}
void NokiaDisplay::init()
{
  pinMode(NOKIA_DISPLAY_LGT, OUTPUT);
  digitalWrite(NOKIA_DISPLAY_LGT, LOW);
  

  display.begin();
  display.setRotation(2);
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(42);
  display.clearDisplay();   // clears the screen and buffer

  // draw a single pixel
  this->drawBitmap(pixil_frame_0);
  display.display();
  delay(2000);
}

NokiaDisplay::NokiaDisplay() : display(NOKIA_DISPLAY_CLK, 
                                            NOKIA_DISPLAY_DIN, 
                                            NOKIA_DISPLAY_DC, 
                                            NOKIA_DISPLAY_CE, 
                                            NOKIA_DISPLAY_RST)
{
}

NokiaDisplay::~NokiaDisplay()
{
}

void display_execute_command(struct command *command, NokiaDisplay *display)
{
  //  display->init();
}
