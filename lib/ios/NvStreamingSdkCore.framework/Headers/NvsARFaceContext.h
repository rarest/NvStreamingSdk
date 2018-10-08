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

@protocol NvsARFaceContextDelegate <NSObject>
@optional

/*!
 *  \brief 通知人脸道具开始加载
 *  \param itemPath 人脸道具路径
 */
- (void)notifyFaceItemLoadingBegin:(NSString *)itemPath ;


/*!
 *  \brief 通知人脸道具加载完成
 */
- (void)notifyFaceItemLoadingFinish ;

@end

/*!
 *  \brief 粒子特效上下文
 *
 *  人脸特效上下文类可视作调整粒子效果的入口。
 *  \warning NvsParticleSystemContext类中，所有public API都在UI线程使用！！！
 */
@interface NvsARFaceContext : NSObject

@property (nonatomic, weak) id<NvsARFaceContextDelegate> delegate;

- (void)setInternalContext:(void *)internalContext;
- (bool)isFaceTracking;

@end
