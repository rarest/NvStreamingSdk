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
#import "NvsCommonDef.h"

/*!
 * \brief NvsObject类，继承自object-c里的NSObject类。
 *
 * NvsObject类是SDK里大多数类的基类，通过NvsObject类，其他类继承了一些基础的与object-c语言编译系统之间的接口，并且获得了在它的实例中表现为一个对象的能力。
 * \warning NvsObject类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsObject : NSObject
/*!
   \brief 给NvsObject对象添加附件，用来标识NvsObject的对象或者用于其他用途
   \param key 要添加的附件所对应的key
   \param value 要添加的附件
   \since 1.11.1
   \sa getAttachment:
*/
- (void)setAttachment:(NSObject*)value forKey:(NSString*)key;

/*!
   \brief 获取已经添加的附件
   \param key 附件所对应的key
   \return 返回key所对应的附件
   \since 1.11.1
   \sa setAttachment:forKey:
*/
- (NSObject*)getAttachment:(NSString*)key;
@end

