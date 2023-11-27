#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>
void init(void)
{
  glClearColor(93.0 / 255.0, 202.0 / 255.0, 252.0 / 255.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();  
  glOrtho(-50, 50, -50, 50, -1.0, 1.0);
}

int moment = 0;
int moment2 = 0;
float c1= 0;
float c2= 0;
float c3= 50;
float c4= -30;
float c5= 55;
float c6= -10;
float c7= -50;
float c8= 20;

void circle (GLfloat cx, GLfloat cy, GLfloat rx, GLfloat ry)
{
    glBegin(GL_TRIANGLE_FAN);
    //glColor3f( 0,1, 1);
    glVertex2f(cx,cy);

    for(int i=0; i<=100; i++){
        float angle= 2.0f*3.142f*i/100;
        float x= rx*cosf(angle);
        float y= ry*sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutPostRedisplay();

    if(moment <= 2000){
        moment++;
    }
    else{
        moment=0;
    }
    float cx = 0, cy = 0, rx = 45, ry = 45;
    
    float angle= 2.0f*3.142f*moment/2000;
    float x= rx*cosf(angle);
    float y= ry*sinf(angle);

    float actual_x = x+cx;
    float actual_y = y+cy;
    
    float moon_x = -actual_x;
    float moon_y = -actual_y;

    //sun15
    glColor3f(1,1,0);
    circle(actual_x, actual_y,5,5);


    //moon
    glColor3f(1,1,1);
    circle(-actual_x, -actual_y, 5, 5);
    glColor3f(93.0 / 255.0, 202.0 / 255.0, 252.0 / 255.0);
    circle(-actual_x+3, -actual_y+3, 5, 5);

    //Stars    
    if(moment > 1000 && moment < 2000){
        glBegin(GL_POINTS);
            glColor3f(1, 1, 1);
            glVertex2f(45, 45);
            glVertex2f(-40, 45);
            glVertex2f(20, 40);
            glVertex2f(41, 42);
            glVertex2f(30, 38);
            glVertex2f(48, 0);
            glVertex2f(-10, 47);
            glVertex2f(20, 39);
            glVertex2f(-25, 41);
        glEnd();
    }


    if(c1 <= 60){
        c1+=0.1;
    }
    else{
        c1=-60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c1    ,48,2,2);
    circle(c1-2  ,45,2,2);
    circle(c1-3.5,48,2,2);
    circle(c1-5.5,47,2,2);
    circle(c1+1  ,45,2,2);
    circle(c1+3.5,47,2,2);


    if(c2 >= -60){
        c2-=0.2;
    }
    else{
        c2=60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c2     ,43,2,2);
    circle(c2-2   ,41,2,2);
    circle(c2-3.5 ,42,2,2);
    circle(c2+1   ,40,2,2);
    circle(c2+3.5 ,42,2,2);



    if(c3 >= -60){
        c3-=0.02;
    }
    else{
        c3=60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c3    ,48,2,2);
    circle(c3-2  ,45,2,2);
    circle(c3-3.5,48,2,2);
    circle(c3+1  ,45,2,2);
    circle(c3+3.5,47,2,2);


    if(c4 <= 60){
        c4+=0.25;
    }
    else{
        c4=-60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c4    ,46,2,2);
    circle(c4-2.3,43,2,2);
    circle(c4-5.5,43,2,2);
    circle(c4-3.5,46,2,2);
    circle(c4+0.5,43,2,2);
    circle(c4+3  ,44,2,2);


    if(c5 >= -60){
        c5-=0.1;
    }
    else{
        c5=60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c5   ,48,2,2);
    circle(c5-6 ,46,2,2);
    circle(c5-1 ,45,2,2);
    circle(c5-3 ,46,2,2);
    circle(c5-5 ,45,2,2);
    circle(c5+2 ,46,2,2);


    if(c6 <= 60){
        c6+=0.06;
    }
    else{
        c6=-60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c6   ,41,2,2);
    circle(c6-6 ,41,2,2);
    circle(c6-1 ,40,2,2);
    circle(c6-3 ,41,2,2);
    circle(c6-5 ,40,2,2);
    circle(c6+3 ,41,2,2);


    if(c7 <= 60){
        c7+=0.1;
    }
    else{
        c7=-60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c7  ,47,2,2);
    circle(c7-8,46,2,2);
    circle(c7-1,45,2,2);
    circle(c7-3,46,2,2);
    circle(c7-5,45,2,2);
    circle(c7-5,47,2,2);
    circle(c7+2,46,2,2);


    if(c5 >= -60){
        c8-=0.09;
    }
    else{
        c8=60;
    }
    //cloud
    glColor3f(1,1,1);
    circle(c8   ,42,2,2);
    circle(c8-8 ,41,2,2);
    circle(c8-1 ,40,2,2);
    circle(c8-3 ,42.5,2,2);
    circle(c8-5 ,40,2,2);
    circle(c8-5 ,42,2,2);
    circle(c8+2 ,41,2,2);

    //base
    glColor3f(167.0 / 255.0, 167.0 / 255.0, 168.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,3);
    glVertex2i(-50,-50);
    glVertex2i(50,-50);
    glVertex2i(50,3);
    glEnd();
    glColor3f(166.0 / 255.0, 224.0 / 255.0, 237.0 / 255.0);
    glBegin(GL_LINES);
    glVertex2i(-35,0);
    glVertex2i(35,0);
    glVertex2i(-50,-10);
    glVertex2i(50,-10);
    glVertex2i(-50,-20);
    glVertex2i(50,-20);
    glVertex2i(-50,-30);
    glVertex2i(50,-30);
    glVertex2i(-50,-40);
    glVertex2i(50,-40);
    glVertex2i(-50,-40);
    glVertex2i(50,-50);
    

   
    glVertex2i(-60,-50);
    glVertex2i(-30,5);
    glVertex2i(-40,-50);
    glVertex2i(-20,5);
    glVertex2i(-20,-50);
    glVertex2i(-10,5);
    glVertex2i(0,-50);
    glVertex2i(0,5);
    glVertex2i(20,-50);
    glVertex2i(10,5);
    glVertex2i(40,-50);
    glVertex2i(20,5);
    glVertex2i(60,-50);
    glVertex2i(30,5);
    glEnd();


    //piller1    
    glColor3f(255.0 / 255.0, 242.0 / 255.0, 191.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-30,16);
    glVertex2i(-30,32);
    glVertex2i(-31,34);
    glVertex2i(-32,32);
    glVertex2i(-32,16.5);
    glEnd();
    circle(-31,30,2,1);
    circle(-31,28,2,1);
    circle(-31,17,2,1);

    //piller1
    glBegin(GL_POLYGON);
    glVertex2i(-37,17);
    glVertex2i(-37,33);
    glVertex2i(-38,35);
    glVertex2i(-39,33);
    glVertex2i(-39,17);
    glEnd();
    circle(-38,31,2,1);
    circle(-38,29,2,1);
    circle(-38,17,2,1);

    //piller2
    glBegin(GL_POLYGON);
    glVertex2i(4,15);
    glVertex2i(4,32);
    glVertex2i(3,34);
    glVertex2i(2,32);
    glVertex2i(2,15);
    glEnd();
    circle(3,30,2,1);
    circle(3,28,2,1);
    circle(3,16,2,1);

    //piller2
    glBegin(GL_POLYGON);
    glVertex2i(-3,15);
    glVertex2i(-3,32);
    glVertex2i(-4,34);
    glVertex2i(-5,32);
    glVertex2i(-5,15);
    glEnd();
    circle(-4,30,2,1);
    circle(-4,28,2,1);
    circle(-4,16,2,1);

    //piller3
    glBegin(GL_POLYGON);
    glVertex2i(30,16);
    glVertex2i(30,32);
    glVertex2i(31,34);
    glVertex2i(32,32);
    glVertex2i(32,16);
    glVertex2i(31,34);
    glEnd();
    circle(31,30,2,1);
    circle(31,28,2,1);
    circle(31,17,2,1);

    //piller3
    glBegin(GL_POLYGON);
    glVertex2i(37,17);
    glVertex2i(37,33);
    glVertex2i(38,35);
    glVertex2i(39,33);
    glVertex2i(39,17);
    glEnd();
    circle(38,31,2,1);
    circle(38,29,2,1);
    circle(38,17,2,1);

    //building
    glColor3f(252.0 / 255.0, 236.0 / 255.0, 210.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,-15);
    glVertex2i(-50,18);
    glVertex2i(-20,15);
    glVertex2i(-20,3);
    glEnd();

    //building
    glColor3f(252.0 / 255.0, 236.0 / 255.0, 210.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-20,3);
    glVertex2i(-20,15);
    glVertex2i(20,15);
    glVertex2i(20,3);
    glEnd();



    //building
    glColor3f(252.0 / 255.0, 236.0 / 255.0, 210.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(50,-15);
    glVertex2i(50,18);
    glVertex2i(20,15);
    glVertex2i(20,3);
    glEnd();




    //roof
    glColor3f(252.0 / 255.0, 252.0 / 255.0, 225.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,-30);
    glVertex2i(-50,-50);
    glVertex2i(50,-50);
    glVertex2i(50,-30);
    glEnd();



    //roof top
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-49,-40);
    glVertex2i(-31,-40);
    glVertex2i(-40,-27);
    glEnd();
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    circle(-40,-44,12,12);


    //roof top
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-29,-40);
    glVertex2i(-11,-40);
    glVertex2i(-20,-27);
    glEnd();
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    circle(-20,-44,12,12);



    //roof top
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-9,-40);
    glVertex2i(9,-40);
    glVertex2i(0,-27);
    glEnd();
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    circle(0,-44,12,12);



    //roof top
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(11,-40);
    glVertex2i(29,-40);
    glVertex2i(20,-27);
    glEnd();
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    circle(20,-44,12,12);



    //roof top
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(31,-40);
    glVertex2i(49,-40);
    glVertex2i(40,-27);
    glEnd();
    glColor3f(242.0 / 255.0, 213.0 / 255.0, 155.0 / 255.0);
    circle(40,-44,12,12);




    //bottom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,-15);
    glVertex2i(-50,-5);
    glVertex2i(-48,-2);
    glVertex2i(-45,-5);
    glVertex2i(-45,-12);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-45,-12);
    glVertex2i(-45,-5);
    glVertex2i(-43,0);
    glVertex2i(-40,-2);
    glVertex2i(-40,-9);
    glEnd();



    //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-40,-9);
    glVertex2i(-40,-2);
    glVertex2i(-38,2);
    glVertex2i(-35,0);
    glVertex2i(-35,-6);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-35,-6);
    glVertex2i(-35,0);
    glVertex2i(-33,4);
    glVertex2i(-30,2);
    glVertex2i(-30,-3);
    glEnd();



    //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-30,-3);
    glVertex2i(-30,2);
    glVertex2i(-28,6);
    glVertex2i(-25,3);
    glVertex2i(-25,0);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-25,0);
    glVertex2i(-25,3);
    glVertex2i(-23,7);
    glVertex2i(-20,5);
    glVertex2i(-20,3);
    glEnd();



    //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-20,3);
    glVertex2i(-20,5);
    glVertex2i(-18,7);
    glVertex2i(-15,5);
    glVertex2i(-15,3);
    glEnd();




   //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-15,3);
    glVertex2i(-15,5);
    glVertex2i(-13,7);
    glVertex2i(-10,5);
    glVertex2i(-10,3);
    glEnd();


   //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-10,3);
    glVertex2i(-10,5);
    glVertex2i(-8,7);
    glVertex2i(-5,5);
    glVertex2i(-5,3);
    glEnd();


   //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5,3);
    glVertex2i(-5,5);
    glVertex2i(-3,7);
    glVertex2i(0,5);
    glVertex2i(0,3);
    glEnd();



   //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(0,3);
    glVertex2i(0,5);
    glVertex2i(3,7);
    glVertex2i(5,5);
    glVertex2i(5,3);
    glEnd();



   //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(5,3);
    glVertex2i(5,5);
    glVertex2i(8,7);
    glVertex2i(10,5);
    glVertex2i(10,3);
    glEnd();


   //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(10,3);
    glVertex2i(10,5);
    glVertex2i(13,7);
    glVertex2i(15,5);
    glVertex2i(15,3);
    glEnd();


   //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(15,3);
    glVertex2i(15,5);
    glVertex2i(18,7);
    glVertex2i(20,5);
    glVertex2i(20,3);
    glEnd();




   //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(20,3);
    glVertex2i(20,5);
    glVertex2i(23,7);
    glVertex2i(25,3);
    glVertex2i(25,0);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(25,0);
    glVertex2i(25,3);
    glVertex2i(28,6);
    glVertex2i(30,2);
    glVertex2i(30,-3);
    glEnd();




    //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(30,-3);
    glVertex2i(30,2);
    glVertex2i(33,4);
    glVertex2i(35,0);
    glVertex2i(35,-6);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(35,-6);
    glVertex2i(35,0);
    glVertex2i(38,2);
    glVertex2i(40,-2);
    glVertex2i(40,-9);
    glEnd();




    //botom house
    glColor3f(250.0 / 255.0, 115.0 / 255.0, 85.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(40,-9);
    glVertex2i(40,-2);
    glVertex2i(43,0);
    glVertex2i(45,-5);
    glVertex2i(45,-12);
    glEnd();



    //botom house
    glColor3f(171.0 / 255.0, 61.0 / 255.0, 36.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(45,-12);
    glVertex2i(45,-5);
    glVertex2i(48,-2);
    glVertex2i(50,-5);
    glVertex2i(50,-15);
    glEnd();




    //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,1);
    glVertex2i(-50,13);
    glVertex2i(-48,16);
    glVertex2i(-45,13);
    glVertex2i(-45,2);
    glEnd();



    //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-45,2);
    glVertex2i(-45,13);
    glVertex2i(-43,16);
    glVertex2i(-40,13);
    glVertex2i(-40,4);
    glEnd();



    //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-40,4);
    glVertex2i(-40,13);
    glVertex2i(-38,16);
    glVertex2i(-35,13);
    glVertex2i(-35,5);
    glEnd();



    //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-35,5);
    glVertex2i(-35,13);
    glVertex2i(-33,16);
    glVertex2i(-30,13);
    glVertex2i(-30,7);
    glEnd();



    //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-30,7);
    glVertex2i(-30,13);
    glVertex2i(-28,15);
    glVertex2i(-25,12);
    glVertex2i(-25,9);
    glEnd();



    //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-25,9);
    glVertex2i(-25,12);
    glVertex2i(-23,14);
    glVertex2i(-20,12);
    glVertex2i(-20,9);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-20,9);
    glVertex2i(-20,12);
    glVertex2i(-18,14);
    glVertex2i(-15,11);
    glVertex2i(-15,9);
    glEnd();




   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-15,9);
    glVertex2i(-15,11);
    glVertex2i(-13,14);
    glVertex2i(-10,11);
    glVertex2i(-10,9);
    glEnd();



   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-10,9);
    glVertex2i(-10,11);
    glVertex2i(-8,14);
    glVertex2i(-5,11);
    glVertex2i(-5,9);
    glEnd();


   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-5,9);
    glVertex2i(-5,11);
    glVertex2i(-3,14);
    glVertex2i(0,11);
    glVertex2i(0,9);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(0,9);
    glVertex2i(0,11);
    glVertex2i(3,14);
    glVertex2i(5,11);
    glVertex2i(5,9);
    glEnd();


   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(5,9);
    glVertex2i(5,11);
    glVertex2i(8,14);
    glVertex2i(10,11);
    glVertex2i(10,9);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(10,9);
    glVertex2i(10,11);
    glVertex2i(13,14);
    glVertex2i(15,11);
    glVertex2i(15,9);
    glEnd();


   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(15,9);
    glVertex2i(15,11);
    glVertex2i(18,14);
    glVertex2i(20,11);
    glVertex2i(20,9);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(20,9);
    glVertex2i(20,11);
    glVertex2i(23,14);
    glVertex2i(25,11);
    glVertex2i(25,9);
    glEnd();


   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(25,9);
    glVertex2i(25,11);
    glVertex2i(28,15);
    glVertex2i(30,13);
    glVertex2i(30,7);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(30,7);
    glVertex2i(30,13);
    glVertex2i(33,16);
    glVertex2i(35,13);
    glVertex2i(35,5);
    glEnd();


   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(35,5);
    glVertex2i(35,13);
    glVertex2i(38,16);
    glVertex2i(40,13);
    glVertex2i(40,4);
    glEnd();


   //top house
    glColor3f(196.0 / 255.0, 172.0 / 255.0, 49.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(40,4);
    glVertex2i(40,13);
    glVertex2i(43,16);
    glVertex2i(45,13);
    glVertex2i(45,2);
    glEnd();



   //top house
    glColor3f(255.0 / 255.0, 248.0 / 255.0, 115.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(45,2);
    glVertex2i(45,13);
    glVertex2i(48,16);
    glVertex2i(50,13);
    glVertex2i(50,1);
    glEnd();


   //border
    glColor3f(247.0 / 255.0, 222.0 / 255.0, 27.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,-1);
    glVertex2i(-25,8);
    glVertex2i(-25,9);
    glVertex2i(-50,1);
    glEnd();



    //border
    glColor3f(247.0 / 255.0, 222.0 / 255.0, 27.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(-25,8);
    glVertex2i(25,8);
    glVertex2i(25,9);
    glVertex2i(-25,9);
    glEnd();



    //border
    glColor3f(247.0 / 255.0, 222.0 / 255.0, 27.0 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2i(25,8);
    glVertex2i(50,-1);
    glVertex2i(50,1);
    glVertex2i(25,9);
    glEnd();



    if(moment2 <= 1000){
        moment2++;
    }else{
        moment2=0;
    }

    cx = 0, cy = -6, rx = 20, ry = 6;
    
    angle= 2.0f*3.142f*moment2/1000;
    x= rx*cosf(angle);
    y= ry*sinf(angle);

    actual_x = x+cx;
    actual_y = y+cy;

    //men
    glColor3f(0,0,0);
    circle(actual_x, actual_y, 1, 1);
    glColor3f(1,1,1);
    circle(actual_x, actual_y-3, 1, 2);

    //women
    glColor3f(0,0,0);
    circle(actual_x+3, actual_y-1, 1, 1);
    glColor3f(0,0,0);
    circle(actual_x+3, actual_y-3, 1, 2);




    
    //kaba left
    glColor3f( 0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-11);
    glVertex2i(-6,-8);
    glVertex2i(-6,3);
    glVertex2i(0,2);
    glEnd();



    //kaba right
    glColor3f( 0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-11);
    glVertex2i(6,-8);
    glVertex2i(6,3);
    glVertex2i(0,2);
    glEnd();



    //kaba top
    glColor3f( 0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(-6,3);
    glVertex2i(0,6);
    glVertex2i(6,3);
    glEnd();


    //kaba top left
    glColor3f( 1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-2);
    glVertex2i(0,-3);
    glVertex2i(-6,0);
    glVertex2i(-6,1);
    glEnd();



    //kaba top right
    glColor3f( 1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-2);
    glVertex2i(0,-3);
    glVertex2i(6,0);
    glVertex2i(6,1);
    glEnd();



    //kaba bottom left
    glColor3f( 1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-11);
    glVertex2i(-6,-8);
    glVertex2i(-6,-6);
    glVertex2i(0,-9);
    glEnd();



    //kaba bottom right
    glColor3f( 1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,-11);
    glVertex2i(6,-8);
    glVertex2i(6,-6);
    glVertex2i(0,-9);
    glEnd();



    //kaba door
    glColor3f( 1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(1,-3);
    glVertex2i(1,-7);
    glVertex2i(3,-6);
    glVertex2i(3,-2);
    glEnd();



    if(moment > 1000 && moment <= 1500){
        float alpha = (moment - 1000) / float(1500 - 1000);

        glColor4f(4.0/255.0, 3.0/255.0, 72.0/255.0, alpha/2.0);
        glBegin(GL_POLYGON);
            glVertex2f(-50, -50);
            glVertex2f(-50, 50);
            glVertex2f(50, 50);
            glVertex2f(50, -50);
        glEnd();
    }


    if(moment > 1500 && moment < 2000){
        float alpha = (moment - 1500) / float(2000 - 1500);

        glColor4f(4.0/255.0, 3.0/255.0, 72.0/255.0, 0.5-alpha/2.0);
        glBegin(GL_POLYGON);
            glVertex2f(-50, -50);
            glVertex2f(-50, 50);
            glVertex2f(50, 50);
            glVertex2f(50, -50);
        glEnd();
    }

    glutSwapBuffers();
}

int main(int argc,char **argv){

    
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(768,768);
    glutCreateWindow("Kaba Sharif");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

