#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define NUMBER_OF_DOTS 10
#define R 0.5
#define PI 3.14159

/* Funkcija koja vrsi OpenGL inicijalizaciju */
static void initialize(void);

/* Deklaracije callback funkcija */
static void on_keyboard(unsigned char key, int x, int y);
static void on_display(void);

//globalne promenljive
static int display_primitive;

int main(int argc, char** argv){
    
    //inicijalizacija GLUT-a
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_RGBA | \
                        GLUT_DEPTH | \
                        GLUT_DOUBLE);
    
    // Kreira se prozor
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    
    
    // Registruju se funkcije za obradu dogadjaja
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    
    
    // Inicijalizacija OpenGL-a
    initialize();
    
    // Beskonacna petlja u kojoj se izvrsava program
    glutMainLoop();
    
    return 0;
}

static void initialize(void){

    //postavlja se boja pozadine
    glClearColor(1, 1, 1, 0);
    
    //podesava se velicina tacke
    glPointSize(6);
    
    //podesava se debljina linije
    glLineWidth(12.7);
    
    //postavlja se podrazumevana primitiva
    display_primitive = GL_POINTS;
   
}


//ako se pritisne na tastaturi dugme ESC
static void on_keyboard(unsigned char key, int x, int y){
   
    switch(key){
        case 27:    
                exit(EXIT_SUCCESS);
                break;    
        
    /* U zavisnoti od pritisnutog tastera, 
     * postavlje se primitiva koja se iscrtava
     */
                 
        case '1':
                display_primitive = GL_POINTS;
                printf("Activated GL_POINTS\n");
                break;
    
        case '2':
                display_primitive = GL_LINES;
                printf("Activated GL_LINES\n");
                break;
        case '3':
                display_primitive = GL_LINE_STRIP;
                printf("Activated GL_LINE_STRIP\n");
                break;
        case '4':
                display_primitive = GL_LINE_LOOP;
                printf("Activated GL_LINE_LOOP\n");
                break;
        case '5':
                display_primitive = GL_TRIANGLES;
                printf("Activated GL_TRIANGLES\n");
                break;
        case '6':
                display_primitive = GL_TRIANGLE_STRIP;
                printf("Activated GL_TRIANGLE_STRIP\n");
                break;
        case '7':
                display_primitive = GL_TRIANGLE_FAN;
                printf("Activated GL_TRIANGLE_FAN\n");
                break;                
        case '8':
                display_primitive = GL_QUADS;
                printf("Activated GL_QUADS\n");
                break;
        case '9':
                display_primitive = GL_QUAD_STRIP;
                printf("Activated GL_QUAD_STRIP\n");
                break;
        case '0':
                display_primitive = GL_POLYGON;
                printf("Activated GL_POLYGON\n");
                break;
                
                //postavljamo da se pokazuje samo zadnje lice poligina
        case 'f':
                glEnable(GL_CULL_FACE);
                glCullFace(GL_FRONT);
                printf("Activated culling of GL_FRONT\n");
                break;
                
        case 'b':
                glEnable(GL_CULL_FACE);
                glCullFace(GL_BACK);
                printf("Activated culling of GL_BACK\n");
                break;
        case 'a':
            /* Postavljamo da se prikazuju oba lica poligona */
            glDisable(GL_CULL_FACE);
            printf("Deactivated culling\n");
            break;
            
            //ponovo se forsira da se iscrtava sadrzaj programa
    }
   
    glutPostRedisplay();
}

static void on_display(void){
 
    //brise se prethodni sadrzaj prozora
    glClear(GL_COLOR_BUFFER_BIT);
  
    /* Iscrtavamo tacke - jednu u koordinatnom pocetku,
    a ostale kao temena 10-ougla cije je teziste
    u koordinatnom pocetku. */
    glBegin(GL_POINTS); 
    
        glColor3f(1, 0, 0);
        glVertex2f(0, 0);
    
        int i;
    
        for(i = 0; i < NUMBER_OF_DOTS; i++){
            glVertex2f(
                    R * cos(2 * PI / NUMBER_OF_DOTS * i), 
                    R * sin(2 * PI / NUMBER_OF_DOTS * i)
            ); 
        }
    glEnd();
    
        /* Crta se primitiva cija su temena - jedno u koordinatnom
       pocetku, a ostala kao temena 10-ougla cije je teziste
       u koordinatnom pocetku. */
    glColor3f(0, 0, 1);
    
    glBegin(display_primitive);
        
        glVertex2f(0, 0);
            
        for(i = 0; i < NUMBER_OF_DOTS; i++){
            glColor3f(0, 0, 0.1 * i);
            glVertex2f(
                    R * cos(2 * PI / NUMBER_OF_DOTS * i), 
                    R * sin(2 * PI / NUMBER_OF_DOTS * i)
            ); 
        }
        
    glEnd();
    
    glutSwapBuffers();
    
}
