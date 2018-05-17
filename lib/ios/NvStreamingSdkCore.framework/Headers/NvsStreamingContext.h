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
#include "NvsAREffectContext.h"


/*!
 *  \brief
 *  流媒体上下文创建标志
 */
typedef enum {
    NvsStreamingContextFlag_Support4KEdit = 1,  //!< \if ENGLISH \else 支持4K视频编辑 \endif
    NvsStreamingContextFlag_Support8KEdit = 4   //!< 支持8K编辑(仅图片)
} NvsStreamingContextFlag;

/*!
 *  \brief
 *  生成视频文件的分辨率高度级别(创建时间线(createTimeline)时指定视频的宽高和横纵比，根据输出的视频分辨率高度算出生成视频文件的宽度)
 */
typedef enum {
    NvsCompileVideoResolutionGrade360 = 0,  //!< \if ENGLISH \else 输出高度360像素 \endif
    NvsCompileVideoResolutionGrade480,      //!< \if ENGLISH \else 输出高度480像素 \endif
    NvsCompileVideoResolutionGrade720,      //!< \if ENGLISH \else 输出高度720像素 \endif
    NvsCompileVideoResolutionGrade1080,     //!< \if ENGLISH \else 输出高度1080像素 \endif
    NvsCompileVideoResolutionGrade2160,     //!< \if ENGLISH \else 输出高度2160像素 \endif
    NvsCompileVideoResolutionGradeCustom = 256  //!< 自定义生成视频高度
} NvsCompileVideoResolutionGrade;

/*!
 *  \brief 生成视频文件的码率级别
 */
typedef enum {
    NvsCompileBitrateGradeLow = 0,          //!< \if ENGLISH \else 低码率 \endif
    NvsCompileBitrateGradeMedium,           //!< \if ENGLISH \else 中等码率 \endif
    NvsCompileBitrateGradeHigh              //!< \if ENGLISH \else 高码率 \endif
} NvsCompileVideoBitrateGrade;

/*!
 *  \brief 视频预览模式
 */
typedef enum {
    NvsVideoPreviewSizeModeFullSize = 0,     //!< \if ENGLISH \else 全屏预览 \endif
    NvsVideoPreviewSizeModeLiveWindowSize    //!< \if ENGLISH \else liveWindow预览 \endif
} NvsVideoPreviewSizeMode;

/*!
 *  \brief 视频采集分辨率级别
 */
typedef enum {
    NvsVideoCaptureResolutionGradeLow = 0,   //!< \if ENGLISH \else 低分辨率 \endif
    NvsVideoCaptureResolutionGradeMedium,    //!< \if ENGLISH \else 中等分辨率 \endif
    NvsVideoCaptureResolutionGradeHigh       //!< \if ENGLISH \else 高分辨率 \endif
} NvsVideoCaptureResolutionGrade;

/*!
 *  \brief 流媒体引擎状态
 */
typedef enum {
    NvsStreamingEngineState_Stopped = 0,      //!< \if ENGLISH \else 引擎停止 \endif
    NvsStreamingEngineState_CapturePreview,   //!< \if ENGLISH \else 采集预览 \endif
    NvsStreamingEngineState_CaptureRecording, //!< \if ENGLISH \else 采集录制 \endif
    NvsStreamingEngineState_Playback,         //!< \if ENGLISH \else 播放 \endif
    NvsStreamingEngineState_Seeking,          //!< \if ENGLISH \else 定位 \endif
    NvsStreamingEngineState_Compile           //!< \if ENGLISH \else 生成 \endif
} NvsStreamingEngineState;

/*!
 *  \brief 采集标志
 */
typedef enum
{
    NvsStreamingEngineCaptureFlag_GrabCapturedVideoFrame = 1,       //!< \if ENGLISH \else 获取采集视频的帧内容（打开这个标志会降低性能，只有在必要的时候开启这个标志） \endif
    NvsStreamingEngineCaptureFlag_StrictPreviewVideoSize = 8,       //!< 限定预览视频尺寸只能是系统自带的预览视频尺寸
    NvsStreamingEngineCaptureFlag_DontCaptureAudio = 16,            //!< 不采集音频
    NvsStreamingEngineCaptureFlag_CaptureBuddyHostVideoFrame = 32,  //!< 采集伴侣视频帧
    NvsStreamingEngineCaptureFlag_IgnoreScreenOrientation = 64,     //!< 不使用屏幕方向来确定采集画面的旋转角度 \since 1.15.2
    NvsStreamingEngineCaptureFlag_AutoVideoStabilization = 128      //!< 启用视频防抖动 \since 1.16.1
} NvsStreamingEngineCaptureFlag;


/*!
 *  \brief 输入buffer的图像旋转角度
 */
typedef enum
{
    BufferImageRotation_0 = 0,
    BufferImageRotation_90 = 1,
    BufferImageRotation_180 = 2,
    BufferImageRotation_270 = 3,
} BufferImageRotation;


/*!
 *  \brief 防抖动标志
 */
typedef enum
{
    VideoStabilizationFlag_Off = 0, //!< 视频防抖动模式关闭
    VideoStabilizationFlag_Auto = 1, //!< 视频防抖自动模式
    VideoStabilizationFlag_Standard = 2, //!<视频防抖标准模式
    VideoStabilizationFlag_Super = 3, //!< 视频防抖电影模式
} VideoStabilizationFlag;

/*!
 *  \brief 录制标志
 */
typedef enum
{
    NvsStreamingEngineRecordingFlag_VideoIntraFrameOnly = 2,    //!< 录制仅包含I-Frame的视频文件
} NvsStreamingEngineRecordingFlag;

/*!
 *  \brief 引擎定位标识
 */
typedef enum {
    NvsStreamingEngineSeekFlag_ShowCaptionPoster = 2,          //!< \if ENGLISH \else 整体展示字幕效果 \endif
    NvsStreamingEngineSeekFlag_ShowAnimatedStickerPoster = 4,  //!< \if ENGLISH \else 整体展示动画贴纸效果 \endif
} NvsStreamingEngineSeekFlag;

/*!
 *  \brief 引擎播放标志
 */
