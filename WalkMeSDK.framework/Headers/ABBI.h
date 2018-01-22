// Copyright © 2016 ABBI Ltd. <https://abbi.io> All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 * Enum to Support Hybrid iOS apps (i.e. webview based apps)
 * Use - (void) start: (NSString*) appId withSecretKey: (NSString*) appSecretKey andApplicationType:(ABBIAppType) type;
 *
 */
typedef enum {ABBI_APP_NATIVE = 10, ABBI_APP_HYBRID = 11, ABBI_APP_COCOS2D = 12, ABBI_APP_UNITY = 13, ABBI_APP_MAX = 14} ABBIAppType;
typedef enum {GOAL = 1} EventType;

/**
* ABBI class manages the execution of ABBI SDK.
* Navigate to https://console.abbi.io to Register/Login and Manage Your Promotions
* For support, drop us an email at Support@abbi.io
*/
@interface ABBI : NSObject

/** 
 * Starts ABBI SDK.
 *
 * @param appId The Application Id provided by ABBI
 * @param appSecretKey The Application Secret key provided by ABBI
 * 
 * To get your Application Id and Application Secret key, login to Abbi console at https://console.abbi.io
 * and click the settings icon near your Application Name. You can find more info here - https://abbi.zendesk.com/hc
 */
+ (void)start:(NSString *)appId withSecretKey:(NSString *)appSecretKey;

/** 
 * Starts ABBI SDK - FOR HYBRID APPS ONLY!
 *
 * @param appId The Application Id provided by ABBI
 * @param appSecretKey The Application Secret key provided by ABBI
 * @param type The Application Type (i.e. ABBI_APP_HYBRID)
 *
 * To get your Application Id and Application Secret key, login to Abbi console at https://console.abbi.io
 * and click the settings icon near your Application Name. You can find more info here - https://abbi.zendesk.com/hc
 */
+ (void)start:(NSString *)appId withSecretKey:(NSString *)appSecretKey andApplicationType:(ABBIAppType)type;

/**
 * Sends a Goal to ABBI's Backend.
 * A Goal is a user action that can be used to target your users.
 *
 * Usage Example :@
 *
 * [ABBI sendGoal:@"Bought a blue sword" withProperites:nil]
 * [ABBI sendGoal:@"Bought a blue sword" withProperites:@{@"item_name", @"unlimited_calls"}]
 *
 * @param goalName the Goal name.
 * @param properties the Goal properties, key-value structured (if any).
 */
+ (void)sendGoal:(NSString *)goalName withProperites:(NSDictionary *)properties;

/**
 * Deprecated. Please use setUserAttributeWithKey:andValue: instead.
 */
+ (void)setUserDataKey:(NSString*)key withValue:(NSString*)value DEPRECATED_MSG_ATTRIBUTE("use setUserAttributeWithKey:andValue:");

/**
 * Deprecated. Please use setUserAttributes: instead.
 */
+ (void)setUserDataProperties:(NSDictionary<NSString*,NSString*>*)properties DEPRECATED_MSG_ATTRIBUTE("use setUserAttributes:");

/**
 * Sets a user attribute
 *
 * @param key the attribute key
 * @param value the attribute value
 * 
 * @code
 * Usage Examples:
 * [ABBI setUserAttributeWithKey:@"isProUser" andValue:@YES];
 * [ABBI setUserAttributeWithKey:@"isLoggedIn" andValue:@(0)];
 */
+ (void)setUserAttributeWithKey:(NSString *)key andValue:(id)value;

/**
 * Sets multiple user attributes
 *
 * @param attributes the user attributes
 * 
 * @code
 * Usage Example:
 * [ABBI setUserAttributes:@{@"isProUser": @YES, @"isLoggedIn": @(0)}];
 */
+ (void)setUserAttributes:(NSDictionary<NSString*,id> *)attributes;

/**
 * Sets a private user attribute
 *
 * @param key the attribute key
 * @param value the attribute value
 *
 * @code
 * Usage Examples:
 * [ABBI setPrivateUserAttributeWithKey:@"gender" andValue:@"female"];
 * [ABBI setPrivateUserAttributeWithKey:@"balance" andValue:@(1000)];
 */
+ (void)setPrivateUserAttributeWithKey:(NSString *)key andValue:(id)value;

/**
 * Sets multiple private user attributes
 *
 * @param attributes the private user attributes
 *
 * @code
 * Usage Example:
 * [ABBI setPrivateUserAttributes:@{@"gender": @"female", @"balance": @(1000)}];
 */
+ (void)setPrivateUserAttributes:(NSDictionary<NSString*,id> *)attributes;

/**
 * Clears all private user attributes
 */
+ (void)clearPrivateUserAttributes;

/** 
 * Utility function for remote sessions with ABBI support team.
 *
 * @param n Will be given by ABBI support team when needed
 */
+ (void)setFlag:(int)n;

/**
 * Launches a campaign by trigger key
 * Once invoked, the method will show the campaign WITHOUT any of its segments (if defined)
 *
 * @code
 * Usage Example :
 * [ABBI trigger:@"Show How To Order Credit Card"];
 */
+ (void)trigger:(NSString *)myTriggerName;


@end
