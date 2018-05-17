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
 *  \brief 粒子特效上下文
 * 
 *  粒子特效上下文类可视作调整粒子效果的入口。可以调整粒子发射器的位置，大小，发射速率等
 */
NVS_EXPORT @interface NvsAREffectContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*!
 *  \brief 设置大眼进度
 *  \param ratio 进度:最大值1,最小值:0,默认值0
 */
- (void)setEyeEnlageRatio:(float)ratio;


/*!
 *  \brief 设置瘦脸进度
 *  \param ratio 进度:最大值1,最小值:-1,默认值0
 */
- (void)setShrinkFaceRatio:(float)ratio;

@end

