﻿//================================================================================
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
/*! \file NvsVideoClip.h
 */
#pragma once

#import "NvsCommonDef.h"
#import "NvsClip.h"
#import "NvsCustomVideoFx.h"


typedef enum NvsVideoClipType {
    NvsVideoClipType_AV = 0,   /*!< 音视频(0) */
    NvsVideoClipType_Image,    /*!< 图片*/
} NvsVideoClipType;  /*!< 片段类型 */

/*!
 *  \brief 图片片段运作模式
 *  \since 1.1.0
 */
typedef enum {
    NvsStreamingEngineImageClipMotionMode_LetterBoxZoomIn = 0, //!< 放大
    NvsStreamingEngineImageClipMotionMode_LetterBoxZoomOut,    //!< 缩小
    NvsStreamingEngineImageClipMotionMode_ROI                  //!< 图片片段ROI(Region Of Interesting)
} NvsStreamingEngineImageClipMotionMode;

typedef enum NvsSourceBackgroundMode {
    NvsSourceBackgroundModeColorSolid = 0,   /*!< 纯色(0) */
    NvsSourceBackgroundModeBlur,    /*!< 模糊*/
} NvsSourceBackgroundMode;  /*!< 背景模式 */

typedef enum NvsClipWrapMode {
    NvsClipWrapMode_Repeat_LastFrame = 0,
    NvsClipWrapMode_Repeat_FirstFrame = 1,
    NvsClipWrapMode_Repeat = 2
} NvsClipWrapMode;

typedef enum NvsExtraVideoRotation {
    NvsExtraVideoRotation_0 = 0,
    NvsExtraVideoRotation_90 = 1,
    NvsExtraVideoRotation_180 = 2,
    NvsExtraVideoRotation_270 = 3
} NvsExtraVideoRotation;

@class NvsVideoFx;

/*!
    \brief 视频片段，对视频文件的描述

    视频片段源可以是视频或者图片。每个视频片段可以修改其裁剪入点、裁剪出点以及播放速度，也可以设置摇摄和扫描。编辑视频时，可以按特效类型的不同（内建特效，包裹式特效，美颜特效）添加或者插入多个视频特效。
    添加资源包特效时，都得先安装，安装成功后获取packageId才能使用，而内建特效(builtin)只需获取特效名称即可使用。
    \warning NvsVideoClip类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsVideoClip : NvsClip


@property (readonly) NvsVideoClipType videoType;  //!< 视频片段类型(音视频、图片)


@property (readonly) NvsRoleInTheme roleInTheme;  //!< 视频片段在主题中角色(通用、片头、片尾)

@property (nonatomic) NvsStreamingEngineImageClipMotionMode imageMotionMode; //!< 图片片段运作模式 \since 1.1.0

@property (nonatomic) BOOL imageMotionAnimationEnabled;  //!< 是否支持图片动画 \since 1.1.0

@property (readonly) NvsRect startROI; //!< 图片片段起始ROI \since 1.1.0

@property (readonly) NvsRect endROI;   //!< 图片片段终止ROI \since 1.1.0


/*!
    \brief 设置片段是否倒放

    注意：使用片段倒放请确保当前视频文件为全I帧视频，否则倒放播放效率极低完全无法忍受！可以利用美摄SDK录制标志
    STREAMING_ENGINE_RECORDING_FLAG_VIDEO_INTRA_FRAME_ONLY来产生出全I帧视频文件。如果从别的地方
    导入的文件无法保证为全I帧视频又想用倒放功能则可以使用美摄的转码SDK直接将原始视频转码为一个倒放的文件再使用。
    注意：请确保需要倒放的视频文件位于APP的沙盒中
    \param playInReverse 片段是否倒放
    \since 1.5.1
    \sa getPlayInReverse
 */
- (void)setPlayInReverse:(BOOL)playInReverse;

/*!
    \brief 获取片段是否倒放
    \return 返回片段是否倒放
    \since 1.5.1
    \sa setPlayInReverse
 */
- (BOOL)getPlayInReverse;
/*!
    \brief 设置视频额外旋转角度
    \param rotation 额外旋转角度
    \sa getExtraVideoRotation
 */
- (void)setExtraVideoRotation:(NvsExtraVideoRotation)rotation;

/*!
    \brief 获取视频额外旋转角度
    \return 返回值，获取额外旋转角度
    \sa setExtraVideoRotation:
 */
- (NvsExtraVideoRotation)getExtraVideoRotation;

/*!
    \brief 设置摇摄和扫描

    摇摄和扫描功能是用来适配图像在显示窗口上的位置与大小的。具体请参见[摇摄与扫描(Pan and Scan)] (\ref Pan_Scan.md)专题。
    \param pan 摇摄
    \param scan 扫描
    \sa getPan:andScan:
 */
- (void)setPan:(float)pan andScan:(float)scan;