typedef enum {
    NvsStreamingEnginePlaybackFlag_LowPipelineSize = 8         //!< 降低引擎在播放时内部的流水线尺寸
} NvsStreamingEnginePlaybackFlag;

/*! \anchor RECORD_CONFIGURATIONS */
/*! @name 录制视频配置 */
//!@{
#define NVS_RECORD_BITRATE        @"bitrate"				   //!< 录制视频码率
#define NVS_RECORD_GOP_SIZE       @"gopsize"                  //!< 录制视频GOP SIZE
//!@}

/*! \anchor COMPILE_CONFIGURATIONS */
/*! @name 生成时间线的配置 */
//!@{
#define NVS_COMPILE_BITRATE         @"bitrate"              //!< 生成视频码率
#define NVS_COMPILE_GOP_SIZE        @"gopsize"              //!< 生成视频GOP SIZE
#define NVS_COMPILE_AUDIO_BITRATE   @"audio bitrate"        //!< 生成音频码率
#define NVS_COMPILE_LOSSLESS_AUDIO  @"lossless audio"       //!< 是否生成无损音频
//!@}

@class NvsCaptureDeviceCapability;
@class NvsCaptureVideoFx;
@class NvsFxDescription;
@class NvsCaptureDeviceCapability;
@class NvsCaptureVideoFx;
@class NvsFxDescription;

@protocol NvsStreamingContextDelegate <NSObject>
@optional

/*!
 *  \brief 采集设备准备完成
 *  \param captureDeviceIndex 设备索引
 */
- (void)didCaptureDeviceCapsReady:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 采集设备预览解析度准备完成
 *  \param captureDeviceIndex 设备索引
 */
- (void)didCaptureDevicePreviewResolutionReady:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 采集设备预览开始
 *  \param captureDeviceIndex 设备索引
 */
- (void)didCaptureDevicePreviewStarted:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 采集设备错误
 *  \param captureDeviceIndex 设备索引 
 *  \param errorCode 错误码
 */
- (void)didCaptureDeviceError:(unsigned int)captureDeviceIndex errorCode:(int32_t)errorCode;

/*!
 *  \brief 采集设备停止
 *  \param captureDeviceIndex 设备索引
 */
- (void)didCaptureDeviceStopped:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 采集设备自动对焦完成
 *  \param captureDeviceIndex 设备索引
 *  \param succeeded 对焦是否完成
 */
- (void)didCaptureDeviceAutoFocusComplete:(unsigned int)captureDeviceIndex succeeded:(BOOL)succeeded;

/*!
 *  \brief 采集录制开始
 *  \param captureDeviceIndex 设备索引
 *  \sa didCaptureRecordingFinished:
 *  \sa didCaptureRecordingError:
 *  \since 1.16.0
 */
- (void)didCaptureRecordingStarted:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 录制时长通知
 *  \param captureDeviceIndex 设备索引
 *  \param duration 已经录制的时长，单位是微秒
 *  \since 1.17.0
 */
- (void)didCaptureRecordingDurationUpdated:(int)captureDeviceIndex duration:(int64_t)duration;

/*!
 *  \brief 采集录制完成
 *  \param captureDeviceIndex 设备索引
 *  \sa didCaptureRecordingStarted:
 *  \sa didCaptureRecordingError:
 */
- (void)didCaptureRecordingFinished:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 采集录制失败
 *  \param captureDeviceIndex 设备索引
 *  \sa didCaptureRecordingStarted:
 *  \sa didCaptureRecordingFinished:
 */
- (void)didCaptureRecordingError:(unsigned int)captureDeviceIndex;

/*!
 *  \brief 播放预先加载完成
 *  \param timeline 时间线
 */
- (void)didPlaybackPreloadingCompletion:(NvsTimeline *)timeline;

/*!
 *  \brief 时间线播放的当前位置
 *  \param timeline 时间线
 *  \param position 时间线播放的当前位置
 *  \since 1.6.0
 */
- (void)didPlaybackTimelinePosition:(NvsTimeline *)timeline position:(int64_t)position;

/*!
 *  \brief 播放停止
 *  \param timeline 时间线
 */
- (void)didPlaybackStopped:(NvsTimeline *)timeline;

/*!
 *  \brief 播放到结尾
 *  \param timeline 时间线
 */
- (void)didPlaybackEOF:(NvsTimeline *)timeline;

/*!
 *  \brief 生成视频文件进度
 *  \param timeline 时间线
 *  \param progress 进度值
 */
- (void)didCompileProgress:(NvsTimeline *)timeline progress:(int)progress;

/*!
 *  \brief 生成视频文件完成
 *  \param timeline 时间线
 *  \sa didCompileFailed:
 */
- (void)didCompileFinished:(NvsTimeline *)timeline;

/*!
 *  \brief 生成视频文件完成
 *  \param timeline 时间线
 *  \param isCanceled 中途取消导致生成完成。注：任何对引擎操作引起的停止生成均视为中途取消
 *  \since 1.6.0
 *  \sa didCompileFinished:
 */
- (void)didCompileCompleted:(NvsTimeline *)timeline isCanceled:(BOOL)isCanceled;

/*!
 *  \brief 生成视频文件失败
 *  \param timeline 时间线
 */
- (void)didCompileFailed:(NvsTimeline *)timeline;

/*!
 *  \brief 引擎状态改变
 *  \param state 引擎状态
 */
- (void)didStreamingEngineStateChanged:(NvsStreamingEngineState)state;

/*!
 *  \brief 第一视频帧呈现
 *  \param timeline 时间线
 */
- (void)didFirstVideoFramePresented:(NvsTimeline *)timeline;

/*!
 *  \brief 时间线越界（注：非必要情况请勿使用此回调接口）
 *  \param timeline 时间线
 *  \since 1.2.0
 */

- (void)didTimestampOutOfRange:(NvsTimeline *)timeline;

/*!
 *  \brief 获取采集预览图像

   请特别注意:这个函数被调用是在一个单独的线程,而不是在UI线程.使用请考虑线程安全的问题!!

 *  \param sampleBufferInfo 获取到的图像数据
 *  \since 1.4.0
 */
- (void)captureVideoFrameGrabbedArrived:(NvsVideoFrameInfo*)sampleBufferInfo;

