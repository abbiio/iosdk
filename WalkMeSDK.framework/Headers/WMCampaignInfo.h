//
//  WMCampaignInfo.h
//  ABBISDK
//
//  Created by WalkMe on 07/03/2018.
//  Copyright © 2018 Abbi Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMUserData.h"

@interface WMCampaignInfo : NSObject

@property (nonatomic,strong) NSString* campaginCta;
@property (nonatomic,strong) NSString* campaignCtaId;
@property (nonatomic,strong) NSString* campaignId;
@property (nonatomic,strong) WMUserData* userData;
@property (nonatomic,strong) NSDictionary* campaignData;


@end
