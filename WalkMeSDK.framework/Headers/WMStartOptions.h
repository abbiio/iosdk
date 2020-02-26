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
    WMStatsEventTypeInteraction,
    WMStatsEventTypeGoal,
    WMStatsEventTypeViewTransition,
    WMStatsEventTypeMonitoring,
    WMStatsEventTypeMonitoringElement,
    WMStatsEventTypeMonitoringView,
    WMStatsEventTypeUsers,
    WMStatsEventTypeOnboardingItemCompleted
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
- (void)campaignDidDismiss:(WMCampaignInfo *)campaignInfo;

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

@interface WMStartOptions : NSObject

@property (nonatomic, strong, readonly) NSString *key;
@property (nonatomic, strong, readonly) NSString *secret;
@property (nonatomic, strong) NSString *proxyGatewayURL;
@property (nonatomic, strong) NSString *selfHostedURL;
@property (nonatomic, strong) NSArray<NSNumber *> *events;
@property (nonatomic, assign) ABBIAppType type;
@property (nonatomic, weak) id<WMCampaignInfoDelegate> campaignInfoDelegate;

- (instancetype)initWithKey:(NSString *)key andSecret:(NSString *)secret;

@end

NS_ASSUME_NONNULL_END
