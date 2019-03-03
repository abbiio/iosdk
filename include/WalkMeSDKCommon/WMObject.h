//
//  WMObject.h
//  ABBISDK
//
//  Created by Haim Benchimol on 18/07/2017.
//  Copyright © 2017 Abbi Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMSerialization.h"

@interface WMObject : NSObject <WMSerializationProtocol,NSCopying,NSCoding>

- (instancetype)initWithSerializableObject:(NSDictionary*)object;
- (NSString*)asString;

+ (id)wmObjectFromValue:(id)value;

@end

@interface NSString (WMObject)

- (id)asObject:(Class)objectType;
- (id)asObject:(Class)objectType withVersion:(CGFloat)version;

@end