@end

/*!
 *  \brief 流媒体上下文
 * 
 *  流媒体上下文类可视作整个SDK框架的入口。开发过程中，NvsStreamingContext类提供了静态sharedInstance()接口创建流上下文的唯一实例。
 *  通过这个实例对象，我们可以开启采集设备录制视频，添加采集视频特效，设置拍摄时的各项参数，包括自动聚焦，自动曝光调节，开关换补光灯等。
 *  同时，还能够创建时间线，并将时间线与实时预览窗口(Live Window)连接起来，实时预览播放已经拍摄完成的视频。整个视频制作完成后，要销毁流媒体上下文的对象实例。
 *  带特效拍摄时，添加素材资源包(采集特效包，场景资源包等)，都得先安装，安装成功后获取packageId才能使用，而内建采集特效(builtin)只需获取特效名称即可使用。
    <br>sdk接口中凡是需要传入资源、授权等文件路径时一定是全路径。
    \warning NvsStreamingContext类中，所有public API除了getAVFileInfo，detectVideoFileKeyframeInterval，createVideoFrameRetriever可以跨线程使用，其他都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsStreamingContext : NSObject

@property (nonatomic, weak) id<NvsStreamingContextDelegate> delegate;
@property (readonly) NvsAssetPackageManager *assetPackageManager;
@property (nonatomic) float compileVideoBitrateMultiplier;              //!< 生成视频码率倍乘系数 \since 1.5.0
@property (nonatomic) float recordVideoBitrateMultiplier;               //!< 录制视频码率倍乘系数 \since 1.5.0
@property (nonatomic) BOOL defaultCaptionFade;                          //!< 默认字幕是否为淡入淡出 \since 1.8.0
/*!
 *  \brief 生成时间线配置，设置一次即一直生效。NSMutableDictionary中关键字的值请参见 [生成时间线的配置] (@ref COMPILE_CONFIGURATIONS)
 *         例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_COMPILE_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_COMPILE_BITRATE]; // 10M bps
 *              [config setValue:[NSNumber numberWithInteger:256000] forKey:NVS_COMPILE_AUDIO_BITRATE]; // 设置音频码率为256Kbps
 *              [config setValue:[NSNumber numberWithBool:YES] forKey:NVS_COMPILE_LOSSLESS_AUDIO]; // 设置生成无损音频
 *              _streamingContext.compileConfigurations = config;
 *         取消设置并恢复默认方式例如：[_streamingContext.compileConfigurations setValue:nil forKey:NVS_COMPILE_GOP_SIZE];
 *  \since 1.8.0
 */
@property (nonatomic) NSMutableDictionary *compileConfigurations;

/*!
 *  \brief 获取美摄SDK的版本信息
 *  \param majorVersion 主版本号
 *  \param minorVersion 次版本号
 *  \param revisionNumber 修订版本号
 *  \since 1.4.1
 */
+ (void)getSdkVersion:(int *)majorVersion minorVersion:(int *)minorVersion revisionNumber:(int *)revisionNumber;

/*!
 *  \brief 设置是否将SDK的调试信息写入到文件中
 *  \param saveDebugMessagesToFile 是否将SDK的调试信息写入到文件中
 *  \since 1.17.0
 */
+ (void)setSaveDebugMessagesToFile:(BOOL)saveDebugMessagesToFile;

/*!
 *  \brief 验证SDK授权文件。注意：授权文件接口必须在NvsStreamingContext初始化之前调用。
 *  \param sdkLicenseFilePath SDK授权文件路径
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。若验证失败，则后续的视频预览和生成视频会出现水印。
 */
+ (BOOL)verifySdkLicenseFile:(NSString *)sdkLicenseFilePath;

/*!
 *  \brief 获取流媒体上下文的唯一实例
 *  \return 返回流媒体上下文的对象实例
 *  \sa destroyInstance
 */
+ (NvsStreamingContext *)sharedInstance;

/*!
 *  \brief 获取流媒体上下文的唯一实例。详细了解参见[4k视频编辑专题] (@ref support4kVideoEdit.md)
 *  \param flags 标志字段，如无特殊需求请填写0。
 *  \return 返回流媒体上下文的对象实例
 *  \since 1.5.0
 *  \sa destroyInstance
 */
+ (NvsStreamingContext *)sharedInstanceWithFlags:(NvsStreamingContextFlag)flags;

/*!
 *  \brief 销毁流媒体上下文实例。注意: 销毁之后无法再次创建及获取
 *  \sa sharedInstance
 */
+ (void)destroyInstance;

/*!
 *  \brief 从流媒体上下文中获取引擎所用的EAGLSharegroup对象
 *  \since 1.5.0
 */
- (EAGLSharegroup *)getEAGLSharegroup;

/*!
 *  \brief 获取文件的音视频信息
 *  \param avFilePath 文件路径
 *  \return 返回音视频文件信息的对象
 */
- (NvsAVFileInfo *)getAVFileInfo:(NSString *)avFilePath;

/*!
 *  \brief 探测视频文件的I帧间距
 *  \param videoFilePath 视频文件的路径
 *  \return 返回探测到的I帧间距，返回0表示探测失败
 *  \since 1.6.0
 */
- (int)detectVideoFileKeyframeInterval:(NSString *)videoFilePath;

/*!
 *  \brief 设置默认主题logo图片路径
 *  \param logoImageFilePath logo图片文件路径
 *  \return 返回BOOL值。YES 设置成功；NO 设置失败
 *  \sa getDefaultThemeEndingLogoImageFilePath
 */
- (BOOL)setDefaultThemeEndingLogoImageFilePath:(NSString *)logoImageFilePath;

/*!
 *  \brief 获取默认主题logo图片路径
 *  \return 返回表示图片路径的字符串
 *  \sa setDefaultThemeEndingLogoImageFilePath:
 */
- (NSString *)getDefaultThemeEndingLogoImageFilePath;

/*!
 *  \brief 设置主题结尾logo特效是否显示
 *  \return 返回BOOL值。YES 设置成功；NO 设置失败
 *  \sa setDefaultThemeEndingLogoImageFilePath:
 */
