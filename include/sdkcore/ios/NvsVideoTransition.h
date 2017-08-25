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

/*! \file NvsVideoTransition.h */
#pragma once

#import "NvsFx.h"


/*!
 *  \brief
 *  采集视频特效类型
 */
typedef enum {
    NvsVideoTransitionType_Builtin = 0,
    NvsVideoTransitionType_Package,
} NvsVideoTransitionType;

/*!
    \brief 视频转场，片段间切换的特效
 
    轨道上有多个片段，转场是从一个视频片段播放到另一个视频片段的衔接过渡效果，而在有间隙的片段之间不能添加视频转场。目前支持多种视频转场，
    包括Fade(淡入淡出)、Turning(翻转)、Swap(层叠)、Stretch In(伸展进入)、Page Curl(卷页)、Lens Flare(镜头眩光)、Star(星形)、Dip To Black(闪黑)、Dip To White(闪白)、
    Push To Right(右推拉)、Push To Top(上推拉)、Upper Left Into(斜推)。
    <br>每种视频转场都可通过视频轨道(NvsVideoTrack)来设置和获取。默认转场是Fade(淡入淡出)。
 */
@interface NvsVideoTransition : NvsFx

@property (readonly) NvsVideoTransitionType videoTransitionType; //!< 视频转场类型
@property (readonly,retain) NSString *bultinVideoTransitionName; //!< 内嵌视频转场名字。如果不是内嵌视频转场返回nil
@property (readonly,retain) NSString *videoTransitionPackageId; //!< 视频转场资源包ID。如果不是资源包视频转场返回nil

@end
