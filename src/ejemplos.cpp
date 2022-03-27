#include "includes/ejemplos.hpp"
#include "includes/gl_debug.hpp"

namespace ejemplos{
    namespace{
       
        void ejemplo1_init(){}

        void ejemplo2_init(int *list){
            // glMatrixMode(GL_PROJECTION);
            // glLoadIdentity();

            // gluLookAt(1.5f, 1.0f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);

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

        void ejemplo5_init(){
            /*Lighting*/
            glShadeModel(GL_SMOOTH);
            glEnable(GL_DEPTH_TEST); // Enables Depth Testing
            glEnable(GL_LIGHTING);   // Enable Lighting
            glDepthFunc(GL_LEQUAL);  // The Type Of Depth Testing To Do
            glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
            /*Light values*/
            GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
            GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
            GLfloat LightPosition[]= { 0.0f, 0.0f, 2.0f, 1.0f };
            /*Setting light values*/
            glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
            glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiffuse);
            GLfloat red[]= { 1.0f, 0.0f, 0.0f, 1.0f };
            glLightfv( GL_LIGHT0, GL_SPECULAR, red ); // Sets specular component of light 0 to red,
            glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
            glEnable(GL_LIGHT1);
            glEnable(GL_LIGHT0);
            /*Setting back-culling*/
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            /*****/
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
                glVertex2d(1.25f,.25f);
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
            glBegin(GL_POINTS);
                glArrayElement(0);
                glArrayElement(1);
                glArrayElement(2);
            glEnd();
            glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,indices);
            glDrawArrays(GL_LINE_STRIP,0,3);
            glDisableClientState(GL_VERTEX_ARRAY);


            glLoadIdentity();
            glTranslatef(0.0f,-0.5f,-2.5f);


            glCallList(*list);

        }
        void ejemplo4(const bool &rotate, float *initial_rotation, const std::array<float, 3> &rotate_axis){
            glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
            glLoadIdentity();                   // Reset The View

            auto [x,y,z] = rotate_axis;

            // doesn't work with lighting
            glTranslatef(-1.5f,0.0f,-6.0f);             // Move Left And Into The Screen
            // glRotatef(50.0f,0.0f,1.0f,0.0f);             // Rotate The Pyramid On It's Y Axis
            if (rotate)
                *initial_rotation += rotation_factor;
            
            glRotatef(*initial_rotation, x, y, z);

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

        void ejemplo5(const bool &rotate, float *initial_rotation, const std::array<float, 3> &rotate_axis){
            glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
            glLoadIdentity();                   // Reset The View

            GLfloat red[] = {1.0f, 0.0f, 0.0f, 1.0f};
            GLfloat green[]={0.0f,1.0f,0.0f,1.0f};
            GLfloat blue[]={0.0f,0.0f,1.0f,1.0f};
            GLfloat orange[]={1.0f,0.5f,0.0f,1.0f};
            GLfloat yellow[]={1.0f,1.0f,0.0f,1.0f};
            GLfloat violet[]={1.0f,0.0f,1.0f,1.0f};

            glTranslatef(1.5f,0.0f,-7.0f);              // Move Right And Into The Screen

            auto [x,y,z] = rotate_axis;
            // std::cout << x << " " << y << " " << z <<  "\n";

            if (rotate)
                *initial_rotation += rotation_factor;
            glRotatef(*initial_rotation, x, y, z);
            
            // glRotatef(25.0f,1.0f,1.0f,1.0f);            // Rotate The Cube On X, Y & Z

            glBegin(GL_QUADS);                  // Start Drawing The Cube
                glNormal3f( 0.0f, 1.0f, 0.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, green ); // Sets diffuse component of material to green

                glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Top)
                glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Top)
                glVertex3f(-1.0f, 1.0f, 1.0f);          // Bottom Left Of The Quad (Top)
                glVertex3f( 1.0f, 1.0f, 1.0f);          // Bottom Right Of The Quad (Top)

                glNormal3f( 0.0f,-1.0f, 0.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, orange );// Sets diffuse component of material to orange

                glVertex3f( 1.0f,-1.0f, 1.0f);          // Top Right Of The Quad (Bottom)
                glVertex3f(-1.0f,-1.0f, 1.0f);          // Top Left Of The Quad (Bottom)
                glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Bottom)
                glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Bottom)

                glNormal3f( 0.0f, 0.0f, 1.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, red );// Sets diffuse component of material to red

                glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Front)
                glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Front)
                glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Front)
                glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Front)

                glNormal3f( 0.0f, 0.0f,-1.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, yellow );// Sets diffuse component of material to yellow

                glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Back)
                glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Back)
                glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Back)
                glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Back)

                glNormal3f(-1.0f, 0.0f, 0.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, blue );// Sets diffuse component of material to blue

                glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Left)
                glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Left)
                glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Left)
                glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Left)

                glNormal3f( 1.0f, 0.0f, 0.0f);
                glMaterialfv( GL_FRONT, GL_DIFFUSE, violet );// Sets diffuse component of material to violet

                glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
                glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
                glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
                glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
            glEnd();                        // Done Drawing The Quad
            glFlush();
        }
    }

    void initialize_ejemplo(const int &ejemplo, int *list){
        switch (ejemplo){
        case 1:{
            ejemplo1_init();
            break;
        }
        case 2:{
            ejemplo2_init(list);
            break;
        }
        case 3:{
            // throw "Este ejemplo no existe";

            break;
        }
        case 4:{
            ejemplo4_init();
            break;
        }
        case 5: {
            ejemplo5_init();
            break;
        }
        default:{
            // throw "Este ejemplo no existe";
            break;
        }
        }
    }
    
    void ejemplo(const int &ejemplo, int *list, const bool &rotate, float *initial_rotation, const std::array<float, 3> &rotate_axis){
        switch (ejemplo){
        
        case 1: {
            ejemplo1();
            break;
        }
        case 2: {
            ejemplo2(list);
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            ejemplo4(rotate, initial_rotation, rotate_axis);

            break;
        }
        case 5: {
            ejemplo5(rotate, initial_rotation, rotate_axis);
            break;
        }
        default: {
            break;
        }
        }
    }

}
