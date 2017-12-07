#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 20

const static float size = 0.1;
static float x_curr, y_curr;
static float v_x, v_y;

int animation_ongoing = 0;

static void initialize(void);
static void on_display(void);
static void on_keyboard(char key, int x, int y);
static void on_timer(int value);

int main(int argc, char** argv){
    
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | \
                        GLUT_DEPTH | \
                        GLUT_DOUBLE);
    
    /* Kreira se prozor. */
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    /* Registruju se funkcije za obradu dogadjaja. */
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    
    /* Inicijalizacija seed-a za pseudoslcajne bbrojeve. */
    srand(time(NULL));
    
    initialize(); /* Inicijalizacija OpenGL-a. */
    
    /* Inicijalizuju se pocetne koordinate centra figure. */
    x_curr = (-1 + size/2) + (1 - size/2) * (float)rand()/RAND_MAX;
    y_curr = (-1 + size/2) + (1 - size/2) * (float)rand()/RAND_MAX;
       
    /* Inicijalizuju se pocetna brzina figure. */
    v_x = - size/2  + size * (float)rand()/RAND_MAX;
    v_y = - size/2  + size * (float)rand()/RAND_MAX;
        
    /* Na pocetku je animacija neaktivna */
    //animation_ongoing = 0;
    
    glutMainLoop();
    
    return 0;
}


/* Inicilalizacija OpenGL-a. */
void initialize(void){
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);    
}


static void on_display(void){

    /* Brise se sadrzaj buffer-a po kome ce da se iscrtava novi frame, kao i sadrzaj z-buffer-a. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Postavljanje boje.
    glColor3f(0, 0, 1);
     
    // Iscrtavanje kvadrata.
    glBegin(GL_POLYGON);
        glVertex3f(x_curr - size / 2, y_curr - size / 2, 0);
        glVertex3f(x_curr + size / 2, y_curr - size / 2, 0);
        glVertex3f(x_curr + size / 2, y_curr + size / 2, 0);
        glVertex3f(x_curr - size / 2, y_curr + size / 2, 0);
    glEnd();
    
    
    /* Postavlje se novi sadrzaj koji ce se iscrtati. */
    glutSwapBuffers();
}

static void on_keyboard(char key, int x, int y){
    
    switch(key){
        
        case 27: 
                printf("Taster ---> ESC");
                exit(EXIT_SUCCESS);
                break;         
        //pokretanje animacija
        case 'g':
        case 'G':
                if(!animation_ongoing){
                    animation_ongoing = 1;
                    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
                }
                break;        
        // zaustavlja se animacija
        case 's':
        case 'S':
                animation_ongoing = 0;
                break;
    }
    
}

static void on_timer(int value){
    
    if(value != TIMER_ID)
        return;
    
     /* Azuriraju se koordinate centra kvadrata. */
    x_curr += v_x;
    if (x_curr <= -(1 - size / 2) || x_curr >= 1 - size / 2) {
        v_x *= -1;
    }

    y_curr += v_y;
    if (y_curr <= -(1 - size / 2) || y_curr >= 1 - size / 2) {
        v_y *= -1;
    }
    
    /* Forsira se ponovno iscrtavanje sadrzaja. */
    glutPostRedisplay();
    
    /* Ukoliko animacija i dalje traje registruje se novi timer sledece isctavanje. */
    if(animation_ongoing){
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
    
}
