//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Dec 29. 2016
//   Author:        NewAuto video team
//================================================================================

/*! \file NvsCommonDef.h
 * */
#pragma once

#include <stdint.h>

#define NVS_EXPORT  __attribute__((visibility("default")))

/*!
 *  \brief 音频采样格式
 */
typedef enum {
    NvsAudSmpFmt_None = -1,//!< \if ENGLISH None \else 无 \endif
    NvsAudSmpFmt_U8,       //!< \if ENGLISH unsigned 8 bit \else unsigned 8 bit \endif
    NvsAudSmpFmt_S16,      //!< \if ENGLISH signed 16 bit \else signed 16 bit \endif
    NvsAudSmpFmt_S32,      //!< \if ENGLISH signed 32 bit \else signed 32 bit \endif
    NvsAudSmpFmt_FLT,      //!< \if ENGLISH single precision float \else 单精度浮点数 \endif
    NvsAudSmpFmt_DBL,      //!< \if ENGLISH double precision float \else 双精度浮点数 \endif

    NvsAudSmpFmt_U8P,      //!< \if ENGLISH unsigned 8 bit,planer \else unsigned 8 bit 平面格式 \endif
    NvsAudSmpFmt_S16P,     //!< \if ENGLISH signed 16 bit,planer \else signed 16 bit 平面格式 \endif
    NvsAudSmpFmt_S32P,     //!< \if ENGLISH signed 32 bit,planer \else signed 32 bit 平面格式 \endif
    NvsAudSmpFmt_FLTP,     //!< \if ENGLISH single precision float,planar \else 单精度浮点数 平面格式\endif
    NvsAudSmpFmt_DBLP,     //!< \if ENGLISH double precision float,olanar \else 双精度浮点数 平面格式\endif

    NvsAudSmpFmt_Count
} NvsAudioSampleFormat;

/*! \if ENGLISH \else \brief 文件类型 \endif*/
typedef enum {
    NvsAVFileType_Unknown = -1,      /*!< 未知(-1) */
    NvsAVFileType_AudioVideo = 0,    /*!< 视频(0) */
    NvsAVFileType_Audio,             /*!< 音频 */
    NvsAVFileType_Image              /*!< 图片*/
} NvsAVFileType;

/*! \if ENGLISH \else \brief 视频旋转角度 \endif*/
typedef enum
{
    NvsVideoRotation_0 = 0,
    NvsVideoRotation_90,
    NvsVideoRotation_180,
    NvsVideoRotation_270
} NvsVideoRotation;

/*! \if ENGLISH \else \brief 片段在主题中的角色 \endif */
typedef enum NvsRoleInTheme
{
    NvsRoleInThemeGeneral,   //!< \if ENGLISH \else 通用 \endif
    NvsRoleInThemeTitle,     //!< \if ENGLISH \else 片头 \endif
    NvsRoleInThemeTrailer    //!< \if ENGLISH \else 片尾 \endif
} NvsRoleInTheme;

/*! \if ENGLISH \else \brief 字幕对齐方式 \endif*/
typedef enum NvsTextAlignment
{
    NvsTextAlignmentLeft = 0,
    NvsTextAlignmentCenter,
    NvsTextAlignmentRight
} NvsTextAlignment;

/*! \if ENGLISH \else \brief 片段在主题中的类型 \endif */
typedef enum NvsCategory
{
    NvsDefaultCategory,   //!< \if ENGLISH \else 默认类型 \endif
    NvsUserCategory,     //!< \if ENGLISH \else 用户自定义类型 \endif
    NvsThemeCategory    //!< \if ENGLISH \else 主题类型 \endif
} NvsCategory;

typedef enum NvsVideoFramePixelFormat
{
    NvsPixelFormat_Nv12,  //!< \if ENGLISH \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为VU分量交错 ) \endif
    NvsPixelFormat_YUV420 //!< \if ENGLISH \else  YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ) \endif
} NvsVideoFramePixelFormat;

/*! \if ENGLISH \else \brief 比例值 \endif*/
typedef struct {
    int num;    //!< \if ENGLISH Numerator \else 分子 \endif
    int den;    //!< \if ENGLISH Denominator \else 分母 \endif
} NvsRational;

typedef struct {
    int width;
    int height;
} NvsSize;

typedef struct {
    float left;
    float right;
    float bottom;
    float top;
} NvsRect;

/*! \if ENGLISH \else \brief 音频解析度 \endif */
typedef struct {
    unsigned int sampleRate; //!< \if ENGLISH \else 采样率 \endif
    NvsAudioSampleFormat sampleFormat; //!< \if ENGLISH \else 采样格式 \endif
    unsigned int channelCount; //!< \if ENGLISH \else 声道数 \endif
} NvsAudioResolution;

/*! \if ENGLISH \else \brief 视频解析度 \endif */
typedef struct {
    unsigned int imageWidth;  //!< \if ENGLISH \else 图像宽度 \endif
    unsigned int imageHeight; //!< \if ENGLISH \else 图像高度 \endif
    NvsRational imagePAR;     //!< \if ENGLISH \else 像素比（仅支持1:1）\endif
} NvsVideoResolution;

/*!
    \brief 自定义颜色类

    SDK中，NvsColor类属性r,g,b,a取值范围是[0,1]，而非[0,255]。
 */
typedef struct {
    float r, g, b, a;
} NvsColor;

/*! \if ENGLISH \else \brief 二维坐标结构 \endif */
typedef struct {
    float x, y;
} NvsPosition2D;
/*! \if ENGLISH \else \brief 三维坐标结构 \endif */
typedef struct {
    float x, y, z;
} NvsPosition3D;


#define NVS_VIDEO_FRAME_MAX_PLANES     4

typedef struct{
    //!< \if ENGLISH \else 获取到图像的宽度(以像素为单位) \endif
    int frameWidth;
    //!< \if ENGLISH \else 获取到图像的高度(以像素为单位) \endif
    int frameHeight;
    //!< \if ENGLISH \else 平面图像每行在Frame中占的字节数 \endif
    int planeRowPitch[NVS_VIDEO_FRAME_MAX_PLANES];
    void* planePtr[NVS_VIDEO_FRAME_MAX_PLANES];
    //!< \if ENGLISH \else 获取到图像的格式 \endif
    NvsVideoFramePixelFormat pixelFormat;
    //!< \if ENGLISH \else 获取到图像的时间戳（单位微秒） \endif
    int64_t frameTimestamp;
    bool isRec601; //!< \if ENGLISH \else 是否是BT.601 \endif
    bool isFullRangeYUV;

    int displayRotation; //!< \if ENGLISH \else 显示当前图像需要旋转的角度 \endif
    bool flipHorizontally; //!< \if ENGLISH \else 显示当前图像需要不需要水平翻转 \endif
} NvsVideoFrameInfo;
