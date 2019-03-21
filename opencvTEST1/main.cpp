#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/stitching/stitcher.hpp>

using namespace std;
using namespace cv;
bool try_use_gpu = false;//是否使用GPU，否
vector<Mat> imgs;
string result_name = "dst1.jpg";

int main(int argc, char * argv[])
{
    Mat img1 = imread("2.jpg");
    Mat img2 = imread("3.jpg");

    imshow("p1", img1); 
    imshow("p2", img2);

    if (img1.empty() || img2.empty())
    {
        cout << "Can't read image" << endl;
        return -1;
    }

    imgs.push_back(img1);
    imgs.push_back(img2);


    Stitcher stitcher = Stitcher::createDefault(try_use_gpu); // 使用stitch函数进行拼接
   

    Mat pano; 
    Stitcher::Status status = stitcher.stitch(imgs, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }
    imwrite(result_name, pano);
    Mat pano2 = pano.clone();   

    imshow("全景图像", pano);
	waitKey(600000);
   
        return 0;
}
