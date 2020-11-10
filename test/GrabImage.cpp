#include <iostream>
#include <opencv2/opencv.hpp>
#include "microview.hpp"

int main()
{
    anakin::Camera* camera = new anakin::MicroViewCamera;
    std::cout << camera->Open(0) << "\n";
    std::cout << camera->StartCapture() << "\n";

    cv::Mat img;

    while (true)
    {
        *camera >> img;
        if (!img.empty())
            cv::imshow("camera", img);
        char key = cv::waitKey(1);
        if (key == 27)
            break;
    }
    camera->StopCapture();
    camera->Close();
    return 0;
}