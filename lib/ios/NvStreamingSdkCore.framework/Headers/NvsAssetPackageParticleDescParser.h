//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jan 23. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"

/*!
 *  \brief 资源包类型
 */
typedef enum
{
    NvsParticleType_Normal = 0,         //!< \if ENGLISH \else 一般指没有交互的粒子效果 \endif
    NvsParticleType_Touch,              //!< \if ENGLISH \else 触摸屏幕进行交互的粒子效果 \endif
    NvsParticleType_Gesture,            //!< \if ENGLISH \else 手势进行交互的粒子效果 \endif
    NvsParticleType_Eye,                //!< \if ENGLISH \else 眼睛进行交互的效果 \endif
    NvsParticleType_Mouth,              //!< \if ENGLISH \else 嘴巴进行交互的粒子效果 \endif
} NvsParticleType;


/*!
 *  \brief 资源包状态
 */
typedef enum
{
    NvsEmitterPlace_Left = 0,       //!< \if ENGLISH brief enum description \else 粒子发生器在当前部位的左边 \endif
    NvsEmitterPlace_Right,          //!< \if ENGLISH brief enum description \else 粒子发生器在当前部位的右边 \endif
    NvsEmitterPlace_Top,            //!< \if ENGLISH brief enum description \else 粒子发生器在当前部位的上边 \endif
    NvsEmitterPlace_Bottom,         //!< \if ENGLISH brief enum description \else 粒子发生器在当前部位的下边 \endif
    NvsEmitterPlace_Center          //!< \if ENGLISH brief enum description \else 粒子发生器在当前部位的中间 \endif
} NvsEmitterPlace;



/*!
 *  \brief 粒子特技包描述解析器
 *  \warning NvsAssetPackageParticleDescParser类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsAssetPackageParticleDescParser : NSObject


- (instancetype)initWithEffectDesc:(NSString *)desc;

/*!
  *  \brief 获取粒子类型
  *  \return 返回粒子类型。
  *
  */

- (NvsParticleType) getParticleType;


/*!
*  \brief 获取粒子分片数量
*  \return 返回分片数量
*/
-(int) getParticlePartitionCount;


/*!
   *  \brief 获取某一分片粒子发射器应该放置的位置
   *  \param partitionIndex
   *  \return 返回放置的位置
   */
- (NvsEmitterPlace) getParticlePartitionPlace:(unsigned int)partitionIndex;

   /*!
   *  \brief 获取某一分片粒子发射器名字
   *  \param partitionIndex
   *  \return  返回NSArray数组对象，表示某个类型下资源包的的列表。列表里每个NSString元素都是一个发射器名字。
   */
 - (NSArray *) getParticlePartitionEmitter:(unsigned int)partitionIndex;


/////////////////////////////////////////////////////////////////////////////////
//

/*!
   *  \brief 获取放在左眼粒子发射器位置
   *  \return 返回放置的位置
   */
- (NvsEmitterPlace) getLeftEyePlace;

/*!
    *  \brief 获取放在左眼粒子发射器名字
    *  \return 返回粒子发生器名字
    */
- (NSArray *) getLeftEyeEmitter;

    /*!
    *  \brief 获取放在右眼粒子发射器位置
    *  \return 返回放置的位置
    */
-(NvsEmitterPlace) getRightEyePlace;
    /*!
    *  \brief 获取放在右眼粒子发射器名字
    *  \return 返回粒子发生器名字
    */
-(NSArray *) getRightEyeEmitter;

@end

