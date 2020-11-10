#include "microview.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <functional>

#include <MVCAPI.h>

namespace anakin
{

    MicroViewCamera::MicroViewCamera() :m_pcbF(NULL), m_nCardNo(0)
    {
    }

    MicroViewCamera::~MicroViewCamera()
    {
    }

    int MicroViewCamera::Open(int card_no)
    {
        if (m_nCardNo >= 0)
        {
            MVC_SetStreamHOOK(m_nCardNo, NULL, this);
        }
        m_nCardNo = card_no;
        MVC_SetNetPacketSize(m_nCardNo, 1440);
        return MVC_OpenDevice(m_nCardNo);
    }

    int MicroViewCamera::Close()
    {
        return MVC_CloseDevice(m_nCardNo);
    }

    int MicroViewCamera::StartCapture()
    {
        return MVC_EnableCapture(m_nCardNo);
    }

    int MicroViewCamera::StopCapture()
    {
        return MVC_DisableCapture(m_nCardNo);
    }

    void MicroViewCamera::operator>>(cv::Mat& img)
    {
        MVCFRAMEINFO FrameInfo;
        int ret = MVC_GetFrame(m_nCardNo, &FrameInfo);
        if (FrameInfo.lBufPtr != NULL)
        {
            cv::Mat tmp_frame(FrameInfo.Height, FrameInfo.Width, CV_8UC1, FrameInfo.lBufPtr);
            cv::cvtColor(tmp_frame, img, cv::COLOR_BayerGB2BGR);
        }
    }

} // namespace anakin
