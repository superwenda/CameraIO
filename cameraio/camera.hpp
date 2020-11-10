#ifndef CAMERA_INCLUDE_HPP
#define CAMERA_INCLUDE_HPP
#include <exception>

namespace cv
{
    class Mat;
}

namespace anakin
{
    typedef int(CallbackFuncType)(const cv::Mat&);
    class Camera
    {
    private:

    public:
        Camera()
        {

        }
        virtual ~Camera()
        {

        }

        virtual int Open(int card_no) = 0;
        virtual int Close() = 0;
        virtual int StartCapture() = 0;
        virtual int StopCapture() = 0;
        virtual void operator>>(cv::Mat& img) = 0;
        virtual void RegisterFunc(CallbackFuncType& f)
        {
            throw std::exception("Method not implemented exception.");
        }

        virtual int SetExposure(int exposure)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int GetExposure(int& exposure)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int SetGain(int gain)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int GetGain(int& gain)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int SetGamma(float gamma)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int SetWidth(int width)
        {
            throw std::exception("Method not implemented exception.");
        }
        virtual int SetHeight(int height)
        {
            throw std::exception("Method not implemented exception.");
        }
    };

} // namespace anakin

#endif