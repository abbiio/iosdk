//
//  WMStateBase.h
//  WalkMeSDKCommon
//
//  Created by Haim Ben Chimol on 28/01/2019.
//  Copyright © 2019 WalkMe. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WMStateMachineBase;
@protocol WMStateInterface <NSObject>

@required
- (void)enter;
- (void)exit;

@end

@interface WMStateBase : NSObject <WMStateInterface>

@property (nonatomic,weak) WMStateMachineBase* owner;
@property (nonatomic,readonly) NSString *name; // State class name

@end

NS_ASSUME_NONNULL_END