/*!
    \brief 获取摇摄和扫描
    \param pan 返回值，获取摇摄值
    \param scan 返回值，获取扫描值
    \sa setPan:andScan:
 */
- (void)getPan:(float *)pan andScan:(float *)scan;

/*!
    \brief 设置背景模式
    \param sourceBackgroundMode 背景模式
    \sa getSourceBackgroundMode:
 */
- (void)setSourceBackgroundMode:(NvsSourceBackgroundMode) sourceBackgroundMode;

/*!
    \brief 获取背景模式
    \return 背景模式
    \sa setSourceBackgroundMode: sourceBackgroundMode:
 */
- (NvsSourceBackgroundMode)getSourceBackgroundMode;


/*!
    \brief 设置图片片段动态移动ROI

    具体情况请参见[图片片段ROI专题] (\ref ImageROI.md)
    \param startROI 图片片段起始ROI
    \param endROI 图片片段终止ROI
    \since 1.1.0
    \sa setPan:andScan:
 */
- (void)setImageMotionROI:(NvsRect *)startROI endROI:(NvsRect *)endROI;

/*!
    \brief 设置片段循环模式
    \param wrapMode 循环模式
    \since 2.2.3
    \sa getClipWrapMode
 */

- (void)setClipWrapMode:(NvsClipWrapMode)wrapMode;

/*!
    \brief 获取视频循环模式
    \return 返回循环模式
    \since 2.2.3
    \sa setClipWrapMode
 */

- (NvsClipWrapMode)getClipWrapMode;

/*!
    \brief 在片段上追加内嵌式特效
    \param fxName 特效名称。获取视频特效名称，请参见[getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)
    \return 返回追加的视频特效对象
    \sa insertBuiltinFx:fxIndex:
    \sa appendBeautyFx
    \sa appendPackagedFx:
 */

- (NvsVideoFx *)appendBuiltinFx:(NSString *)fxName;

/*!
    \brief 在片段上指定特效索引处插入内嵌式特效
    \param fxName 特效名称。获取视频特效名称，请参见[getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)
    \param fxIndex 插入特效索引
    \return 返回插入的视频特效对象
    \sa appendBuiltinFx:
    \sa insertPackagedFx:fxIndex:
    \sa insertBeautyFx:
 */
- (NvsVideoFx *)insertBuiltinFx:(NSString *)fxName fxIndex:(unsigned int)fxIndex;

/*!
    \brief 在片段上追加资源包特效
    \param fxPackageId 特效资源包ID
    \return 返回追加的视频特效对象
    \sa appendBeautyFx
    \sa appendBuiltinFx:
    \sa insertPackagedFx:fxIndex:
 */
- (NvsVideoFx *)appendPackagedFx:(NSString *)fxPackageId;

/*!
    \brief 在片段上指定特效索引处插入包裹特效
    \param fxPackageId 包裹特效Id
    \param fxIndex 插入特效索引
    \return 返回插入的视频特效对象
    \sa insertBeautyFx:
    \sa appendPackagedFx:
    \sa insertBuiltinFx:fxIndex:
 */
- (NvsVideoFx *)insertPackagedFx:(NSString *)fxPackageId fxIndex:(unsigned int)fxIndex;

/*!
    \brief 在片段上追加自定义视频特效
    \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
    \return 返回追加的视频特效对象
    \since 1.7.0
 */
- (NvsVideoFx *)appendCustomFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender;

/*!
    \brief 在片段上指定特效索引处插入自定义视频特效
    \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
    \param fxIndex 插入特效索引
    \return 返回插入的视频特效对象
    \since 1.7.0
 */
- (NvsVideoFx *)insertCustomFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender fxIndex:(unsigned int)fxIndex;

/*!
    \brief 在片段上追加美颜特效
    \return 返回追加的视频特效对象
    \sa insertBeautyFx:
    \sa appendPackagedFx:
    \sa appendBuiltinFx:
 */
- (NvsVideoFx *)appendBeautyFx;

/*!
    \brief 在片段上指定特效索引处插入美颜特效
    \param fxIndex 插入特效索引
    \return 返回插入的视频特效对象
    \sa appendBeautyFx
    \sa insertPackagedFx:fxIndex:
    \sa insertBuiltinFx:fxIndex:
 */
- (NvsVideoFx *)insertBeautyFx:(unsigned int)fxIndex;

/*!
    \brief 移除特效
    \param fxIndex 特效索引
    \return 判断是否移除成功。返回true则移除成功，false则失败。
    \sa removeAllFx
 */
- (BOOL)removeFx:(unsigned int)fxIndex;

/*!
    \brief 移除所有特效
    \return 判断是否移除成功。返回true则移除成功，false则失败。
    \sa removeFx:
 */
- (BOOL)removeAllFx;

/*!
    \brief 通过索引获取特效
    \param fxIndex 特效索引
    \return 返回获取的视频特效对象
 */
- (NvsVideoFx *)getFxWithIndex:(unsigned int)fxIndex;

@end
