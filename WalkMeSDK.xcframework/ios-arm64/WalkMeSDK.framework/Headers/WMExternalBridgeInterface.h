//
//  WMExternalBridgeInterface.h
//  WalkMeSDKCommon
//
//  Created by Guy Sharony on 21/12/2022.
//  Copyright © 2022 WalkMe. All rights reserved.
//

#ifndef WMExternalBridgeInterface_h
#define WMExternalBridgeInterface_h

typedef void (^WMExternalBridgeResponseCallback)(id responseData);
typedef void (^WMExternalBridgeHandler)(id data, WMExternalBridgeResponseCallback responseCallback);

@protocol WMExternalBridgeInterface <NSObject>

@property (nonatomic, strong, readonly) Class containerViewClass;

@required
- (void)registerHandler:(NSString *)handlerName handler:(WMExternalBridgeHandler)handler;
- (void)removeHandler:(NSString *)handlerName;
- (void)callHandler:(NSString *)handlerName data:(id)data responseCallback:(WMExternalBridgeResponseCallback)responseCallback;

@end

#endif /* WMExternalBridgeInterface_h */
