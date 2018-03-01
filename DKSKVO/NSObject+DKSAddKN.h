//
//  NSObject+DKSAddKN.h
//  DKSKVO
//
//  Created by aDu on 2018/3/1.
//  Copyright © 2018年 DuKaiShun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (DKSAddKN)

#pragma mark ====== KVO ======
/**
 添加一个监听，无需手动移除，在监听对象销毁时自动移除，下面的两个移除方法一般无需使用

 @param keyPath 监听路径
 @param block KVO回调block，obj为监听对象，oldVal为旧值，newVal为新值
 */
- (void)ks_addObserverBlockForKeyPath:(NSString *)keyPath block:(void (^)(id obj, id oldVal, id newVal))block;

/**
 移除指定的keyPath（一般无需使用，如果需要提前注销KVO才需要）

 @param keyPath 移除路径
 */
- (void)ks_removeObserverBlockForKeyPath:(NSString *)keyPath;

/**
 移除所有的KVOBlock（一般无需使用）
 */
- (void)ks_removeAllObserverBlocks;

#pragma mark ====== Notification ======
/**
 *  通过block方式注册通知，通过该方式注册的通知无需手动移除，同样会自动移除
 *
 *  @param name  通知名
 *  @param block 通知的回调Block，notification为回调的通知对象
 */
- (void)ks_addNotificationForName:(NSString *)name block:(void (^)(NSNotification *notification))block;

/**
 *  提前移除某一个name的通知
 *
 *  @param name 需要移除的通知名
 */
- (void)ks_removeNotificationForName:(NSString *)name;

/**
 *  提前移除所有通知
 */
- (void)ks_removeAllNotification;

/**
 *  发送一个通知
 *
 *  @param name     通知名
 *  @param userInfo 数据字典
 */
- (void)ks_postNotificationWithName:(NSString *)name userInfo:(nullable NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