- (BOOL)setThemeEndingEnabled:(BOOL)enable;


/*!
 *  \brief 创建时间线
 *  \param videoEditRes 视频编辑解析度(指定视频宽高及像素比)。对于视频编辑解析度，在传入对应参数值时，目前要求传入的图像宽度值是4的倍数，高度值是2的倍数。注：如果创建NvsStreamingContext单例对象，支持4k视频编辑，则视频编辑解析度里的imageWidth * imageHeight不能高于3840*2160像素，否则视频编辑解析度里的imageWidth * imageHeight不能高于1920 * 1080像素。
 *  \param videoFps 视频帧率
 *  \param audioEditRes 音频编辑解析度(指定采样率、采样格式及声道数)。对于音频编辑解析度，传入的采样率值支持两种：44100与48000。
 *  \return 返回创建的时间线对象
 *  \sa removeTimeline:
 */
- (NvsTimeline *)createTimeline:(NvsVideoResolution *)videoEditRes videoFps:(NvsRational *)videoFps audioEditRes:(NvsAudioResolution *)audioEditRes;

/*!
 *  \brief 移除时间线
 *  \param timeline 要移除的时间线
 *  \return 返回BOOL值。YES 移除成功；NO 移除失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa createTimeline:videoFps:audioEditRes:
 */
- (BOOL)removeTimeline:(NvsTimeline *)timeline;


/*!
 *  \brief 获取引擎状态
 *  \return 返回引擎状态
 */
- (NvsStreamingEngineState)getStreamingEngineState;

/*!
 *  \brief 取得时间线当前时间位置，单位为微秒
 *  \param timeline 时间线
 *  \return 返回时间线的当前位置值
 */
- (int64_t)getTimelineCurrentPosition:(NvsTimeline *)timeline;

/*!
 *  \brief 时间线生成视频文件
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位微秒)。startTime取值范围在[0,timeline.duration - 1],传入其他值无效。
 *  \param endTime 结束时间(单位微秒)。endTime取值范围在(startTime,timeline.duration],同样传入其他值无效。
 *  \param outputFilePath 生成视频输出的文件路径。注意: 目前只支持输出.mov格式的文件
 *  \param videoResolutionGrade 生成视频输出的分辨率级别
 *  \param videoBitrateGrade 生成视频输出的码率。视频输出码率级别分为低码率，中等码率，高等码率。视频生成具体码率值跟生成视频的分辨率有关，这里以1280 * 720p为例，计算出不同码率级别对应的近似值，
 *                           NvsCompileBitrateGradeLow级别值为2.2Mbps，NvsCompileBitrateGradeMedium级别值为3.3Mbps，NvsCompileBitrateGradeHigh级别值为6Mbps。
 *  \param flags 生成视频输出的特殊标志(暂时只设为0)
 *  \return 返回BOOL值。注意：时间线生成视频文件是异步操作。返回值为YES则启动时间线生成文件成功，NO则时间线生成文件启动失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
 */
- (BOOL)compileTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime outputFilePath:(NSString *)outputFilePath videoResolutionGrade:(NvsCompileVideoResolutionGrade)videoResolutionGrade videoBitrateGrade:(NvsCompileVideoBitrateGrade)videoBitrateGrade flags:(int)flags;

/*!
 *  \brief 设置自定义的生成视频高度。
 *         在生成时视频时，设置生成视频的分辨率高度级别为NvsCompileVideoResolutionGradeCustom
 *         就可以使用自定义的生成视频高度。但是请注意，为了保证视频生成成功，美摄SDK会对高度进行适当的对齐，
 *         因此最终生成的视频高度不一定就是这里设置的高度！
 *  \param videoHeight 自定义的生成视频高度
 *  \since 1.6.1
 */
- (void)setCustomCompileVideoHeight:(unsigned int)videoHeight;

/*!
 *  \brief 获取当前自定义的生成视频高度。
 *  \return 返回当前自定义的生成视频高度
 *  \since 1.6.1
 */
- (unsigned int)getCustomCompileVideoHeight;

/*!
 *  \brief 连接时间线和实时预览窗口
 *  \param timeline 时间线
 *  \param liveWindow 实时预览窗口
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 */
- (BOOL)connectTimeline:(NvsTimeline *)timeline withLiveWindow:(NvsLiveWindow *)liveWindow;

/*!
 *  \brief 连接时间线和视频帧接收器
 *  \param timeline 时间线
 *  \param receiver 视频帧接收器
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 */
- (BOOL)connectTimeline:(NvsTimeline *)timeline withVideoFrameReceiver:(NvsVideoFrameReceiver *)receiver;

/*!
 *  \brief 定位某一时间戳的图像
 *  \param timeline 时间线
 *  \param timestamp 时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，seekTimeline会返回No,导致无法开启定位。
 *  \param videoSizeMode 图像预览模式
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回BOOL值。注意：定位某时间戳图像是异步操作。返回值为YES则成功开启定位，NO则无法开启定位。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 *  \sa playbackTimeline:startTime:endTime:proxyScale:preload:flags:
 *  \sa seekTimeline:timestamp:proxyScale:flags:
 */
- (BOOL)seekTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp videoSizeMode:(NvsVideoPreviewSizeMode)videoSizeMode flags:(int)flags;

/*!
 *  \brief 定位某一时间戳的图像
 *  \param timeline 时间线
 *  \param timestamp 时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，seekTimeline会返回No,导致无法开启定位。
 *  \param proxyScale 代理缩放比例
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回BOOL值。注意：定位某时间戳图像是异步操作。返回值为YES则成功开启定位，NO则无法开启定位。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 */
- (BOOL)seekTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp proxyScale:(const NvsRational *)proxyScale flags:(int)flags;

/*!
 *  \brief 获取时间线某一时间戳的图像。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param timeline 欲获取图像的时间线对象
 *  \param timestamp 欲获取图像的时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，grabImageFromTimeline会返回nil。
 *  \param proxyScale 代理缩放比例，填写nil表示使用默认比例1:1
 *  \return 返回该时间戳图像的UIImage对象，如果获取图像失败返回nil
 *  \since 1.1.2
 */
