//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Feb 22. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <UIKit/UIView.h>
#import "NvsMultiThumbnailSequenceView.h"

/*!
    \brief 缩略图序列

    注意：新的代码请不要再使用这个控件，请使用NvsMultiThumbnailSequenceView控件！
    缩略图序列，即视频按照某种程度缩放，来静态缩略显示的序列。视频编辑时，通过预览定位视频序列，可以设置序列的开始时间，时长，缩略图横纵比等。同时，依照缩略图在对应时段位置精确添加字幕和裁剪视频。
    \warning NvsThumbnailSequenceView类中，所有public API都在UI线程使用！！！
    \since 1.1.0
    \deprecated
 */
NVS_EXPORT @interface NvsThumbnailSequenceView : UIView

@property (nonatomic) NSString *mediaFilePath; //!< 媒体文件路径
@property (nonatomic) int64_t startTime;       //!< 序列开始时间（单位微秒）
@property (nonatomic) int64_t duration;        //!< 序列时长（单位微秒）
@property (nonatomic) float thumbnailAspectRatio; //!< 缩略图横纵比
@property (nonatomic) BOOL stillImageHint;     //!< 是否是静态图片
@property (nonatomic) NvsThumbnailImageFillMode thumbnailImageFillMode;     //!< \if ENGLISH \else 缩略图图片填充模式 \endif


- (instancetype)init;
- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithCoder:(NSCoder *)aDecoder;

@end

