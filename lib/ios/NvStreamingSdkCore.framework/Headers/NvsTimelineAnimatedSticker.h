//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Feb 17. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"
#import <CoreGraphics/CGGeometry.h>

/*!
    \brief 时间线动画贴纸，带有动画效果的贴纸
   
    时间线动画贴纸是视频编辑时使用的一种美化特效，叠加在视频上会产生一些特殊效果。编辑视频时，可通过时间线(Time Line)来添加和移除动画贴纸。如果添加的贴纸位置不合理，还可进行调整移动。
    \warning NvsTimelineAnimatedSticker类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsTimelineAnimatedSticker : NvsFx

@property (readonly) BOOL isPanoramic;  //!< 是否为全景图动画贴纸贴纸 \since 1.6.0
@property (nonatomic) BOOL clipAffinityEnabled; //!< 是否开启与clip的亲和关系 \since 1.7.1
@property (readonly) int64_t inPoint; //!< 动画贴纸在时间线上显示的入点（单位微秒）
@property (readonly) int64_t outPoint; //!< 动画贴纸在时间线上显示的出点（单位微秒）

/*!
    \brief 获取动画贴纸包ID
    \return 返回获取动画贴纸包ID
    \since 1.7.0
 */
- (NSString *)getAnimatedStickerPackageId;

/*!
     \brief 改变动画贴纸在时间线上显示的入点
     \param newInPoint 动画贴纸在时间线上的新的入点（单位微秒）
     \return 返回动画贴纸在时间线上的显示的入点值（单位微秒）
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeOutPoint:
     \sa movePosition:
 */
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*!
     \brief 改变动画贴纸在时间线上显示的出点
     \param newOutPoint 动画贴纸在时间线上的新的出点（单位微秒）
     \return 返回动画贴纸在时间线上的显示的出点值（单位微秒）
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeInPoint:
     \sa movePosition:
 */
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*!
     \brief 改变动画贴纸在时间线上的显示位置(入点和出点同时偏移offset值)
     \param offset 入点和出点改变的偏移值（单位微秒）
     \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
     \sa changeInPoint:
     \sa changeOutPoint:
 */
- (void)movePosition:(int64_t)offset;

/*!
     \brief 设置缩放
     \param scale 缩放值
     \sa getScale
 */
- (void)setScale:(float)scale;

/*!
     \brief 获取缩放值
     \return 返回获取的缩放值
     \sa setScale:
 */
- (float)getScale;

/*!
     \brief 设置水平翻转
     \param flip 是否水平翻转。true表示水平翻转，false则不翻转
     \sa getHorizontalFlip
 */
- (void)setHorizontalFlip:(bool)flip;

/*!
     \brief 获取水平翻转状态
     \return 返回BOOL值，表示水平翻转状态。YES表示已翻转，NO则未翻转
     \sa setHorizontalFlip:
 */
- (BOOL)getHorizontalFlip;

/*!
     \brief 设置竖直翻转
     \param flip 是否竖直翻转。true表示竖直翻转，false则不翻转
     \sa getVerticalFlip
 */
- (void)setVerticalFlip:(bool)flip;

/*!
     \brief 获取竖直翻转状态
     \return 返回BOOL值，表示竖直翻转状态。YES表示已翻转，NO则未翻转
     \sa setVerticalFlip:
 */
- (BOOL)getVerticalFlip;

/*!
     \brief 设置旋转角度
     \param angle 旋转角度值
     \sa getRotationZ
 */
- (void)setRotationZ:(float)angle;

/*!
     \brief 获取旋转角度值
     \return 返回获取的旋转角度值
     \sa setRotationZ:
 */
- (float)getRotationZ;

/*!
     \brief 设置平移
     \param translation 平移位置
     \sa getTransltion
     \sa translateAnimatedSticker:
 */
- (void)setTranslation:(CGPoint)translation;

/*!
     \brief 获取平移位置
     \return 返回CGPoint对象，表示获取的平移位置
     \sa setTranslation:
 */
- (CGPoint)getTransltion;

/*!
     \brief 平移动画贴纸
     \param translationOffset 动画贴纸平移的水平和垂直的偏移值
     \since 1.8.1
     \sa setTranslation:
     \sa getTranslation
 */
- (void)translateAnimatedSticker:(CGPoint)translationOffset;

/*!
     \brief 缩放动画贴纸
     \param scaleFactor 动画贴纸缩放的因子
     \param anchor 动画贴纸缩放的锚点
     \since 1.8.1
 */
- (void)scaleAnimatedSticker:(float)scaleFactor anchor:(CGPoint)anchor;

/*!
     \brief 旋转动画贴纸
     \param angle 动画贴纸旋转的角度
     \param anchor 动画贴纸旋转的锚点
     \since 1.8.1
     \sa rotateAnimatedSticker:
 */
- (void)rotateAnimatedSticker:(float)angle anchor:(CGPoint)anchor;

/*!
     \brief 以动画贴纸中心点为锚点旋转动画贴纸
     \param angle 动画贴纸旋转的角度
     \since 1.8.1
     \sa rotateAnimatedSticker:anchor:
 */
- (void)rotateAnimatedSticker:(float)angle;

/*!
     \brief 获取原始包围矩形框
     \return 返回NvsRect对象，表示获取的原始包围矩形框
 */
- (NvsRect)getOriginalBoundingRect;

/*!
    \brief 获取动画贴纸的原始包围矩形框变换后的顶点位置
    \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始包围矩形框的左上，左下，右下，右上顶点
    \since 1.4.0
 */
- (NSArray *)getBoundingRectangleVertices;

/*!
    \brief 对动画贴纸设置中心点的极角。只对全景图动画贴纸有效
    \param centerPolarAngle 中心点的极角，单位为角度
    \since 1.6.0
 */
- (void)setCenterPolarAngle:(float)centerPolarAngle;

/*!
    \brief 获取动画贴纸中心点的极角。只对全景图动画贴纸有效
    \return 返回动画贴纸中心点的极角，单位为角度
    \since 1.6.0
 */
- (float)getCenterPolarAngle;

/*!
    \brief 对动画贴纸设置中心点的方位角。只对全景图动画贴纸有效
    \param centerAzimuthAngle 中心点的极角，单位为角度
    \since 1.6.0
 */
- (void)setCenterAzimuthAngle:(float)centerAzimuthAngle;

/*!
    \brief 获取动画贴纸中心点的方位角。只对全景图动画贴纸有效
    \return 返回动画贴纸中心点的方位角，单位为角度
    \since 1.6.0
 */
- (float)getCenterAzimuthAngle;

/*!
    \brief 对动画贴纸设置极角的张角。只对全景图动画贴纸有效
    \param polarAngleRange 极角的张角，单位为角度
    \since 1.6.0
 */
- (void)setPolarAngleRange:(float)polarAngleRange;

/*!
    \brief 获取动画贴纸极角的张角。只对全景图动画贴纸有效
    \return 返回动画贴纸极角的张角，单位为角度
    \since 1.6.0
 */
- (float)getPolarAngleRange;

/*!
    \brief 获取动画贴纸与极角垂直的张角。只对全景图动画贴纸有效
    \return 返回动画贴纸与极角垂直的张角，单位为角度
    \since 1.7.0
 */
- (float)getOrthoAngleRange;

/*!
     \brief 设置贴纸Zzhi值
     \param value 表示贴纸Z值
     \sa getZValue
 */
- (void)setZValue:(float)value;

/*!
     \brief 获取贴纸Z值
     \return 返回贴纸Z值
     \sa setZValue:
 */
- (float)getZValue;

@end

