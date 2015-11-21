// Test.cpp : 定义控制台应用程序的入口点。
// 
#include "stdafx.h"  
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include "cv.h"  
#include "highgui.h"  
IplImage * img0=NULL;  
IplImage * img1=NULL;  
CvMat * img2=NULL;  
CvMat *img3=NULL;  
void onTrackerSlid(int pos)  
{  
    cvSub(img0, img1, img2,0);//图像相减  
    cvThreshold(img2, img3, pos, 255,0 (CV_THRESH_BINARY));//阈值处理  
    cvShowImage( "result", img3 );//显示处理后的图像图像  
      
}  
int main( int argc, char** argv )  
{    int thresh = 80;  
//载入图像  
img0=cvLoadImage("a1.jpg",0);//不可以再一次用IplImage定义，因为其已经是全局变量  
img1=cvLoadImage("a2.jpg",0);  
  
img2=cvCreateMat(img0->height,img0->width,CV_8UC1);//矩阵指针的初始化，与cvCreareImage类似  
img3=cvCreateMat(img0->height,img0->width,CV_8UC1);  
cvSmooth(img0, img0, CV_GAUSSIAN, 3, 0, 0,0);//高斯滤波平滑图像  
 
cvNamedWindow( "imge0", CV_WINDOW_AUTOSIZE);//创建窗口  
cvNamedWindow( "imge1", CV_WINDOW_AUTOSIZE);  
cvNamedWindow( "result", CV_WINDOW_AUTOSIZE);  
cvShowImage( "imge0", img0 );//显示图像  
cvShowImage( "imge1", img1 );  
cvCreateTrackbar("threshold","result",&thresh,255,onTrackerSlid);  
onTrackerSlid(thresh);  
cvWaitKey(0); //等待按键  
cvDestroyWindow( "Imge0" );//销毁窗口  
cvDestroyWindow( "Imge1" );  
cvDestroyWindow( "result" );  
cvReleaseImage( &img0); //释放图像  
cvReleaseImage( &img1);  
cvReleaseMat( &img2);  
cvReleaseMat( &img3);  
return -1;  
}  



