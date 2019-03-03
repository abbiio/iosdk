//
//  WMStateMachineBase.h
//  WalkMeLib
//
//  Created by walkme_ps on 10/15/14.
//  Copyright (c) 2014 walkme_ps. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WMStateBase;

@interface WMStateMachineBase : NSObject

@property (nonatomic,strong) WMStateBase* currentState;

- (void)switchState:(__kindof WMStateBase*)newState;

@end
