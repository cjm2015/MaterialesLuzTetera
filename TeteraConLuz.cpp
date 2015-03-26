#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
double a1=0.329412f,a2= 0.223529f,a3=0.027451f,d1=0.780392f,d2=0.568627f,d3=0.113725f,s1=0.992157f,s2=0.941176f,s3=0.807843f,sh=27.8974f,n=0.1;
float shine=28.454;// declaracion de variables
int b=0;double a=150.0;
void keyboard(unsigned char key, int x, int y);//declarando la funcion
void PonerMateriales();//funcion que almacena los valores de las variables
void init(void)
{
	glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}
void reshape(int w, int h)
{
 glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
 glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
 glLoadIdentity();
// Usamos proyeccion ortogonal
 glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
 glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
 glLoadIdentity();
}
void display(void)
{
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode( GL_MODELVIEW_MATRIX );
 glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
 glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
 glRotated(-30.0, 0.0, 1.0, 0.0);
 GLfloat mat_ambient[] = {a1,a2,a3,n};
 GLfloat mat_diffuse[] = {d1,d2,d3,n};
 GLfloat mat_specular[] = {s1,s2,s3,n};
 GLfloat shine[] = {sh};
// Dibujamos una "Tetera" y le aplico el material
 glPushMatrix();
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
 glutSolidTeapot(a);
 glFlush();
}
int main(int argc, char **argv)
{
// Inicializo OpenGL
 glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
 glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
 glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
 glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
 glutCreateWindow ("Tetera");
// Inicializamos el sistema
 init();
glutDisplayFunc(display);
 	glutKeyboardFunc(keyboard);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}
void keyboard(unsigned char key, int x, int y)
{
	
    switch (key)
    {
		
    case '1':
        b=1;//con esta variable accedo al if especificado
        PonerMateriales();//funcion que maneja las variables para asignarlas al ambient difuce specular shine
        
        break;
    case '2':
        b=2;
        PonerMateriales();
        
        break;
    case '3':
        b=3;
        PonerMateriales();
        
        break;
    case '4':
        b=4;
        PonerMateriales();
        
        break;
    case '5':
    b=5;
    PonerMateriales();
    
            break;
    case 27:
        exit(0);// exit
    }
    glutPostRedisplay(); // actualización de visualización
}
void PonerMateriales()
{
	if(b==1){
		//a=130.0;//cambia el tamaño de la tetera
		a1=0.135;a2=0.2225;a3=0.1575;d1=0.54;d2=0.89;d3=0.63;s1=0.316228;s2=0.316228;s3=0.316228;shine=0.1;//aplicando los valores a las variables
		}
	if(b==2){
		//a=150.0;
		a1=0.05375;a2=0.05;a3=0.06625;d1=0.18675;d2=0.17;d3=0.22525;s1=0.332741;s2=0.328634;s3=0.346435;sh=0.3;
		}
	if(b==3){
		//a=170.0;
		a1=0.25;a2=0.29725;a3=0.29725;d1=1.0;d2=0.829;d3=0.829;s1=0.296648;s2=0.296648;s3=0.296648;sh=0.088;
		}
	if(b==4){
		//a=190.0;
		a1=0.1745;a2=0.01175;a3=0.01175;d1=1.61424;d2=0.04136;d3=0.04136;s1=0.727811;s2=0.626959;s3=0.636959;sh=0.6;
		}
	if(b==5){
		//a=210.0;
		a1=0.1;a2=0.18725;a3=0.1745;d1=0.396;d2=0.73151;d3=0.69102;s1=0.297254;s2=0.30829;s3=0.306678;sh=0.1;
		}
}