- (UIImage *)grabImageFromTimeline:(NvsTimeline *)timeline
                         timestamp:(int64_t)timestamp
                        proxyScale:(const NvsRational *)proxyScale;

/*!
 *  \brief 获取时间线某一时间戳的图像。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param timeline 欲获取图像的时间线对象
 *  \param timestamp 欲获取图像的时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，grabImageFromTimeline会返回nil。
 *  \param proxyScale 代理缩放比例，填写nil表示使用默认比例1:1
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回该时间戳图像的UIImage对象，如果获取图像失败返回nil
 *  \since 1.16.0
 */
- (UIImage *)grabImageFromTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp proxyScale:(const NvsRational *)proxyScale flags:(int)flags;

/*!
 *  \brief 播放时间线
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位是微秒)。startTime取值范围在[0,timeline.duration - 1]。传入其他值无效，playbackTimeline会返回No导致无法开启播放。
 *  \param endTime 结束时间(单位是微秒)。如果endTime值传入是负值，则默认播放到视频末尾。
 *  \param videoSizeMode 图像预览模式
 *  \param preload 是否预先加载
 *  \param flags 预览的特殊标志，如无特殊需求，请填写0。请参见 [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag)
 *  \return 返回BOOL值。注意：播放时间线是异步操作。返回YES则可以开启播放时间线，NO则无法开启播放。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa playbackTimeline:startTime:endTime:proxyScale:preload:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
 */
- (BOOL)playbackTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime videoSizeMode:(NvsVideoPreviewSizeMode)videoSizeMode preload:(BOOL)preload flags:(int)flags;

/*!
 *  \brief 预览播放时间线
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位是微秒)。startTime取值范围在[0,timeline.duration - 1]。传入其他值无效，playbackTimeline会返回No导致无法开启播放。
 *  \param endTime 结束时间(单位是微秒)。如果endTime值传入是负值，则默认播放到视频末尾。
 *  \param proxyScale 代理缩放比例
 *  \param preload 是否预先加载
 *  \param flags 预览的特殊标志，如无特殊需求，请填写0。请参见 [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag)
 *  \return 返回BOOL值。注意：播放时间线是异步操作。返回YES则可以开启播放时间线，NO则无法开启播放。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
 *  \sa seekTimeline:timestamp:proxyScale:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 */
- (BOOL)playbackTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime proxyScale:(const NvsRational *)proxyScale preload:(BOOL)preload flags:(int)flags;

/*!
 *  \brief 停止引擎
 */
- (void)stop;

/*!
 *  \brief 清除缓存资源
 *  \param asynchronous 是否异步
 */
- (void)clearCachedResources:(BOOL)asynchronous;

/*!
 *  \brief 采集设备的数量
 *  \return 返回采集设备数
 */
- (unsigned int)captureDeviceCount;

/*!
 *  \brief 是否为后置采集设备
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 返回BOOL值。返回YES则是后置采集设备，NO则不是。
 */
- (BOOL)isCaptureDeviceBackFacing:(unsigned int)catpureDeviceIndex;

/*!
 *  \brief 获取采集设备的能力描述对象
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 返回采集设备能力描述对象
 */
- (NvsCaptureDeviceCapability *)getCaptureDeviceCapability:(unsigned int)catpureDeviceIndex;

/*!
 *  \brief 连接采集预览和实时预览窗口
 *  \param liveWindow 实时预览窗口
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \sa connectTimeline:withLiveWindow:
 */
- (BOOL)connectCapturePreviewWithLiveWindow:(NvsLiveWindow *)liveWindow;

/*!
 *  \brief 连接采集预览和视频帧接收器
 *  \param receiver 视频帧接收器
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \since 1.7.1
 */
- (BOOL)connectCapturePreviewWithVideoFrameReceiver:(NvsVideoFrameReceiver *)receiver;

/*!
 *  \brief 为视频采集添加用户水印
 *  \param watermarkFilePath 水印文件的路径，须为PNG或JPG文件
 *  \param displayWidth 水印在视频预览画面中显示的宽度，为0则使用图片文件的宽度
 *  \param displayHeight 水印在视频预览画面中显示的高度，为0则使用图片文件的高度
 *  \param opacity 水印的不透明度, 取值范围 0~1
 *  \param position 水印的位置，请参见 [NvsTimelineWatermarkPosition] (@ref NvsTimelineWatermarkPosition)
 *  \param marginX 水印在X方向的边距
 *  \param marginY 水印在Y方向的边距
 *  \since 2.0.1
 */
-(void)setUserWatermarkForCapture:(NSString *)watermarkFilePath
                     displayWidth:(int)displayWidth
                    displayHeight:(int)displayHeight
                          opacity:(float)opacity
                         position:(NvsTimelineWatermarkPosition)position
                          marginX:(int)marginX
                          marginY:(int)marginY;

/*!
 *  \brief 移除为视频采集添加的用户水印
 *  \since 2.0.1
 */
-(void)removeUserWatermarkForCapture;

