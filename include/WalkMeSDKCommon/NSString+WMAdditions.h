//
//  NSString+WMAdditions.h
//  ABBISDK
//
//  Created by Haim Benchimol on 03/04/2018.
//  Copyright © 2018 WalkMe Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (WMAdditions)

- (NSUInteger)__wm__distanceFromString:(NSString*)query;
- (NSString*)__wm__decodedBase64String;

@end
