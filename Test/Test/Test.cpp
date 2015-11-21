// Test.cpp : �������̨Ӧ�ó������ڵ㡣
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
    cvSub(img0, img1, img2,0);//ͼ�����  
    cvThreshold(img2, img3, pos, 255,0 (CV_THRESH_BINARY));//��ֵ����  
    cvShowImage( "result", img3 );//��ʾ������ͼ��ͼ��  
      
}  
int main( int argc, char** argv )  
{    int thresh = 80;  
//����ͼ��  
img0=cvLoadImage("a1.jpg",0);//��������һ����IplImage���壬��Ϊ���Ѿ���ȫ�ֱ���  
img1=cvLoadImage("a2.jpg",0);  
  
img2=cvCreateMat(img0->height,img0->width,CV_8UC1);//����ָ��ĳ�ʼ������cvCreareImage����  
img3=cvCreateMat(img0->height,img0->width,CV_8UC1);  
cvSmooth(img0, img0, CV_GAUSSIAN, 3, 0, 0,0);//��˹�˲�ƽ��ͼ��  
 
cvNamedWindow( "imge0", CV_WINDOW_AUTOSIZE);//��������  
cvNamedWindow( "imge1", CV_WINDOW_AUTOSIZE);  
cvNamedWindow( "result", CV_WINDOW_AUTOSIZE);  
cvShowImage( "imge0", img0 );//��ʾͼ��  
cvShowImage( "imge1", img1 );  
cvCreateTrackbar("threshold","result",&thresh,255,onTrackerSlid);  
onTrackerSlid(thresh);  
cvWaitKey(0); //�ȴ�����  
cvDestroyWindow( "Imge0" );//���ٴ���  
cvDestroyWindow( "Imge1" );  
cvDestroyWindow( "result" );  
cvReleaseImage( &img0); //�ͷ�ͼ��  
cvReleaseImage( &img1);  
cvReleaseMat( &img2);  
cvReleaseMat( &img3);  
return -1;  
}  