/*!
 *  \brief 启动采集设备预览
 *  \param captureDeviceIndex 采集设备索引
 *  \param videoResGrade 视频采集分辨率级别。视频分辨率等级是指录制时所拍摄视频短边（即可能是宽度或者是高度）的分辨率值，根据视频横纵比aspectRatio(值为nil则由系统采集设备来决定横纵比)计算得到另一边（即可能是宽度或者是高度）的值。
其包括三种级别，分别是LOW，MEDIUM，HIGH，前置摄像头依次对应480p，540p，720p，后置摄像头依次对应540p，720p，1080p。如果有用户想自定义录制视频的等级，
例如540 * 960,则需要拍摄等横纵比的视频，通过创建宽高依次是540和960的时间线，编辑然后生成。生成时，生成分辨率高度等级里面没有960p的等级，因此需要在生成前调用
setCustomCompileVideoHeight()接口来自定义高度，然后调用生成接口compileTimeline()，生成高度级别设置为NvsCompileVideoResolutionGradeCustom即可。实例代码如下：

            NvsVideoResolution videoEditRes;
            videoEditRes.imageWidth = 540;
            videoEditRes.imageHeight = 960;
            videoEditRes.imagePAR = (NvsRational){1, 1};
            NvsRational videoFps = {25, 1};
            NvsAudioResolution audioEditRes;
            audioEditRes.sampleRate = 48000;
            audioEditRes.channelCount = 2;
            audioEditRes.sampleFormat = NvsAudSmpFmt_S16;
            self.timeline = [_context createTimeline:&videoEditRes videoFps:&videoFps audioEditRes:&audioEditRes];//创建时间线
            [_context setCustomCompileVideoHeight:960];//设置自定义高度
            [self.context compileTimeline:self.timeline startTime:0 endTime:self.timeline.duration outputFilePath:videoPath
            videoResolutionGrade:NvsCompileVideoResolutionGradeCustom videoBitrateGrade:NvsCompileBitrateGradeMedium flags:0];//生成视频
*  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineCaptureFlag] (@ref NvsStreamingEngineCaptureFlag)。每个Flag应用场景如下：
<br>NvsStreamingEngineCaptureFlag_GrabCapturedVideoFrame用于视频抠像；
<br>NvsStreamingEngineCaptureFlag_StrictPreviewVideoSize与NvsStreamingEngineCaptureFlag_CaptureBuddyHostVideoFrame结合用于人脸识别；
<br>NvsStreamingEngineCaptureFlag_DontCaptureAudio用于视频直播，不采集音频流，一般不常用。
*  \param aspectRatio 预览视频横纵比，传入nil则由系统采集设备来决定横纵比
*  \return 返回BOOL值。返回YES则启动预览成功，NO则启动预览失败。
*/
- (BOOL)startCapturePreview:(unsigned int)captureDeviceIndex
              videoResGrade:(NvsVideoCaptureResolutionGrade)videoResGrade
                      flags:(int)flags
                aspectRatio:(const NvsRational *)aspectRatio;


/*!
 *  \brief 启动输入buffer模式的采集设备预览
 *  \param width 输入buffer的宽
 *  \param height 输入buffer的高
 *  \param fps 输入buffer的帧率
 *  \param rotation 输入buffer的图像旋转角度。请参见 [输入buffer的图像旋转角度] (@ref BufferImageRotation)
 *  \param flipHorizontally 是否需要水平翻转
*  \return 返回BOOL值。返回YES则启动预览成功，NO则启动预览失败。
* \sa sendBufferToCapturePreview
*/
- (BOOL)startBufferCapturePreview:(unsigned int)width
                                                height:(unsigned int)height
  fps:(const NvsRational *)fps
  rotation:(int)rotation
  flipHorizontally:(BOOL)flipHorizontally;

/*!
 *  \brief 输入buffer给采集设备预览
 *  \param data 输入buffer的数据和相应信息。仅支持NV12格式的数据
 *  \return 返回BOOL值。
 * \sa startBufferCapturePreview
*/
- (BOOL)sendBufferToCapturePreview:(const NvsVideoFrameInfo *)data;

/*!
 *  \brief 为直播启动采集设备预览
 *  \param captureDeviceIndex 采集设备索引
 *  \param videoResGrade 视频采集分辨率级别
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineCaptureFlag] (@ref NvsStreamingEngineCaptureFlag)
 *  \param aspectRatio 预览视频横纵比，传入nil则由系统采集设备来决定横纵比
 *  \param liveStreamingEndPoint 直播推流的目的地址(rtmp://xxx)
 *  \return 返回BOOL值。返回YES则启动预览成功，NO则启动预览失败。
 *  \since 1.1.0
 */
- (BOOL)startCapturePreviewForLiveStreaming:(unsigned int)captureDeviceIndex
                              videoResGrade:(NvsVideoCaptureResolutionGrade)videoResGrade
                                      flags:(int)flags
                                aspectRatio:(const NvsRational *)aspectRatio
                      liveStreamingEndPoint:(NSString *)liveStreamingEndPoint;

/*!
 *  \brief 获取采集预览视频分辨率
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 获取采集预览视频分辨率
 *  \since 1.7.1
 */
- (NvsSize)getCapturePreviewVideoSize:(unsigned int)catpureDeviceIndex;

/*!
 *  \brief 对采集设备的视频帧内容进行采样
 *  \param sampleRect 采样的矩形区域，坐标为实时预览窗口的自身坐标系
 *  \return 返回值为采样的颜色值，该颜色值是采样的矩形区域内所有像素颜色的平均值
 *  \since 1.2.0
 */
- (NvsColor)sampleColorFromCapturedVideoFrame:(CGRect)sampleRect;

/*!
 *  \brief 启动自动聚焦
 *  \param focusPointOfInterest 自动聚焦的目标点，坐标为实时预览窗口的自身坐标系
 *  \sa cancelAutoFocus
 */
- (void)startAutoFocus:(CGPoint)focusPointOfInterest;

/*!
 *  \brief 取消正在进行中的自动聚焦
 *  \sa startAutoFocus:
 */
- (void)cancelAutoFocus;

/*!
 *  \brief 启动自动曝光调节
 *  \param pointOfInterest 曝光调节点
 */
- (void)startAutoExposure:(CGPoint)pointOfInterest;

/*!
 *  \brief 设置缩放因子
 *  \param zoomFactor 缩放比例
 *  \sa getZoomFactor
 */
- (void)setZoomFactor:(float)zoomFactor;

/*!
 *  \brief 获取缩放因子
 *  \return 返回缩放因子值
 *  \sa setZoomFactor:
 */
- (float)getZoomFactor;

/*!
 *  \brief 开/关换补光灯
 *  \param on 设置灯光开或关
 *  \sa isFlashOn
 */
- (void)toggleFlash:(BOOL)on;

/*!
 *  \brief 开/关换补光灯状态
 *  \return 返回BOOL值。返回YES则换补光灯是打开状态，NO则是关闭状态。
 *  \sa toggleFlash:
 */
- (BOOL)isFlashOn;

/*!
 *  \brief 获取当前的视频防抖动标志
 *  \sa setVideoStabilization
 */
- (VideoStabilizationFlag)getVideoStabilization;

/*!
 *  \brief 设置视频防抖动
 *  \param flags 视频防抖动值
 *  \sa getVideoStabilization:
 */
