#include "stdafx.h"
#include <windows.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<iostream>
#define M_PI 3.14159
#define POINTS 1
#define LINES 2
#define LINE_STRIP 3
#define LINE_LOOP 4
#define TRIANGLES 5
#define TRIANGLE_STRIP 6
#define TRIANGLE_FAN 7
#define QUADS 8
#define QUAD_STRIP 9
#define POLYGON 10
#define DOUBLE_TRIANGLES 11
#define DOUBLE_QUAD_STRIP 12
#define TRIBLE_TRIANGLES 13
#define TRIBLE_QUAD_STRIP 14
GLint phi;
GLfloat theta, x, y, z;
GLfloat c = M_PI / 180.0; //�Ƕ�ת�����ȣ�M_PI=3.14159��
GLint du = 90, oldmy = -1, oldmx = -1; //du���ӵ���y��ĽǶ�,opengl��Ĭ��y�����Ϸ���  
GLfloat r = 1.5f, h = 0.0f; //r���ӵ���y��İ뾶,h���ӵ�߶ȼ���y���ϵ�����  

int shape = 2;
int time;
int cnt = 1;
int cot = 1;
using namespace std;
void processMenuEvents(int option);
void Mouse(int button, int state, int x, int y);

void createGLUTMenus() {
	int menu;
	//�����˵�������GLUT��processMenuEvents ����˵��¼���
	menu = glutCreateMenu(processMenuEvents);
	//���˵�������Ŀ
	glutAddMenuEntry("POINTS", POINTS);
	glutAddMenuEntry("LINES", LINES);
	glutAddMenuEntry("LINE_STRIP", LINE_STRIP);
	glutAddMenuEntry("LINE_LOOP", LINE_LOOP);
	glutAddMenuEntry("TRIANGLES", TRIANGLES);
	glutAddMenuEntry("TRIANGLE_STRIP", TRIANGLE_STRIP);
	glutAddMenuEntry("TRIANGLE_FAN", TRIANGLE_FAN);
	glutAddMenuEntry("QUADS", QUADS);
	glutAddMenuEntry("QUAD_STRIP", QUAD_STRIP);
	glutAddMenuEntry("POLYGON", POLYGON);
	glutAddMenuEntry("DOUBLE_TRIANGLES", DOUBLE_TRIANGLES);
	glutAddMenuEntry("DOUBLE_QUAD_STRIP", DOUBLE_QUAD_STRIP);
	glutAddMenuEntry("TRIBLE_TRIANGLES", TRIBLE_TRIANGLES);
	glutAddMenuEntry("TRIBLE_QUAD_STRIP", TRIBLE_QUAD_STRIP);
	glutAttachMenu(GLUT_RIGHT_BUTTON);// �Ѳ˵�������Ҽ�����������
	
}
void processMenuEvents(int option) {
	//option�����Ǵ��ݹ�����value ��ֵ��
	switch (option) {
	case POINTS:
		shape = 0;  cot = 1;
		break;
	case LINES:
		shape = 1;  cot = 1;
		; break;
	case LINE_STRIP:
		shape = 2;  cot = 1;
		; break;
	case LINE_LOOP:
		shape = 3; cot = 1;
		break;
	case TRIANGLES:
		shape = 4;  cot = 1;
		break;
	case TRIANGLE_STRIP:
		shape = 5;  cot = 1;
		break;
	case TRIANGLE_FAN:
		shape = 6;  cot = 1;
		break;
	case QUADS:
		shape = 7;  cot = 1;
		break;
	case QUAD_STRIP:
		shape = 8;  cot = 1;
		break;
	case POLYGON:
		shape = 9;  cot = 1;
		break;
	case DOUBLE_TRIANGLES:
		shape = 6; cot = 2;
		break;
	case DOUBLE_QUAD_STRIP:
		shape = 8;  cot = 2;
		break;
	case TRIBLE_TRIANGLES:
		shape = 6;  cot = 3;
		break;
	case TRIBLE_QUAD_STRIP:
		shape = 8;  cot = 3;
		break;
	}
	
}
void Draw(int cnt) {
	for (phi = -80; phi <= 80.0; phi += 20)
	{
		switch (shape)
		{
		case 0:
			glBegin(GL_POINTS);
			break;
		case 1:
			glBegin(GL_LINES);            
			break;
		case 2:
			glBegin(GL_LINE_STRIP);                
			break;
		case 3:
			glBegin(GL_LINE_LOOP); 
			break;
		case 4:
			glBegin(GL_TRIANGLES);                
			break;
		case 5:
			glBegin(GL_TRIANGLE_STRIP);    
			break;
		case 6:
			glBegin(GL_TRIANGLE_FAN);        
			break;
		case 7:
			glBegin(GL_QUADS);         
			break;
		case 8:
			glBegin(GL_QUAD_STRIP);             
			break;
		case 9:
			glBegin(GL_POLYGON);    
			break;
		}
		for (theta = -180.0; theta <= 180.0; theta += 20.0)
		{
			x = sin(c*theta)*cos(c*phi);
			y = cos(c*theta)*cos(c*phi);
			z = sin(c*phi);
			glVertex3d(x/cnt, y/cnt , z / cnt);
			x = sin(c*theta)*cos(c*(phi + 20.0));
			y = cos(c*theta)*cos(c*(phi + 20.0));
			z = sin(c*(phi + 20.0));
			glVertex3d(x / cnt, y / cnt, z / cnt);
		}
		glEnd();
	}
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x / cnt, y / cnt, z / cnt);
	c = M_PI / 180.0;
	z = sin(c*80.0);
	for (theta = -180.0; theta <= 180.0; theta += 20.0)
	{
		x = sin(c*theta)*cos(c*80.0);
		y = cos(c*theta)*cos(c*80.0);
		glVertex3d(x / cnt, y / cnt, z / cnt);
	}
	glEnd();
	x = y = 0;
	z = -1;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x / cnt, y / cnt, z / cnt);
	z = -sin(c*80.0);
	for (theta = -180.0; theta <= 180.0; theta += 20.0)
	{
		x = sin(c*theta)*cos(c*80.0);
		y = cos(c*theta)*cos(c*80.0);
		glVertex3d(x / cnt, y / cnt, z / cnt);
	}
	glEnd();
}
// ����RenderScene�����ڴ����л�����Ҫ��ͼ��
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //ִ��ʵ�ʵ��������
	glLoadIdentity();//ʹ���긴λ
	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 10, 0); //���ӵ㿴Զ��,y�᷽��(0,1,0)���Ϸ���  
	glColor3f(1.0, 0.0, 1.0); // ���õ�ǰ��ͼʹ�õ�RGB��ɫ
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	double start = glutGet(GLUT_ELAPSED_TIME);

	if (cot == 3)
	{
		Draw(cot);
		glTranslatef(0.7, 0.0, 0.0);
		Draw(cot);
		glTranslatef(-1.4, 0.0, 0.0); //ƽ�ƣ�λ����Ϊ����(dx,dy,dz)
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// ˢ��OpenGL�������
		glFlush();
		if (time != 0) {
			cout << time << endl;
		}

		glutSwapBuffers();
	}
	if (cot == 2)
	{
		Draw(cot);
		glTranslatef(1.0, 0.0, 0.0); //ƽ�ƣ�λ����Ϊ����(dx,dy,dz)
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// ˢ��OpenGL�������
		glFlush();
		if (time!=0) {
			cout << time << endl;}
		
		glutSwapBuffers();
	}
	if (cot == 1) {
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// ˢ��OpenGL�������
		glFlush();
		//if (time!= 0) {
			cout << time << endl;
		//}
	
		glutSwapBuffers();
	}
}
void Mouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) //��һ����갴��ʱ,��¼����ڴ����еĳ�ʼ����  
		oldmx = x, oldmy = y;
	RenderScene();
}
void onMouseMove(int x, int y) //��������϶�  
{
	du += x - oldmx; //����ڴ���x�᷽���ϵ������ӵ��ӵ���y��ĽǶ��ϣ�����������ת��  
	h += 0.03f*(y - oldmy); //����ڴ���y�᷽���ϵĸı�ӵ��ӵ��y�����ϣ�������ת��  
	if (h>1.0f) h = 1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫���  
	else if (h<-1.0f) h = -1.0f;
	oldmx = x, oldmy = y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼��  
	RenderScene();
}
void init()
{
	glEnable(GL_DEPTH_TEST);


	GLfloat ambient[] = { 1.0, 1.0, 1.0, 3.0 };
	GLfloat diffuse[] = { 0, 0.8, 1, 3.0 };
	GLfloat position[] = { 0.0, 4.0, 3.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0.0, 0.1, 0.1, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
// ����ChangeSize�Ǵ��ڴ�С�ı�ʱ���õĵǼǺ���
void ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);//��������,x,y��ָ���������������½�
	glMatrixMode(GL_PROJECTION); //GL_PROJECTION��ͶӰ����������ν�һ������ͶӰ��ƽ���ϣ� 
	glLoadIdentity();//ʹ���긴λ
	gluPerspective(75.0f, (float)w / h, 0.5f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
}
// ����SetupRC���ڳ�ʼ�����������ó�����Ⱦ״̬

int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("The Experiment 1 of Computer Graphics");
	//init();
	// ��ʼ��GLUT��OpenGL���ڵ���ʾģʽ
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE	 | GLUT_RGB);
	// ����һ����ΪGLRect�Ĵ���
	/*glutCreateWindow("GLRect");*/
	// ���õ�ǰ���ڵ���ʾ�ص������ʹ��������λص�����
	init();
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	//glutIdleFunc(RenderScene);  
	glutMouseFunc(Mouse);
	glutMotionFunc(onMouseMove);
	createGLUTMenus();
	// ������GLUT�¼�����ѭ��
	glutMainLoop();
	return 0;
}