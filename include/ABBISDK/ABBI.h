//
//  ABBI.h
//  ABBISDK
//
//  Navigate to https://console.abbi.io to Register/Login and Manage Your Promotions
//  For support, drop us an email at Support@abbi.io
//  Copyright © 2015 ABBI Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABBI : NSObject

+(void) start: (NSString*) appId withSecretKey: (NSString*) appSecretKey;

@end
