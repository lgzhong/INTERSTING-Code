#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <time.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned char BYTE;
#define conv(r, c) ((r)*width+c)
#define convs(r, c) ((r)*swidth+c)
#define cw(i) (i>=xx1 && i<xx2)
#define ch(i) (i>=yy1 && i<yy2)
#define dist(p1, p2) abs(p1-p2)
#define random(n) (rand() % n)
#define random_1 ((double)rand() / (double)RAND_MAX)

//���嶯�����ʱ�Ƿ���ɫ��ת 
//#define reverse_bg
//��֡������ģ
//#define multi_bg_build
//�����Ƿ񽫽����Ƶ��������·��Ϊ��ǰĿ¼��result.yuv
//#define output_yuv
//�Ƿ����㶯��ĵ�Ԫ����ɫ������ĵ�Ԫ�񽫻��ɻ�ɫ 
//#define paint_cell
//�Ƿ���й�Ӱ���� 
//#define ghost_clear 

void yuv_process(const char* yuvData, char resultMatrix[128][128], bool* alarmResult);

void set_resolution(int width,int height);

void set_cell_split(int row , int col);

void set_detection_region(int x1, int y1, int x2, int y2);

void set_threshold_sensity(int t, int s);

void gauss_filter(float win[3][3], BYTE* yuvData);

void generateGaussianTemplate(float win[][3], int ksize, float sigma);

void write_yuv(BYTE* yuvData, string name="result.yuv");

void set_background(BYTE* yuvData);

void predict(BYTE* yuvData);

void corrode(BYTE* yuvData);

void swell(BYTE* yuvData);

void check(BYTE* yuvData, char resultMatrix[128][128], bool* alarm); 

void filter();

void update_bg(BYTE* yuvData);

void set_background_mul(BYTE* yuvData); 

void fill_in();