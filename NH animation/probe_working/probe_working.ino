void setup(){
  DDRA =255;
  DDRB=255;
}


void
line_diagonal(
        uint8_t y0,
        uint8_t x0,
        uint8_t y1,
        uint8_t x1
       
)
{
        int dx, dy, sx, sy;

        if (x0 < x1)
        {
                dx = x1 - x0;
                sx = 1;
        } else {
                dx = x0 - x1;
                sx = -1;
        }

        if (y0 < y1)
        {
                dy = y1 - y0;
                sy = 1;
        } else {
                dy = y0 - y1;
                sy = -1;
        }

        int err = dx - dy;

        while (1)
        {
                PORTB = x0;
                PORTA = y0;

                if (x0 == x1 && y0 == y1)
                        break;

                int e2 = 2 * err;
                if (e2 > -dy)
                {
                        err = err - dy;
                        x0 += sx;
                }
                if (e2 < dx)
                {
                        err = err + dx;
                        y0 += sy;
                }
                delayMicroseconds(40);
        }
}

void
line_vert(
        uint8_t x0,
        uint8_t y0,
        uint8_t w
)
{       
        PORTA = x0;
        PORTB = y0;
        for (int i = 0 ; i < w ; i++)
                PORTB++;
                delayMicroseconds(8);
                
}

void    
line_horiz(
        uint8_t x0,
        uint8_t y0,
        uint8_t h
)       
{       
        PORTA = x0;
        PORTB = y0;
        
        for (int i = 0 ; i < h ; i++)
                PORTA++;
                delayMicroseconds(8);
}


unsigned char sinTab[]=
{ 
 127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,
  221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,
  76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
  33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124
 };

unsigned char j=64;


void loop() {
  //front side
 line_horiz(100,180,40);//top line - go clockwise from here
line_vert(110,180,50);//left upright on RTG
line_horiz(110,230,20);
line_vert(130,180,50);
line_diagonal(140,180,180,120);
line_vert(180,90,30);
line_horiz(60,90,120);//bottom line
line_vert(60,90,30);
line_diagonal(60,120,100,180);

//rear side
line_horiz(110,190,40);//top line - go clockwise from here
line_vert(120,190,50);//left upright on RTG
line_horiz(120,240,20);
line_vert(140,190,50);
line_diagonal(150,190,190,130);
line_vert(190,100,30);
line_horiz(70,100,120);//bottom line
line_vert(70,100,30);
line_diagonal(70,130,100,180);

//diagonal connections
line_diagonal(100,180,110,190);
line_diagonal(110,180,120,190);
line_diagonal(110,230,120,240);
line_diagonal(130,180,140,190);
line_diagonal(130,230,140,240);
line_diagonal(140,180,150,190);
line_diagonal(180,120,190,130);
line_diagonal(180,90,190,100);
line_diagonal(60,90,70,100);
line_diagonal(60,120,70,130);

//antenna booms
line_vert(115,135,20);
line_diagonal(115,135,130,120);
line_diagonal(115,135,95,120);


for(int i=0;i<256;i++){
    PORTA=0.2*sinTab[i]+90;//horizontal sin wave
  PORTB=0.2*sinTab[j++]+110;//vertical sin wave
  delayMicroseconds(8);//delay between points
 


    }

}
