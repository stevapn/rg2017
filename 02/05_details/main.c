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

    //velicina tacke
    float point_size;
    
    // Minimalna i maksimalna dozvoljena velicina tacaka
    GLfloat point_size_range[2];

    // Debljina linije
    GLfloat line_width;
    
    // Minimalna i maksimalna dozvoljena debljina linije
    GLfloat line_width_range[2];
    
    //postavlja se boja pozadine
    glClearColor(0.75, 0.75, 0.75, 0);
    
    //Ukljucije se testiranje z-koordinate piksela
    glEnable(GL_DEPTH_TEST);
    
    //podesava se velicina tacke
    glPointSize(6);
    
    // informacije o celicine tacke
    glGetFloatv(GL_POINT_SIZE, &point_size);
    printf("Current point size: %f\n", point_size);
        
    // informacije o celicine tacke
    glGetFloatv(GL_POINT_SIZE_RANGE, point_size_range);
    printf("Minimal point size: %f\n", point_size_range[0]);
    printf("Maximal point size: %f\n", point_size_range[1]);
    
    //postavjla se debljina linije
    glLineWidth(13);

        // trenutna debljina linije
    glGetFloatv(GL_LINE_WIDTH, &line_width);
    printf("current line width: %g\n", line_width);
    
    glGetFloatv(GL_LINE_WIDTH_RANGE, line_width_range);
    printf("Minimal line width: %g\n", line_width_range[0]);
    printf("Maximal line width: %g\n", line_width_range[1]);
    
    
    //podeesavanje paterna kojim ce biti iscrtane linije
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xf8f8);
    
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
 
    //brisanje sadrzaja ekrana
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //crtanje tacaka
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
        glVertex3f(0, 0, 0);
        glVertex3f(0.75, 0, 0);
        glVertex3f(0.75, 0.75, 0);
        glVertex3f(0, 0.75, 0);
    glEnd();
    
    //crtaju se linije
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
        glVertex3f(-0.75, -0.75, 0);
        glVertex3f(-0.25, -0.75, 0);
        glVertex3f(-0.25, -0.25, 0);
        glVertex3f(-0.75, -0.25, 0);
    glEnd();
    
    
    glutSwapBuffers();
}
