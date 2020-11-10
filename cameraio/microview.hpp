#ifndef MICROVIEW_INCLUDE_HPP
#define MICROVIEW_INCLUDE_HPP

#include "camera.hpp"
#include <afxwin.h>
namespace anakin
{
    class MicroViewCamera : public Camera
    {
    private:
        CallbackFuncType* m_pcbF;
        int m_nCardNo;
    public:
        MicroViewCamera();
        virtual ~MicroViewCamera();

        virtual int Open(int card_no);
        virtual int Close();
        virtual int StartCapture();
        virtual int StopCapture();

        virtual void operator>>(cv::Mat& img);


    };
} // namespace anakin

#endif