//
//  WMUserData.h
//  ABBISDK
//
//  Created by WalkMe on 07/03/2018.
//  Copyright © 2018 Abbi Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WMUserData : NSObject

/**
 * User attributes in current session
 */
@property (nonatomic,strong) NSDictionary *userAttributes;

/**
 * Private user attributes in current session
 */
@property (nonatomic,strong) NSDictionary *privateUserAttributes;

/**
 * User session duration in seconds
 */
@property (nonatomic,strong) NSNumber *sessionDuration;

/**
 * User's iOS version
 */
@property (nonatomic,strong) NSString *systemVersion;

/**
 * Device unique ID
 */
@property (nonatomic,strong) NSString *deviceId;

/**
 * Device model
 */
@property (nonatomic,strong) NSString *deviceModel;

/**
 * Device orientation PRT_REG / PRT_USD / LSL / LSR
 */
@property (nonatomic,strong) NSString *deviceOrientation;

/**
 * Application version
 */
@property (nonatomic,strong) NSString *appVersion;

/**
 * Application name
 */
@property (nonatomic,strong) NSString *appName;

/**
 * Locale language for user's device
 */
@property (nonatomic,strong) NSString *locale;

/**
 * WalkMe SDK version
 */
@property (nonatomic,strong) NSString *sdkVer;

/**
 * Session unique id
 */
@property (nonatomic,strong) NSString *sessionId;

/**
 * Is push notification approved for user
 */
@property (nonatomic,strong) NSString *isPushEnabled;

/**
 * User device timezone
 */
@property (nonatomic,strong) NSString *timezone;

/**
 * User current network ( WIFI / CELLULAR / OFFLINE )
 */
@property (nonatomic,strong) NSString *network;

/**
 * User OS system name
 */
@property (nonatomic,strong) NSString *systemName;

/**
 * User creation timestamp
 */
@property (nonatomic,strong) NSNumber *userCreationTimestamp;

/**
 * Did the user use the app for the first time
 */
@property (nonatomic,assign) BOOL isNewUser;

@end