- (void)setVideoStabilization:(VideoStabilizationFlag)flags;
/*!
 *  \brief 设置曝光补偿
 *  \param exposureBias 曝光补偿值
 *  \sa getExposureBias
 */
- (void)setExposureBias:(float)exposureBias;

/*!
 *  \brief 获取曝光补偿
 *  \return 返回曝光补偿值
 *  \sa setExposureBias:
 */
- (float)getExposureBias;

/*!
 *  \brief 给采集追加一个内建视频特效
 *  \param videoFxName 视频特效名。获取视频特效名称，请参见[getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)。
 *  \return 返回追加的内建视频特效对象
 *  \sa insertBuiltinCaptureVideoFx:withInsertPosition:
 */
- (NvsCaptureVideoFx *)appendBuiltinCaptureVideoFx:(NSString *)videoFxName;

/*!
 *  \brief 给采集插入一个内建视频特效
 *  \param videoFxName 视频特效名。获取视频特效名称，请参见[getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)。
 *  \param insertPosition 插入位置
 *  \return 返回插入的内建视频特效对象
 *  \sa appendBuiltinCaptureVideoFx:
 */
- (NvsCaptureVideoFx *)insertBuiltinCaptureVideoFx:(NSString *)videoFxName withInsertPosition:(unsigned int)insertPosition;

/*!
 *  \brief 给采集追加一个包裹视频特效
 *  \param videoFxPackageId 视频特效包裹ID
 *  \return 返回追加的包裹视频特效对象
 *  \sa insertPackagedCaptureVideoFx:withInsertPosition:
 */
- (NvsCaptureVideoFx *)appendPackagedCaptureVideoFx:(NSString *)videoFxPackageId;

/*!
 *  \brief 给采集插入一个包裹视频特效
 *  \param videoFxPackageId 视频特效包裹ID
 *  \param insertPosition 插入位置
 *  \return 返回插入的包裹视频特效对象
 *  \sa appendPackagedCaptureVideoFx:
 */
- (NvsCaptureVideoFx *)insertPackagedCaptureVideoFx:(NSString *)videoFxPackageId withInsertPosition:(unsigned int)insertPosition;

/*!
 *  \brief 在片段上追加自定义采集视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \return 返回追加的采集视频特效对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \since 1.7.0
 */
- (NvsCaptureVideoFx *)appendCustomCaptureVideoFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender;

/*!
 *  \brief 在片段上指定特效索引处插入自定义采集视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \param insertPosition 插入位置
 *  \return 返回插入的采集视频特效对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \since 1.7.0
 */
- (NvsCaptureVideoFx *)insertCustomCaptureVideoFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender withInsertPosition:(int)insertPosition;

/*!
 *  \brief 给采集追加一个美颜视频特效
 *  \return 返回追加的美颜视频特效对象
 *  \sa insertBeautyCaptureVideoFx:
 */
- (NvsCaptureVideoFx *)appendBeautyCaptureVideoFx;

/*!
 *  \brief 给采集插入一个美颜视频特效
 *  \param insertPosition 插入位置
 *  \return 返回插入的美颜视频特效对象
 *  \sa appendBeautyCaptureVideoFx:
 */
- (NvsCaptureVideoFx *)insertBeautyCaptureVideoFx:(unsigned int)insertPosition;

/*!
 *  \brief 对采集的视频移除特定索引值的采集视频特效
 *  \param captureVideoFxIndex 视频特效索引
 *  \return 返回BOOL值。返回YES则移除成功，NO则失败
 *  \sa appendBuiltinCaptureVideoFx:
 *  \sa appendPackagedCaptureVideoFx:
 *  \sa appendBeautyCaptureVideoFx
 */
- (BOOL)removeCaptureVideoFx:(unsigned int)captureVideoFxIndex;

/*!
 *  \brief 移除所有采集视频特效
 *  \sa removeCaptureVideoFx:
 *  \sa getCaptureVideoFxCount
 */
- (void)removeAllCaptureVideoFx;

/*!
 *  \brief 获得采集视频特效的数量
 *  \return 返回视频特效数量
 */
- (unsigned int)getCaptureVideoFxCount;

/*!
 *  \brief 获得采集视频特效的对象
 *  \param captureVideoFxIndex 视频特效索引
 *  \return 返回视频特效对象
 *  \sa removeCaptureVideoFx:
 */
- (NvsCaptureVideoFx *)getCaptureVideoFxByIndex:(unsigned int)captureVideoFxIndex;

/*!
 *  \brief 对采集设备应用拍摄场景资源包
 *  \param captureSceneId 拍摄场景资源包的ID
 *  \return 返回BOOL值。值为YES则应用成功，NO则失败。
 *  \since 1.2.0
 *  \sa getCurrentCaptureSceneId
 *  \sa removeCurrentCaptureScene
 */
- (BOOL)applyCaptureScene:(NSString *)captureSceneId;

/*!
 *  \brief 取得当前拍摄场景资源包的ID
 *  \return 当前拍摄场景资源包的ID字符串，返回nil表示当前没有拍摄场景资源包
 *  \since 1.2.0
 *  \sa applyCaptureScene:
 *  \sa removeCurrentCaptureScene
 */
- (NSString *)getCurrentCaptureSceneId;

/*!
 *  \brief 移除当前拍摄场景
 *  \since 1.2.0
 *  \sa applyCaptureScene:
 *  \sa getCurrentCaptureSceneId
 */
- (void)removeCurrentCaptureScene;

/*!
 *  \brief 获取人脸特技上下文
 *  \since 1.17.0
 */
- (NvsAREffectContext*)getAREffectContext;

/*!
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \sa stopRecording
 */
- (BOOL)startRecording:(NSString *)outputFilePath;

/*!
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \since 1.5.1
 *  \sa stopRecording
 */
- (BOOL)startRecording:(NSString *)outputFilePath withFlags:(int)flags;

/*!
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations 录制视频配置。NSMutableDictionary中关键字的值请参见 [录制视频配置] (@ref RECORD_CONFIGURATIONS)
 *         例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \since 1.16.0
 *  \sa stopRecording
 */
- (BOOL)startRecording:(NSString *)outputFilePath withFlags:(int)flags withRecordConfigurations:(NSMutableDictionary *)withRecordConfigurations;

