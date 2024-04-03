// 2024/04/04
// 自力AC

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, const char *argv[])
{

    if (argc != 2)
    {
        cout << "usage" << endl;
    }

    Mat im_in = imread(argv[1], 1);
    if (!im_in.data)
    {
        cout << "No image data" << endl;
        return -1;
    }

    int j_height = im_in.rows;
    int i_width = im_in.cols;
    int size = j_height * i_width;
    Mat im_out = Mat::zeros(i_width, j_height, CV_8UC1); // 記述注意

    for (int j = 0; j < j_height; j++)
    {
        for (int i = 0; i < i_width; i++)
        { // 答えはdoubleじゃなくてfloatでやってる
            uchar y = (uchar)(0.2126 * (double)im_in.at<Vec3b>(j, i)[2] + 0.7152 * (double)im_in.at<Vec3b>(j, i)[1] + 0.0722 * (double)im_in.at<Vec3b>(j, i)[0]);
            im_out.at<uchar>(j, i) = y;
        }
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    cv::imshow("Display Image", im_out);
    cv::waitKey(0);

    cv::destroyAllWindows();
    // save image
    cv::imwrite("../output/2.bmp", im_out);

    return 0;
}