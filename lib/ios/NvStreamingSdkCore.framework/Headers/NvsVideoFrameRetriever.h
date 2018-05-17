//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    May 2. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"

/*!
 *  \brief 生成提取视频帧的高度级别
 *  \since 1.2.0
 */
typedef enum {
    NvsVideoFrameHeightGrade360 = 0,  //!< 生成视频帧高度360像素
    NvsVideoFrameHeightGrade480,      //!< 生成视频帧高度480像素
    NvsVideoFrameHeightGrade720       //!< 生成视频帧高度720像素
} NvsVideoFrameHeightGrade;

@class UIImage;
/*!
 *  \brief 视频帧提取
 *
 *  视频帧提取类，可以获取某一时刻的原始视频帧图像。
 *  \warning NvsVideoFrameRetriever类中，所有public API不仅可以在UI线程使用，也可以跨线程使用！！！
 *  \since 1.2.0
 */
NVS_EXPORT @interface NvsVideoFrameRetriever : NSObject
/*!
 *  \brief 获取某一时刻视频帧图像。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param time 获取视频帧的时间值(单位微秒)
 *  \param videoFrameHeightGrade 生成视频帧图像的高度级别
 *  \return 返回UIImage对象，表示某一时刻视频帧图像
 */
- (UIImage *)getFrameAtTime:(int64_t)time videoFrameHeightGrade:(NvsVideoFrameHeightGrade)videoFrameHeightGrade;
/*!
 *  \brief 获取某一时刻视频帧图像，可以自定义视频帧的高度。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param time 获取视频帧的时间值(单位微秒)
 *  \param videoFrameHeight 自定义视频帧高度
 *  \return 返回UIImage对象，表示某一时刻视频帧图像
 *  \since 1.15.0
 */
- (UIImage *)getFrameAtTimeWithVideoFrameHeight:(int64_t)time videoFrameHeight:(unsigned int)videoFrameHeight;
@end

