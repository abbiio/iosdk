//
//  NSMutableDictionary+WMAdditions.h
//  ABBISDK
//
//  Created by Haim Benchimol on 19/06/2018.
//  Copyright © 2018 WalkMe Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (WMAdditions)

- (void)addEntriesFromDictionaryIgnoreNull:(NSDictionary*)otherDictionary;

@end
