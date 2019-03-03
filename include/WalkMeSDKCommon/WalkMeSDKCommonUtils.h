//
//  WalkMeSDKCommonUtils.h
//  WalkMeSDKCommon
//
//  Created by Haim Ben Chimol on 21/01/2019.
//  Copyright © 2019 WalkMe. All rights reserved.
//

#ifndef WalkMeSDKCommonUtils_h
#define WalkMeSDKCommonUtils_h

#import <Foundation/Foundation.h>

// Import all public extensions here
#import <WalkMeSDKCommon/NSString+WMAdditions.h>
#import <WalkMeSDKCommon/NSDictionary+WMAdditions.h>
#import <WalkMeSDKCommon/NSMutableDictionary+WMAdditions.h>

__unused static id ObjectOrNull(id object) {
    return object ? object : [NSNull null];
}


#endif /* WalkMeSDKCommonUtils_h */
