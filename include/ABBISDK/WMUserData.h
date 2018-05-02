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
 * User Attributes in current session.
 */
@property (nonatomic,strong) NSDictionary *userAttributes;

/**
 * Private User Attributes in current session.
 */
@property (nonatomic,strong) NSDictionary *privateUserAttributes;

/**
 * User Session Duration in second.
 */
@property (nonatomic,strong) NSNumber *sessionDuration;

/**
 * User's iOS version
 */
@property (nonatomic,strong) NSString *systemVersion;

/**
 * Device Unique ID
 */
@property (nonatomic,strong) NSString *deviceId;

/**
 * Device Model.
 */
@property (nonatomic,strong) NSString *deviceModel;

/**
 * Device Orientation PRT_REG / PRT_USD / LSL / LSR.
 */
@property (nonatomic,strong) NSString *deviceOrientation;

/**
 * The application version.
 */
@property (nonatomic,strong) NSString *appVersion;

/**
 * The application name.
 */
@property (nonatomic,strong) NSString *appName;

/**
 * Locale language for user's device.
 */
@property (nonatomic,strong) NSString *locale;

/**
 * WalkMe SDK version.
 */
@property (nonatomic,strong) NSString *sdkVer;

/**
 * Session unique id.
 */
@property (nonatomic,strong) NSString *sessionId;

/**
 * If Push notification approved for user.
 */
@property (nonatomic,strong) NSString *isPushEnabled;

/**
 * User device timezone.
 */
@property (nonatomic,strong) NSString *timezone;

/**
 * User current network ( WIFI / 3G ).
 */
@property (nonatomic,strong) NSString *network;

/**
 * User OS System Name.
 */
@property (nonatomic,strong) NSString *systemName;

/**
 * Current Timestamp for this User.
 */
@property (nonatomic,strong) NSString *timestamp;

@end
