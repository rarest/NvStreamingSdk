//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jun 17. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"

/*!
 *  \brief
 *  时间线视频特效类型
 */
typedef enum {
    NvsTimelineVideoFxType_Builtin = 0,
    NvsTimelineVideoFxType_Package,
    NvsTimelineVideoFxType_Custom
} NvsTimelineVideoFxType;


/*!
    \brief 时间线视频特效
 */
@interface NvsTimelineVideoFx : NvsFx

@property (readonly) NvsTimelineVideoFxType timelineVideoFxType; //!< 时间线视频特效类型
@property (readonly,retain) NSString *bultinTimelineVideoFxName; //!< 内嵌时间线视频特效名字。如果不是内嵌时间线视频特效返回nil
@property (readonly,retain) NSString *timelineVideoFxPackageId; //!< 时间线视频特效资源包ID。如果不是资源包时间线视频特效返回nil
@property (readonly) int64_t inPoint; //!< \if ENGLISH \else 时间线视频特效在时间线上的入点 \endif
@property (readonly) int64_t outPoint; //!< \if ENGLISH \else 时间线视频特效在时间线上的出点 \endif

/*!
     \brief 改变时间线视频特效在时间线上的入点
     \param newInPoint 动画贴纸在时间线上的新的入点
     \return 返回时间线视频特效在时间线上最终的入点值
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeOutPoint:
     \sa movePosition:
 */
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*!
     \brief 改变时间线视频特效在时间线上的出点
     \param newOutPoint 时间线视频特效在时间线上的新的出点
     \return 返回时间线视频特效在时间线最终的出点值
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeInPoint:
     \sa movePosition:
 */
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*!
     \brief 改变时间线视频特效在时间线上的位置(入点和出点同时偏移offset值)
     \param offset 入点和出点改变的偏移值
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeInPoint:
     \sa changeOutPoint:
 */
- (void)movePosition:(int64_t)offset;

@end

