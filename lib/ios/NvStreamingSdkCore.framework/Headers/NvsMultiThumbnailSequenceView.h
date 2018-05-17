//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Aug 28. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <UIKit/UIScrollView.h>
#import "NvsCommonDef.h"

/*!
    \brief 多缩略图序列信息描述
    \since 1.10.0
 */
NVS_EXPORT @interface NvsThumbnailSequenceDesc : NSObject

@property (nonatomic) NSString *mediaFilePath;      //!< 视频文件路径
@property (nonatomic) int64_t inPoint;              //!< 时间线上入点(单位微秒)
@property (nonatomic) int64_t outPoint;             //!< 时间线上出点(单位微秒)
@property (nonatomic) int64_t trimIn;               //!< 裁剪入点(单位微秒)
@property (nonatomic) int64_t trimOut;              //!< 裁剪出点(单位微秒)
@property (nonatomic) BOOL stillImageHint;          //!< 是否是静态图片

@end

/*!
*   \brief 缩略图图片填充模式
*/
typedef enum {
    NvsThumbnailFillModeStretch = 0,           //!< \if ENGLISH \else 图片缩放填充满整个窗口，可能会导致图片变形 （默认模式）\endif
      NvsThumbnailFillModeAspectCrop,    //!< \if ENGLISH \else 图片按比例均匀填充满窗口，必要时进行裁剪 \endif

}NvsThumbnailImageFillMode;


/*!
    \brief 多缩略图序列

    多缩略图序列，可以显示一个时间线内多个片段的缩略图序列。支持缩略图时间比例尺的调节，当有效内容超长时支持滚动浏览。
    \warning NvsMultiThumbnailSequenceView类中，所有public API都在UI线程使用！！！
    \since 1.10.0
 */
NVS_EXPORT @interface NvsMultiThumbnailSequenceView : UIScrollView


@property (nonatomic) NSArray *descArray;           //!< 缩略图序列描述数组。注意：一旦设置，再修改数组里面的内容是不起作用的，除非再次设置缩略图序列描述数组
@property (nonatomic) CGFloat thumbnailAspectRatio; //!< 缩略图横纵比
@property (nonatomic) double pointsPerMicrosecond;  //!< 比例尺，每微秒所占用的point数量
@property (nonatomic) CGFloat startPadding;         //!< 起始边距，单位为point
@property (nonatomic) CGFloat endPadding;           //!< 结束边距，单位为point
@property (nonatomic) NvsThumbnailImageFillMode thumbnailImageFillMode;  //!< 缩略图图片填充模式
@property (nonatomic) int64_t maxTimelinePosToScroll; //!< 允许滚动的最大时间线位置(单位微秒)，默认值为0，表示不做限制


- (instancetype)init;
- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithCoder:(NSCoder *)aDecoder;

/*!
 *  \brief 将控件的X坐标映射到时间线位置
 *  \param x 控件的X坐标，单位为point
 *  \return 返回映射的时间线位置，单位为微秒
 *  \sa mapXFromTimelinePos
 */
- (int64_t)mapTimelinePosFromX:(CGFloat)x;

/*!
 *  \brief 将时间线位置映射到控件的X坐标
 *  \param timelinePos 时间线位置，单位为微秒
 *  \return 返回映射的控件的X坐标，单位为point
 *  \sa mapTimelinePosFromX
 */
- (CGFloat)mapXFromTimelinePos:(int64_t)timelinePos;

/*!
 *  \brief 缩放当前比例尺
 *  \param scaleFactor 缩放的比例
 *  \param anchorX 缩放的锚点X坐标，单位为point
 */
- (void)scale:(double)scaleFactor withAnchor:(CGFloat)anchorX;

@end

