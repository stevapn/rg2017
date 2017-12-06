#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* Funkcija koja vrsi OpenGL inicijalizaciju */
static void initialize(void);

/* Deklaracije callback funkcija */
static void on_keyboard(unsigned char key, int x, int y);
static void on_display(void);

int main(int argc, char** argv){
    
    //inicijalizacija GLUT-a
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_RGBA | \
                        GLUT_DEPTH | GLUT_DOUBLE);
    
    // Kreira se prozor
    glutInitWindowSize(300, 300);
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

   
    
}


//ako se pritisne na tastaturi dugme ESC
static void on_keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:    
                exit(EXIT_SUCCESS);
                break;    
    }
}

static void on_display(void){
 
  
    
    
}
