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
GLfloat c = M_PI / 180.0; //角度转换弧度，M_PI=3.14159…
GLint du = 90, oldmy = -1, oldmx = -1; //du是视点绕y轴的角度,opengl里默认y轴是上方向  
GLfloat r = 1.5f, h = 0.0f; //r是视点绕y轴的半径,h是视点高度即在y轴上的坐标  

int shape = 2;
int time;
int cnt = 1;
int cot = 1;
using namespace std;
void processMenuEvents(int option);
void Mouse(int button, int state, int x, int y);

void createGLUTMenus() {
	int menu;
	//创建菜单并告诉GLUT，processMenuEvents 处理菜单事件。
	menu = glutCreateMenu(processMenuEvents);
	//给菜单增加条目
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
	glutAttachMenu(GLUT_RIGHT_BUTTON);// 把菜单和鼠标右键关联起来。
	
}
void processMenuEvents(int option) {
	//option，就是传递过来的value 的值。
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
// 函数RenderScene用于在窗口中绘制需要的图形
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //执行实际的清除操作
	glLoadIdentity();//使坐标复位
	gluLookAt(r*cos(c*du), h, r*sin(c*du), 0, 0, 0, 0, 10, 0); //从视点看远点,y轴方向(0,1,0)是上方向  
	glColor3f(1.0, 0.0, 1.0); // 设置当前绘图使用的RGB颜色
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	double start = glutGet(GLUT_ELAPSED_TIME);

	if (cot == 3)
	{
		Draw(cot);
		glTranslatef(0.7, 0.0, 0.0);
		Draw(cot);
		glTranslatef(-1.4, 0.0, 0.0); //平移，位移量为向量(dx,dy,dz)
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// 刷新OpenGL命令队列
		glFlush();
		if (time != 0) {
			cout << time << endl;
		}

		glutSwapBuffers();
	}
	if (cot == 2)
	{
		Draw(cot);
		glTranslatef(1.0, 0.0, 0.0); //平移，位移量为向量(dx,dy,dz)
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// 刷新OpenGL命令队列
		glFlush();
		if (time!=0) {
			cout << time << endl;}
		
		glutSwapBuffers();
	}
	if (cot == 1) {
		Draw(cot);
		double end = glutGet(GLUT_ELAPSED_TIME);
		time = end - start;
		// 刷新OpenGL命令队列
		glFlush();
		//if (time!= 0) {
			cout << time << endl;
		//}
	
		glutSwapBuffers();
	}
}
void Mouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) //第一次鼠标按下时,记录鼠标在窗口中的初始坐标  
		oldmx = x, oldmy = y;
	RenderScene();
}
void onMouseMove(int x, int y) //处理鼠标拖动  
{
	du += x - oldmx; //鼠标在窗口x轴方向上的增量加到视点绕y轴的角度上，这样就左右转了  
	h += 0.03f*(y - oldmy); //鼠标在窗口y轴方向上的改变加到视点的y坐标上，就上下转了  
	if (h>1.0f) h = 1.0f; //视点y坐标作一些限制，不会使视点太奇怪  
	else if (h<-1.0f) h = -1.0f;
	oldmx = x, oldmy = y; //把此时的鼠标坐标作为旧值，为下一次计算增量做准备  
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
// 函数ChangeSize是窗口大小改变时调用的登记函数
void ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);//定义视区,x,y是指定窗口内视区左下角
	glMatrixMode(GL_PROJECTION); //GL_PROJECTION：投影矩阵，描述如何将一个物体投影到平面上； 
	glLoadIdentity();//使坐标复位
	gluPerspective(75.0f, (float)w / h, 0.5f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
}
// 函数SetupRC用于初始化，用来设置场景渲染状态

int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("The Experiment 1 of Computer Graphics");
	//init();
	// 初始化GLUT库OpenGL窗口的显示模式
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE	 | GLUT_RGB);
	// 创建一个名为GLRect的窗口
	/*glutCreateWindow("GLRect");*/
	// 设置当前窗口的显示回调函数和窗口再整形回调函数
	init();
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	//glutIdleFunc(RenderScene);  
	glutMouseFunc(Mouse);
	glutMotionFunc(onMouseMove);
	createGLUTMenus();
	// 启动主GLUT事件处理循环
	glutMainLoop();
	return 0;
}