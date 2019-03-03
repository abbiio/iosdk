//
//  WMJSONSerialization.h
//  WalkMe
//
//  Created by Haim Ben Chimol on 10/12/15.
//  Copyright © 2015 WalkMe. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WMSerializationProtocol <NSObject>

@required
/**
 @abstract Returns the latest supported version of the model
 @return The latest model version
 */

+ (CGFloat)version;

/**
 @abstract A key:value mapping of an object in order to support JSON serialization
 @return A kay:value mapping of the object properties
 */
- (NSDictionary*)jsonMap;

/**
 @abstract Converts an object to a native object that can be serialized by the NSJSONSerialization class.
 @return A kay:value mapping of the object properties
 */
- (NSDictionary*)serialize;

/**
 @abstract Receives a dictionary and attempt to convert it to an object
 @return The object or nil, if can't convert.
 */
- (instancetype)initWithSerializableObject:(NSDictionary*)object version:(CGFloat)version;

@optional
/**
 @abstract Receives a value and attempt to convert it to an object.
 Simple WMObject implementation just calls "initWithSerializableObject" method.
 A class may override this method if it supports creating different types of objects.
 @return The object or nil, if can't convert.
 */
+ (id)objectFromSerializableObject:(NSDictionary*)object version:(CGFloat)version;

@end

@interface WMSerialization : NSObject

/**
 @abstract Converts an object to a native object that can be serialized by the NSJSONSerialization class.
 @return A kay:value mapping of the object properties
 */
+ (id)objectToSerializableObject:(id)object;

@end

@interface NSMutableDictionary (WMSerialization)

- (instancetype)initWithSerializableDictionary:(id)object version:(CGFloat)version withClass:(Class<WMSerializationProtocol>)aClass;

@end

@interface NSMutableArray (WMSerialization)

- (instancetype)initWithSerializableArray:(id)object version:(CGFloat)version withClass:(Class<WMSerializationProtocol>)aClass;

@end

NS_ASSUME_NONNULL_END