/*!
 *  \brief 启动采集设备的录制，录制的内容包含所有的特效处理效果。
 *
 * 注意：如果特效处理过于复杂可能会导致录制的视频丢帧，所以使用这个方法一定要慎重，要确保特效的处理对于当前
 * 手机是完全可以实时处理的。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。我们建议输出.mov格式的文件
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \sa stopRecording
 */
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath;

/*!
 *  \brief 启动采集设备的录制，录制的内容包含所有的特效处理效果。
 *
 * 注意：如果特效处理过于复杂可能会导致录制的视频丢帧，所以使用这个方法一定要慎重，要确保特效的处理对于当前
 * 手机是完全可以实时处理的。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \since 1.5.1
 *  \sa stopRecording
 */
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath withFlags:(int)flags;

/*!
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations 录制视频配置。NSMutableDictionary中关键字的值请参见 [录制视频配置] (@ref RECORD_CONFIGURATIONS)
 *         例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \since 1.16.0
 *  \sa stopRecording
 */
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath withFlags:(int)flags withRecordConfigurations:(NSMutableDictionary *)withRecordConfigurations;

/*!
 *  \brief 结束录制采集设备信号
 *  \sa startRecording:
 */
- (void)stopRecording;

/*!
 *  \brief 暂停录制采集信号。暂停录制之后再继续录制会录制到同一个媒体文件中。注意：只有不使用系统内置recorder时才能暂停录制！
 *  \return 返回布尔值。值为YES则暂停录制成功，NO则失败。
 *  \since 1.17.0
 *  \sa resumeRecording
 */
- (BOOL)pauseRecording;

/*!
 *  \brief 继续录制采集信号。继续录制会录制到暂停之前的同一个媒体文件中。
 *  \return 返回布尔值。值为YES则继续录制成功，NO则失败。
 *  \since 1.17.0
 *  \sa pauseRecording
 */
- (BOOL)resumeRecording;

/*!
 *  \brief 检查录制是否已经暂停
 *  \return 返回布尔值。值为YES则录制已经暂停，NO为未暂停。
 *  \since 1.17.0
 *  \sa pauseRecording
 *  \sa resumeRecording
 */
- (BOOL)isRecordingPaused;

/*!
 *  \brief 获取全部内嵌视频特效名称
 *  \return 返回包含所有内嵌的视频特效名称的数组对象
 *  \sa getAllBuiltinAudioFxNames
 */
- (NSArray *)getAllBuiltinVideoFxNames;

/*!
 *  \brief 获取全部内嵌音频特效名称
 *  \return 返回包含所有内嵌的音频特效名称的数组对象
 *  \sa getAllBuiltinVideoFxNames
 */
- (NSArray *)getAllBuiltinAudioFxNames;

/*!
 *  \brief 获取全部内嵌视频转场名称
 *  \return 返回包含所有内嵌的视频转场名称的数组对象
    \sa getAllBuiltinCaptureVideoFxNames
    \sa getBeautyVideoFxName
    \sa getDefaultVideoTransitionName
 */
- (NSArray *)getAllBuiltinVideoTransitionNames;

/*!
 *  \brief 获取全部内嵌采集视频特效名称
 *  \return 返回包含所有内嵌的采集视频特效名称的数组对象
 *  \sa getBeautyVideoFxName
 *  \sa getAllBuiltinVideoFxNames
 */
- (NSArray *)getAllBuiltinCaptureVideoFxNames;

/*!
 *  \brief 获得美颜的视频特效名称
 *  \return 返回包含所有美颜视频特效名称的数组对象
    \sa getAllBuiltinVideoFxNames
    \sa getAllBuiltinCaptureVideoFxNames
 */
- (NSString *)getBeautyVideoFxName;

/*!
 *  \brief 获得默认视频转场名称
 *  \return 返回表示默认转场名称的字符串
 *  \sa getAllBuiltinVideoTransitionNames
 */
- (NSString *)getDefaultVideoTransitionName;

/*!
 *  \brief 获取视频特效描述
 *  \param fxName 视频特效名称
 *  \return 返回视频特效描述的对象
 *  \sa getAudioFxDescription:
 */
- (NvsFxDescription *)getVideoFxDescription:(NSString *)fxName;

/*!
 *  \brief 获取音频特效描述
 *  \param fxName 音频特效名称
 *  \return 返回音频特效描述的对象
 *  \sa getVideoFxDescription:
 */
- (NvsFxDescription *)getAudioFxDescription:(NSString *)fxName;

/*!
 *  \brief 创建视频帧提取对象
 *  \param videoFilePath 原始视频文件路径
 *  \return 返回NvsVideoFrameRetriever对象，表示视频帧提取对象
 *  \since 1.2.0
 */
- (NvsVideoFrameRetriever *)createVideoFrameRetriever:(NSString *)videoFilePath;


@end

/*!
 *  \brief 采集设备能力描述
 *
 *  定义采集设备的相关属性，包含自动聚焦，自动曝光，缩放等
 */
@interface NvsCaptureDeviceCapability : NSObject

@property (readonly) BOOL supportAutoFocus;      //!< \if ENGLISH \else 是否支持自动聚焦 \endif
@property (readonly) BOOL supportAutoExposure;   //!< \if ENGLISH \else 是否支持自动曝光 \endif
@property (readonly) BOOL supportZoom;           //!< \if ENGLISH \else 是否支持缩放 \endif
@property (readonly) float maxZoomFactor;        //!< \if ENGLISH \else 最大缩放比例 \endif
@property (readonly) BOOL supportFlash;          //!< \if ENGLISH \else 是否支持换补灯光 \endif
@property (readonly) BOOL supportVideoStabilization;          //!< \if ENGLISH \else 是否支持防抖动 \endif
@property (readonly) BOOL supportExposureBias;   //!< \if ENGLISH \else 是否支持曝光补偿 \endif
@property (readonly) float minExposureBias;      //!< \if ENGLISH \else 最小曝光补偿系数 \endif
@property (readonly) float maxExposureBias;      //!< \if ENGLISH \else 最大曝光补偿系数 \endif

@end

