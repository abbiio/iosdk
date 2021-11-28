//
//  WMStartOptions.h
//  ABBISDK
//
//  Created by Guy Sharony on 08/07/2019.
//  Copyright © 2019 WalkMe Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMCampaignInfo.h"

/**
 * Enum to Support Hybrid iOS apps (i.e. webview based apps)
 * Use - (void) start: (NSString*) appId withSecretKey: (NSString*) appSecretKey andApplicationType:(ABBIAppType) type;
 *
 */
typedef enum {ABBI_APP_NATIVE = 10, ABBI_APP_HYBRID = 11, ABBI_APP_COCOS2D = 12, ABBI_APP_UNITY = 13, ABBI_APP_MAX = 14} ABBIAppType;

/**
 * Enum for events which can be filtered from being sent
 */
typedef NS_ENUM(NSUInteger, WMStatsEventType)
{
    WMStatsEventTypeSessionStarted,
    WMStatsEventTypeSessionStop,
    WMStatsEventTypeAppTerminated,
    WMStatsEventTypeAppEnteredFg,
    WMStatsEventTypeAppEnteredBg,
    WMStatsEventTypePromoImp,
    WMStatsEventTypePromoClk,
    WMStatsEventTypeStepImp,
    WMStatsEventTypeStepClk,
    WMStatsEventTypeGoal,
    WMStatsEventTypeViewTransition,
    WMStatsEventTypeUsers,
    WMStatsEventTypeOnboardingItemCompleted
};

/**
 * Enum for proxy mode
 */
typedef NS_ENUM(NSUInteger, WMProxyOptionMode)
{
    WMProxyOptionModeAll = 0,
    WMProxyOptionModeAnalytics = 1
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Interface definition for a callback to be invoked in Campaign actions.
 */
@protocol WMCampaignInfoDelegate <NSObject>

/**
 * Called after campaign was dismissed.
 *
 * @param campaignInfo The dismissed campaign info.
 */
@optional
- (void)campaignDidDismiss:(WMCampaignInfo *)campaignInfo;

/**
 * Called right before the campaign is about to be shown (will not be called on Power Mode preview)
 *
 * @param campaignInfo The shown campaign info.
 */
@optional
- (void)campaignWillShow:(WMCampaignInfo *)campaignInfo;

/**
 * Return a value in the completion block for SWT Action step of type “Callback”
 *
 * @param campaign The shown campaign info.
 * @param actionType the action type (ex. scroll).
 * @param args array of values from the Value field on the console (comma separated values).
 * @param completion a block to return a value for the action step
 */
@optional
- (void)campaign:(WMCampaignInfo *)campaign didPerformAction:(NSString *)actionType withArgs:(NSArray<NSString *> *)args andCompletion:(void (^)(__nullable id result))completion;

@end

@protocol WMAnalyticsDelegate <NSObject>

/**
 * Called after an analytics event was sent.
 *
 * @param type The type of the event
 * @param payload The payload json that contains the event details
 */
- (void)didSendAnalyticsEventOfType:(WMStatsEventType)type withPayload:(NSDictionary<NSString *, id> *)payload;

@end

@class WMSessionConfiguration;

@interface WMStartOptions : NSObject

@property (nonatomic, strong, readonly) NSString *key;
@property (nonatomic, strong, readonly) NSString *secret;
@property (nonatomic, strong) NSString *proxyGatewayURL;
@property (nonatomic, strong) NSString *selfHostedURL;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSArray<NSNumber *> *events;
@property (nonatomic, assign) ABBIAppType type;
@property (nonatomic, assign) WMProxyOptionMode proxyGatewayMode;
@property (nonatomic, assign) BOOL automationEnabled;
@property (nonatomic, assign) BOOL powerModeEnabled;
@property (nonatomic, assign) NSTimeInterval sessionTimeout;
@property (nonatomic, weak) id<WMCampaignInfoDelegate> campaignInfoDelegate;
@property (nonatomic, weak) id<WMAnalyticsDelegate> analyticsDelegate;

- (instancetype)initWithKey:(NSString *)key andSecret:(NSString *)secret;

@end

NS_ASSUME_NONNULL_END
