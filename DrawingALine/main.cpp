/**
void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
 Parameters:
img – Image.
pt1 – First point of the line segment.
pt2 – Second point of the line segment.
color – Line color.
thickness – Line thickness.
lineType – Type of the line:
8 (or omitted) - 8-connected line.
4 - 4-connected line.
CV_AA - antialiased line.
shift – Number of fractional bits in the point coordinates.

Copyright antonioposabella 28/1/17


**/

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {

Mat matrice;
matrice  = Mat::zeros(400, 400, CV_8UC3);

line(matrice,Point(15,20),Point(30,30),Scalar(110,220,0),2,8,0);
putText(matrice,"IMAGE",Point(500,100),FONT_HERSHEY_COMPLEX_SMALL,1,Scalar(0,200,200),4);
imshow("Image",matrice);


waitKey(0);


  return 0;
}
