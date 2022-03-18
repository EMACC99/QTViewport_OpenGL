#include "ejemplos.hpp"

namespace ejemplos{
    namespace{
        void basic_init(){
        }
        void ejemplo1_init(){

        }

        void ejemplo2_init(int *list){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            gluLookAt(1.5f, 1.0f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);

            glMatrixMode(GL_MODELVIEW);

            glLoadIdentity();
            *list = glGenLists(1);
            glNewList(*list, GL_COMPILE);
            
            glBegin(GL_POINTS);
                glColor3f(1.0f,0.0f,1.0f);
                glVertex2f(-0.5f,-0.5f);
                glColor3f(1.0f,0.0f,1.0f);
                glVertex2f(0.5f,-0.5f);
                glVertex2f(0.5f,0.5f);
                glColor3f(0.0f,0.0f,1.0f);
                glVertex2f(-0.5f,0.5f);
                glColor3f(0.0f,0.0f,1.0f);
                glVertex2d(1.25f,.25f);
            glEnd();
            glEndList();

        }

        void ejemplo4_init(){
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
        }
    }

    void initialize_ejemplo(const int &ejemplo, int *list){
        switch (ejemplo){
        case 1:
            ejemplo1_init();
            ejemplo1();
            break;
        
        case 2:
            ejemplo2_init(list);
            ejemplo2(list);
            break;
        
        case 3:
            break;

        case 4:
            ejemplo4_init();
            ejemplo4();

        default:
            break;
        }
    }

    void ejemplo1(){
        glMatrixMode(GL_MODELVIEW);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen and Depth Buffers
        glLoadIdentity();                                   // Reset view
        glPointSize(20.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.0f, 0.0f, -2.0f);
        glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.5f, 0.5f);
        // glVertex2d(1.25f,.25f);
        glEnd();
    }

    void ejemplo2(int *list){
        glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Clear Screen and Depth Buffers
        glLoadIdentity(); //Reset view
        glPointSize(20.0f);
        glColor3f(1.0f,1.0f,1.0f);
        glTranslatef(0.0f,-0.5f,-3.0f);
        float vertices[]={1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,0.0f, 0.0f, 1.0f };
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,vertices);
        unsigned int indices[]={0,1,2};
        /*glBegin(GL_POINTS);
            glArrayElement(0);
            glArrayElement(1);
            glArrayElement(2);
        glEnd();*/
        //glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,indices);
        glDrawArrays(GL_LINE_STRIP,0,3);
        glDisableClientState(GL_VERTEX_ARRAY);


        glLoadIdentity();
        glTranslatef(0.0f,-0.5f,-2.5f);


        glCallList(*list);

    }
    void ejemplo4(){
        glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
        glLoadIdentity();                   // Reset The View

        // doesn't work with lighting
        glTranslatef(-1.5f,0.0f,-6.0f);             // Move Left And Into The Screen
        glRotatef(50.0f,0.0f,1.0f,0.0f);             // Rotate The Pyramid On It's Y Axis
        glBegin(GL_TRIANGLES);                  // Start Drawing The Pyramid
            glColor3f(1.0f,0.0f,0.0f);          // Red
            glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
            glColor3f(0.0f,1.0f,0.0f);          // Green
            glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
            glColor3f(0.0f,0.0f,1.0f);          // Blue
            glVertex3f( 1.0f,-1.0f, 1.0f);          // Right Of Triangle (Front)
            glColor3f(1.0f,0.0f,0.0f);          // Red
            glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
            glColor3f(0.0f,0.0f,1.0f);          // Blue
            glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
            glColor3f(0.0f,1.0f,0.0f);          // Green
            glVertex3f( 1.0f,-1.0f, -1.0f);         // Right Of Triangle (Right)
            glColor3f(1.0f,0.0f,0.0f);          // Red
            glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
            glColor3f(0.0f,1.0f,0.0f);          // Green
            glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
            glColor3f(0.0f,0.0f,1.0f);          // Blue
            glVertex3f(-1.0f,-1.0f, -1.0f);         // Right Of Triangle (Back)
            glColor3f(1.0f,0.0f,0.0f);          // Red
            glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
            glColor3f(0.0f,0.0f,1.0f);          // Blue
            glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
            glColor3f(0.0f,1.0f,0.0f);          // Green
            glVertex3f(-1.0f,-1.0f, 1.0f);          // Right Of Triangle (Left)
        glEnd();
        glFlush();

    }
}