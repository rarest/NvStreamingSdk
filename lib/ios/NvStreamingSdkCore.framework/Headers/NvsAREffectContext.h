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
#pragma once

#import <Foundation/Foundation.h>
#import "NvsTimeline.h"
#import "NvsAssetPackageManager.h"
#import "NvsAVFileInfo.h"
#import "NvsVideoFrameRetriever.h"
#import "NvsVideoFrameReceiver.h"
#import "NvsCustomVideoFx.h"
#import "NvsCommonDef.h"


/*!
 *  \brief 内置人脸扭区上下文
 * 
 *  内置人脸扭区上下文包含一些对人脸特征的扭区接口
 */
NVS_EXPORT @interface NvsAREffectContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*!
 *  \brief 设置大眼程度
 *  \param ratio 缩放程度:最大值1,最小值:-1,默认值0
 */
- (void)setEyeEnlargeRatio:(float)ratio;


/*!
 *  \brief 设置瘦脸程度
 *  \param ratio 程度:最大值1,最小值:-1,默认值0
 */
- (void)setShrinkFaceRatio:(float)ratio;

/*!
 *  \brief 设置额头高度
 *  \param ratio 高度:最大值1,最小值:-1,默认值0
 */
- (void)setForeheadWarpRatio:(float)ratio;

/*!
 *  \brief 设置发际线高度
 *  \param ratio 高度:最大值1,最小值:-1,默认值0
 */
- (void)setHairlineWarpRatio:(float)ratio;

/*!
 *  \brief 设置颧骨宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 */
- (void)setMalarWarpRatio:(float)ratio;

/*!
 *  \brief 设置下颌大小
 *  \param ratio 大小:最大值1,最小值:-1,默认值0
 */
- (void)setJawWarpRatio:(float)ratio;

/*!
 *  \brief 设置下巴大小
 *  \param ratio 大小:最大值1,最小值:-1,默认值0
 */
- (void)setChinWarpRatio:(float)ratio;

/*!
 *  \brief 设置眉毛长度
 *  \param ratio 长度:最大值1,最小值:-1,默认值0
 */
- (void)setEyebrowWarpRatio:(float)ratio;

/*!
 *  \brief 设置眼间距
 *  \param ratio 间距:最大值1,最小值:-1,默认值0
 */
- (void)setEyeDistanceWarpRatio:(float)ratio;

/*!
 *  \brief 设置鼻梁长度
 *  \param ratio 长度:最大值1,最小值:-1,默认值0
 */
- (void)setNoseLengthWarpRatio:(float)ratio;

/*!
 *  \brief 设置鼻子宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 */
- (void)setNoseWidthWarpRatio:(float)ratio;

/*!
 *  \brief 设置嘴部宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 */
- (void)setMouthWidthWarpRatio:(float)ratio;

@end

