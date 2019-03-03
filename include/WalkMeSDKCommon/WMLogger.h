//
//  WMLogger.h
//  ABBISDK
//
//  Created by Kobi Stok on 13/12/2015.
//  Copyright © 2015 Kobi Stok. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kWMLoggerEnabledNotifName @"WMLoggerEnabledNotifName"

#define __FILE_NAME__ [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String]
#define WMLog( s, ... ) [WMLogger Log:[NSString stringWithFormat:@"%s:%d %s %@", \
__FILE_NAME__, \
__LINE__, \
__PRETTY_FUNCTION__, \
[NSString stringWithFormat:(s), ##__VA_ARGS__]]]

@interface WMLogger : NSObject

+ (void)setLogsEnabled:(BOOL)enabled;
+ (BOOL)areLogsEnabled;
+ (void)Log:(NSString*)log withClass:(id)cls;
+ (void)Log:(NSString*)log;

+ (void)readLogsFileWithCompletion:(void (^)(NSString *content))completion;

@end
