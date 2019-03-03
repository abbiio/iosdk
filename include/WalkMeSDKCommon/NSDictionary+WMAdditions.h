//
//  NSDictionary+WMAdditions.h
//  ABBISDK
//
//  Created by Haim Benchimol on 06/02/2018.
//  Copyright © 2018 Abbi Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary<KeyType,ObjectType> (WMAdditions)

- (id)objectForCaseInsensitiveKey:(NSString*)key;

- (NSNumber *)wmNumberForKey:(NSString *)key;
- (NSNumber *)wmNumberForKey:(NSString *)key withDefault:(NSNumber *)defaultTo;

- (NSString *)wmStringForKey:(NSString *)key;
- (NSString *)wmStringForKey:(NSString *)key withDefault:(NSString *)defaultTo;

- (NSArray *)wmArrayForKey:(NSString *)key;

- (NSDictionary *)wmDictionaryForKey:(NSString *)key;
- (NSDictionary *)wmDictionaryForKey:(NSString *)key withDefault:(NSDictionary *)defaultTo;
- (id)wmObjectOfType:(Class)objectType forKey:(NSString*)key;

- (BOOL)wmBoolForKey:(NSString*)key;
- (BOOL)wmBoolForKey:(NSString *)key withDefault:(BOOL)defaultTo;

- (NSDictionary<KeyType,id>*)dictionaryForKeyPath:(NSString*)keyPath;

+ (NSDictionary*)wmDictionaryFromJSONData:(NSData*)jsonData;
+ (NSDictionary*)wmDictionaryFromJSONBase64String:(NSString*)jsonBase64String;

@end
