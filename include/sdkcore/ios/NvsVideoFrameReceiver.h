//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jun 13. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>


@protocol NvsVideoFrameReceiverDelegate <NSObject>

/*!
 *  \brief 通知接收者一个视频帧已经渲染完成
    如果接收者想要获取该视频帧的使用权则需要返回YES，否则并不获取视频帧的使用权。获取使用权后则
    可以使用该视频帧的OpenGL ES纹理ID在自己的EAGLContext之中进行绘制，当然前提是该
    EAGLContext必须与美摄引擎的EAGLContext处于同一个EAGLSharegroup中。接收者在确保不再使用
    这个纹理之后一定要调用reclaimVideoFrame让美摄SDK回收这个纹理，否则会出现泄漏！
    注意：这个回调函数是在引擎的某个线程调用的，并非主线程！
 *  \param videoFrameTextureId 视频帧的OpenGL ES纹理ID
 *  \param videoSize 视频帧的尺寸，单位为像素
 *  \param timelinePos 视频帧的时间戳，单位为微秒
 *  \return 返回BOOL值，为YES表示接收者获取了该视频帧的使用权，如果为NO表示接收者未获取该视频帧的使用权
 */
- (BOOL)didVideoFrameReceived:(unsigned int)videoFrameTextureId
                    videoSize:(CGSize)videoSize
                  timelinePos:(int64_t)timelinePos;

@end


/*!
 *  \brief 时间线视频帧接收器
 * 
 *  对时间线进行定位或者播放的操作所渲染出来的视频帧会通过。
 */
@interface NvsVideoFrameReceiver : NSObject

@property (nonatomic, retain) id<NvsVideoFrameReceiverDelegate> delegate;


- (instancetype)init;

/*!
 *  \brief 回收一个已经获取到使用权的视频帧
 *  \param videoFrameTextureId 待回收的视频帧的OpenGL ES纹理ID
 */
- (void)reclaimVideoFrame:(unsigned int)videoFrameTextureId;

@end

