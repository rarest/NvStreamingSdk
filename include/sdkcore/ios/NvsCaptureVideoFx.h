//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jan 18. 2017
//   Author:        NewAuto video team
//================================================================================

#pragma once

#import "NvsFx.h"


/*!
 *  \brief
 *  采集视频特效类型
 */
typedef enum {
    NvsCaptureVideoFxType_Builtin = 0,
    NvsCaptureVideoFxType_Package,
    NvsCaptureVideoFxType_Custom
} NvsCaptureVideoFxType;

/*!
 *  \brief 采集视频特效

 *  采集视频特效是一种应用在视频采集时的特效。获取流媒体上下文(Streaming Context)实例后，可按内建方式，包裹方式，美颜方式来添加或移除多个采集视频特效。
 * 
 */
@interface NvsCaptureVideoFx : NvsFx

@property (readonly) NvsCaptureVideoFxType captureVideoFxType; //!< 采集视频特效类型
@property (readonly,retain) NSString *bultinCaptureVideoFxName; //!< 内嵌采集视频特效名字。如果不是内嵌采集视频特效返回nil
@property (readonly,retain) NSString *captureVideoFxPackageId; //!< 采集视频特效资源包ID。如果不是资源包采集视频特效返回nil
@property (readonly) unsigned int index;   //!< \if ENGLISH brief member variable description \else 视频特效索引 \endif

@end
