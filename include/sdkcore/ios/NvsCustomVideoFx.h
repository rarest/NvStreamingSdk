//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jul 20. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"


struct NvsCustomVideoFxVideoFrame {
    int texId;  //!< 视频帧的纹理ID
    int width;  //!< 视频帧的宽度
    int height; //!< 视频帧的高度
    BOOL isUpsideDownTexture; //!< 为YES表示这个视频帧中的纹理是上下颠倒的。用户在渲染时需对纹理坐标进行处理。
};

struct NvsCustomVideoFxRenderContext {
    struct NvsCustomVideoFxVideoFrame inputVideoFrame;     //!< 输入视频帧
    struct NvsCustomVideoFxVideoFrame outputVideoFrame;    //!< 输出视频帧
    int64_t effectTime;
    int64_t effectStartTime;
    int64_t effectEndTime;
};


@class NvsCustomVideoFxRenderHelper;

/*!
 *  \brief 自定义视频特效渲染器接口
 */
@protocol NvsCustomVideoFxRenderer <NSObject>

/*!
 *  \brief 美摄SDK对自定义视频特效调用此方法以便让用户初始化一些资源
 *  
 *  这个方法在自定义视频特效的生命周期里最多只会被调用一次。如果该特效从未被真正使用过，则这个方法将不会被调用。
 *  这个方法是在美摄SDK引擎的特效渲染线程里调用，并且当前线程已经绑定了一个EAGLContext。
 */
- (void)didInit;

/*!
 *  \brief 美摄SDK对自定义视频特效调用此方法以便让用户清理资源
 *
 *  这个方法在自定义视频特效的生命周期里最多只会被调用一次，而且一定会在didInit之后调用，如果didInit没有被调用则也不会调用该方法。
 *  这个方法是在美摄SDK引擎的特效渲染线程里调用，并且当前线程已经绑定了一个EAGLContext。
 */
- (void)didCleanup;

/*!
 *  \brief 美摄SDK对自定义视频特效调用此方法以便让进行一些资源预处理
 *
 *  这个方法在自定义视频特效的生命周期里会被多次调用，而且一定会在didInit之后调用，一般来讲是在每次播放时间线之前调用。
 *  一般来讲用户需要在此函数里面进行诸如构建shader program的工作。
 *  这个方法是在美摄SDK引擎的特效渲染线程里调用，并且当前线程已经绑定了一个EAGLContext。
 */
- (void)didPreloadResources;

/*!
 *  \brief 美摄SDK对自定义视频特效调用此方法以便对输入视频帧进行特效处理
 *
 *  用户实现这个方法对输入视频帧进行处理并将结果写入到输出视频帧中去以便完成特效渲染。
 *  这个方法是在美摄SDK引擎的特效渲染线程里调用，并且当前线程已经绑定了一个EGL Context。
 *  当前线程已经绑定了一个FBO，用户只需在相应的attachment point上面绑定color buffer, depth buffer...即可
 *  注意：请务必在渲染完成后，将OpenGL ES context的状态复位到默认状态，比如用户渲染过程中调用了glEnable(GL_BLEND),
 *  则渲染完成后一定要调用glDisable(GL_BLEND),因为默认状态下blend是关闭的。关于OpenGL ES context的默认状态
 *  请参考https://www.khronos.org/opengles/
 *  警告：如果渲染完成后，没有将OpenGL ES context的状态复位到默认状态，则可能导致后续特效渲染发生错误！
 *
 *  \param renderContext 特效渲染上下文对象
 *  \param renderHelper 特效渲染辅助方法接口，注意用户不要保存这个接口，只能在didRender里面使用它！
 */
- (void)didRender:(struct NvsCustomVideoFxRenderContext *)renderContext
     renderHelper:(NvsCustomVideoFxRenderHelper *)renderHelper;

@end


/*!
 *  \brief 自定义视频特效的辅助方法接口
 */
@interface NvsCustomVideoFxRenderHelper : NSObject

/*!
 *  \brief 自定义视频特效的用户调用此方法来申请一个RGBA纹理
 *
 *  注意：使用这个方法申请的纹理一定要调用reclaimTexture进行回收，否则会出现泄漏！
 *  \param texSize 申请纹理的尺寸
 *  \return 返回申请到的纹理ID，返回0表示申请失败
 */
- (int)allocateRGBATexture:(NvsSize)texSize;

/*!
 *  \brief 自定义视频特效的用户调用此方法来回收一个之前申请的纹理
 *  \param texId 要释放的纹理ID
 */
- (void)reclaimTexture:(int)texId;

@end

